#include <QApplication>
#include <QtGui>
#include <QTextList>
#include <QList>

#include "fbrequest.h"
#include "fberror.h"
#include "fbsession.h"
#include "fblogindialog.h"
#include "fbpermissiondialog.h"

#include "friendobject.h"
#include "newsobject.h"
#include "photoobject.h"
#include "commentobject.h"
#include "albumdir.h"
#include "connect.h"

#ifdef Q_WS_MAEMO_5
#include <QtMaemo5/QMaemo5InformationBox>
#endif

//
// This class is responsible for exporting all Facebook data to QML side.
//

//TODO: these should be private members instead
static QString UserId;
static FBSession* iFBSession;
static QList<QObject*> dataList;
static QList<QObject*> friendList;
static QList<QObject*> albumDirList;
static QList<QObject*> photosList;
static QList<QObject*> commentList;
static bool askpermission = false;
static QString ownPhoto;

FBConnect::FBConnect()
{
}

FBConnect::~FBConnect()
{

}

//TODO: Error handlers are missing everywhere

void FBConnect::updateStatus(QString text)
{
    qDebug() << "In updateStatus()" << text;

    FBRequest* request = FBRequest::request();
    Dictionary params;
    params["status"] = text;

 //   connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(statusUpdated(QVariant)));
    connect (request, SIGNAL(requestFailedWithFacebookError(FBError)), this, SLOT(test(FBError)));
    request->call("status.set", params);
}

void FBConnect::sendComment(QString id, QString text)
{
    FBRequest* request = FBRequest::request();
    Dictionary params;

    params["post_id"] = id;
    params["comment"] = text;

    request->call("facebook.Stream.addComment",params);
}

void FBConnect::start()
{
    qDebug() << "In start()" << endl;

    FBLoginDialog*  iLoginDialog;

    iFBSession = FBSession::sessionForApplication(
            "16a3439df02c25f10257292a7d08e72f", "0c86d88866f8177574e35d837c9e99cd", QString( /* "http://iao.fi/SWATFacebook" */ ));

    connect (iFBSession, SIGNAL(sessionDidLogin(FBUID)), this, SLOT(sessionDidLogin(FBUID)));
    connect (iFBSession, SIGNAL(sessionDidLogout()), this, SLOT(sessionDidLogout()));
    connect (iFBSession, SIGNAL(dialogDidFailWithError(FBError)), this, SLOT(test(FBError)));

    //iFBSession->logout();

    if (iFBSession->resume() == false)
    {
        qDebug() << "Facebook login dialog launched...";
        iLoginDialog = new FBLoginDialog();
        askpermission = true;
        iLoginDialog->show();
    }
    else
    {
        qDebug() << "Still logged in";
    }

    ctxt->setContextProperty("connect", this);

    //Update news feed periodically
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000 * 60 * 10);
}

void FBConnect::update()
{
    getNewsFeed();
}

void FBConnect::stop()
{
}

bool FBConnect::getName() const
{
    return 1;
}

void FBConnect::sessionDidLogin(FBUID aUid)
{
    UserId = QString::number(aUid,10);

    qDebug() << "Logged in sucessfully, your FBUID is " << UserId;

    if (askpermission == true)
    {
        FBPermissionDialog *d = new FBPermissionDialog(iFBSession);
        //connect(d, SIGNAL(dialogDidCancel()), this, SLOT(unableToGetStreamRead()));
        connect(d, SIGNAL(dialogDidSucceed()), this, SLOT(gotPermissions()));
        connect(d, SIGNAL(dialogDidFailWithError(FBError)), this, SLOT(test(FBError)));
        d->setPermissionToRequest("read_stream,publish_stream,user_photos,friends_photos,user_photo_video_tags");
        d->show();
    }
    else
    {
        getFriendList();
    }

    qDebug() << "Permission dialog lauched" << UserId;
}

