#include <QApplication>
#include <QtGui>
#include <QLineEdit>

#include <QDeclarativeEngine>
#include <QDeclarativeItem>
#include <QDeclarativeComponent>
#include <QDeclarativeView>
#include <QDeclarativeContext>

#include "connect.h"

QT_USE_NAMESPACE

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    qDebug() << "Started...";

    QDeclarativeEngine engine;
    QDeclarativeComponent component(&engine);

    QWidget *b = new QWidget();
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setMargin(0);

    QDeclarativeView *view = new QDeclarativeView(b);

    FBConnect fb;
    fb.ctxt = view->rootContext();

    //view->setFocusPolicy(Qt::StrongFocus);
    view->setSource(QUrl("qrc:/Facebook.qml"));
    vbox->addWidget(view);
    b->setLayout(vbox);
    b->resize(800,425);
    b->show();

    fb.start();

    return app.exec();
}

