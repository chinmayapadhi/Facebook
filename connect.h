#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>
#include <QDeclarativeContext>

#include "fbsession.h"
#include "fblogindialog.h"

class FBConnect : public QObject
{
    Q_OBJECT
public:
    FBConnect();
    ~FBConnect();

    Q_INVOKABLE bool getName() const;
    QDeclarativeContext *ctxt;

public slots:
    void start();
    void stop();
    void sessionDidLogin(FBUID);

    void getFriendList();
    void getNewsFeed();
    void getAlbums(QString userid);
    void getOwnAlbums();
    void getComments(QString object_id);

    void getPhotos(QString aid);
    void updateStatus(QString text);
    void sendComment(QString id, QString text);
    void test(const FBError &error);
    void update();
    void logout();

    void friendRequestDidLoad(const QVariant&);
    void newsFeedRequestDidLoad(const QVariant&);
    void albumRequestDidLoad(const QVariant&);
    void photosRequestDidLoad(const QVariant&);
    void commentRequestDidLoad(const QVariant&);

    void sessionDidLogout();
    void gotPermissions();

private:
    QString timeAsString(long long epochtime) const;
    bool m_running;
};

#endif // CONNECT_H