void FBConnect::getFriendList()
{
    FBRequest* request = FBRequest::request();
    Dictionary params;

    QString query = "select uid,name,pic_square,status,birthday_date,timezone from user where uid in (select uid2 from friend where uid1==" +UserId+ ")";
    params["query"] = query;
    connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(friendRequestDidLoad(QVariant)));
    //connect (request, SIGNAL(requestFailedWithFacebookError(FBError)), this, SLOT(requestFailedWithFacebookError(FBError)));
    request->call("facebook.fql.query",params);
}

void FBConnect::getNewsFeed()
{
    dataList.clear();
    dataList.append(new NewsObject(QString("One moment..."), 0, QString(""), QString(""), QString(""), QString(""), 0));
    ctxt->setContextProperty("newsModel", QVariant::fromValue(dataList));

    FBRequest* request = FBRequest::request();
    Dictionary params;

    // Query to fetch news posts
    QString queryOne = "SELECT post_id, actor_id, target_id, message, permalink, created_time, likes, comments FROM stream WHERE filter_key in (SELECT filter_key FROM stream_filter WHERE uid=" + UserId + " AND type='newsfeed') AND is_hidden = 0";

    // Fetch all people that made these posts, combine them into a single FQL multiquery
    QString queryTwo = "SELECT id, name, url, pic_square FROM profile WHERE id IN (SELECT actor_id FROM #query1) OR id =" + UserId;
    QString fql = "{\"query1\":\"" + queryOne + "\",\"queryTwo\":\"" + queryTwo + "\"}";
    params["queries"] = fql;

    connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(newsFeedRequestDidLoad(QVariant)));
//  connect (request, SIGNAL(requestFailedWithFacebookError(FBError)), this, SLOT(requestFailedWithFacebookError(FBError)));
    request->call("facebook.fql.multiquery",params);
}

void FBConnect::getComments(QString object_id)
{
    qDebug() << "In FBConnect::getComments(): " << object_id << endl;

    commentList.clear();
    commentList.append(new CommentObject(QString(""), QString("One moment..."), 0));
    ctxt->setContextProperty("commentModel", QVariant::fromValue(commentList));

    FBRequest* request = FBRequest::request();
    Dictionary params;

    QString query = "SELECT fromid, text FROM comment WHERE post_id==\'" + object_id + "\'";
    QString query2 = "SELECT id, name, pic_square FROM profile WHERE id IN (SELECT fromid FROM #query1)";

    QString fql = "{\"query1\":\"" + query + "\",\"queryTwo\":\"" + query2 + "\"}";
    params["queries"] = fql;

    connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(commentRequestDidLoad(QVariant)));
    connect (request, SIGNAL(requestFailedWithFacebookError(FBError)), this, SLOT(test(FBError)));

    request->call("facebook.fql.multiquery",params);
}

void FBConnect::getOwnAlbums()
{
    getAlbums(UserId);
}

void FBConnect::getAlbums(QString uid)
{
    qDebug() << "Getting albums for: " << uid;

    albumDirList.clear();
    albumDirList.append(new AlbumDirObject(QString("One moment..."),
                                           QString("aid")));
    ctxt->setContextProperty("albumDirModel", QVariant::fromValue(albumDirList));

    FBRequest* request = FBRequest::request();
    Dictionary params;

    QString query = "SELECT aid, cover_pid, owner, name, created, modified, description, location, link, size, visible FROM album WHERE owner=" + uid ;
    params["query"] = query;
    connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(albumRequestDidLoad(QVariant)));
    request->call("facebook.fql.query",params);
}

void FBConnect::getPhotos(QString aid)
{
    qDebug() << "In FBConnect::getPhotos()" << endl;
    photosList.clear();
    ctxt->setContextProperty("photosModel", QVariant::fromValue(photosList));

    FBRequest* request = FBRequest::request();
    Dictionary params;

    QString query = "SELECT src,src_big, caption FROM photo WHERE aid=\"" + aid + "\" ORDER BY created DESC LIMIT 1,100";
    params["query"] = query;
    connect (request, SIGNAL(requestDidLoad(QVariant)), this, SLOT(photosRequestDidLoad(QVariant)));
    request->call("facebook.fql.query",params);
}

void FBConnect::gotPermissions()
{
    qDebug() << "Got permissions";
    getFriendList();
}

void FBConnect::sessionDidLogout()
{
}

void FBConnect::logout()
{
    iFBSession->logout();
    exit(0);
}

void FBConnect::friendRequestDidLoad(const QVariant& aContainer)
{
    QVariantList list;

    qDebug() << "In FBConnect::friendRequestDidLoad()" << endl;

    list = aContainer.toList();

    for (int i = 0 ; i < list.count(); i ++)
    {
        QVariantHash dictionary = list.at(i).toHash();
        QHashIterator<QString, QVariant> iterator(dictionary);

        //qDebug() << "Pushing: " << dictionary.value("pic_small").toString() << endl;

        friendList.append(new FriendObject(dictionary.value("name").toString(),
                                           dictionary.value("pic_square").toString(),
                                           dictionary.value("uid").toString())
                          );
    }

    sender()->deleteLater();
    ctxt->setContextProperty("friendModel", QVariant::fromValue(friendList));

    getNewsFeed();
}

void FBConnect::newsFeedRequestDidLoad(const QVariant& container)
{
    dataList.clear();
    QString name, pic;

    if (container.type() == QVariant::List) {
        QVariantList list = container.toList();

        // Item #0 will be our result set on news items
        foreach (const QVariant &newsFeedPostHash, list.at(0).toHash().begin().value().toList()) {
            QHash<QString, QVariant> newsFeedPostData = newsFeedPostHash.toHash();

           foreach (const QVariant &newsFeedUserHash, list.at(1).toHash().begin().value().toList()) {
               QHash<QString, QVariant> newsFeedUserData = newsFeedUserHash.toHash();

               //TODO: slow!!

               if (newsFeedUserData["id"].toString().compare(newsFeedPostData["actor_id"].toString()) == 0)
               {
                   name = newsFeedUserData["name"].toString();
                   pic = newsFeedUserData["pic_square"].toString();
               }

               if (newsFeedUserData["id"].toString().compare(UserId) == 0)
               {
                   ownPhoto = newsFeedUserData["pic_square"].toString();
               }
           }

           if (newsFeedPostData["message"].toString().compare("") != 0)
           {
               dataList.append(new NewsObject(newsFeedPostData["message"].toString(),
                                              newsFeedPostData["actor_id"].toString(),
                                              name, pic,
                                              newsFeedPostData["post_id"].toString(),
                                              timeAsString(newsFeedPostData["created_time"].toLongLong()),
                                              newsFeedPostData["comments"].toHash()["count"].toInt()));
           }
       }
    }

    sender()->deleteLater();
    ctxt->setContextProperty("newsModel", QVariant::fromValue(dataList));
}

void FBConnect::albumRequestDidLoad(const QVariant& aContainer)
{
    QVariantList list;
    albumDirList.clear();
    bool albums = false;

    qDebug() << "In FBConnect::albumRequestDidLoad()" << endl;

    list = aContainer.toList();

    for (int i = 0 ; i < list.count(); i ++)
    {
        albums = true;
        QVariantHash dictionary = list.at(i).toHash();
        QHashIterator<QString, QVariant> iterator(dictionary);

        //qDebug() << "Pushing: " << dictionary.value("name").toString() << endl;

        albumDirList.append(new AlbumDirObject(dictionary.value("name").toString(),
                                               dictionary.value("aid").toString()));
    }

    if (!albums)
    {
        albumDirList.append(new AlbumDirObject(QString("No albums"),
                                               QString("")));
    }

    sender()->deleteLater();
    ctxt->setContextProperty("albumDirModel", QVariant::fromValue(albumDirList));
}

void FBConnect::commentRequestDidLoad(const QVariant& aContainer)
{
    qDebug() << "In FBConnect::commentRequestDidLoad()" << endl;
    commentList.clear();
    bool comments = false;

    if (aContainer.type() == QVariant::List) {
        QVariantList list = aContainer.toList();

        qDebug() << "inside";

        // comments
        foreach (const QVariant &newsFeedPostHash, list.at(0).toHash().begin().value().toList()) {
            comments = true;

            QHash<QString, QVariant> newsFeedPostData = newsFeedPostHash.toHash();

            qDebug() << newsFeedPostData["fromid"].toString() << ": " << newsFeedPostData["text"].toString();

            commentList.append(new CommentObject(newsFeedPostData["fromid"].toString(),
                                                 newsFeedPostData["text"].toString(),
                                                 0)
                               );
        }

        // who made them?
        foreach (const QVariant &newsFeedUserHash, list.at(1).toHash().begin().value().toList()) {
            QHash<QString, QVariant> newsFeedUserData = newsFeedUserHash.toHash();

            foreach (QObject *mycomment, commentList)
            {
                if (((CommentObject*)mycomment)->name().compare(newsFeedUserData["id"].toString()) == 0)
                {
                    // qDebug() << "adding name and pic";
                    ((CommentObject*)mycomment)->set_full_name(newsFeedUserData["name"].toString());
                    ((CommentObject*)mycomment)->set_pic(newsFeedUserData["pic_square"].toString());
                }
            }

            //qDebug() << newsFeedUserData["id"].toString() << ": " << newsFeedUserData["name"].toString() <<
            //        ", " << newsFeedUserData["pic_square"].toString();
        }
    }

    //A special entry for indicating the end of the list, QML inserts comment box here
    CommentObject *last = new CommentObject(QString(""), QString(""), 1);
    last->set_pic(ownPhoto);

    commentList.append(last);

    sender()->deleteLater();
    ctxt->setContextProperty("commentModel", QVariant::fromValue(commentList));
}

void FBConnect::photosRequestDidLoad(const QVariant& aContainer)
{
    QVariantList list;

    //qDebug() << "In FBConnect::photosRequestDidLoad()" << endl;

    list = aContainer.toList();

    for (int i = 0 ; i < list.count(); i ++)
    {
        QVariantHash dictionary = list.at(i).toHash();
        QHashIterator<QString, QVariant> iterator(dictionary);

        //qDebug() << "Pushing: " << dictionary.value("name").toString() << "caption: " << dictionary.value("caption").toString();

        photosList.append(new PhotoObject(dictionary.value("src").toString(),
                                          dictionary.value("src_big").toString(),
                                          dictionary.value("caption").toString())
                          );
    }

    sender()->deleteLater();
    ctxt->setContextProperty("photosModel", QVariant::fromValue(photosList));
}

void FBConnect::test(const FBError &error)
{
    qDebug() << "error:" << error.code() << " - " << error.description();
}

// This function is borrowed and adapted from Facebrick application
QString FBConnect::timeAsString(long long epochtime) const
{
    QDateTime dateTime = QDateTime::fromTime_t(epochtime);
    QDateTime now = QDateTime::currentDateTime();

    int seconds = dateTime.secsTo(now);
    int minutes = seconds / 60;
    int hours = seconds / (60 * 60);
    int days = dateTime.daysTo(now);

    minutes -= hours * 60;

    // make the times a little fuzzy so it's 'easier' to read
    if (hours > 0 && minutes < 5)
        minutes = 0;
    else if (minutes > 55) {
        minutes = 0;
        hours += 1;
    }

    if (minutes && !hours) {
        return tr("%1m ago").arg(minutes);
    } else if (hours < 6 && minutes > 0) {
        return tr("%1h %2m ago").arg(hours).arg(minutes);
    } else if (hours < 6 && minutes == 0) {
        return tr("%1h ago").arg(hours);
    } else if (days < 8) { // See if it's in the past week
        switch (days) {
        case 0:
            return tr("Today");
            break;
        case 1:
            return tr("Yesterday");
            break;
        default:
            return dateTime.date().toString("dddd");
            break;
        }
    } else {
        return dateTime.date().toString(Qt::SystemLocaleShortDate);
    }

    return QLatin1String("I have no idea how long ago :(");
}
