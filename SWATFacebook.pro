#-------------------------------------------------
#
# Project created by QtCreator 2010-05-28T17:40:15
#
#-------------------------------------------------

QT       += core gui declarative network webkit xml

TARGET = SWATFacebook
TEMPLATE = app

DEFINES += QFACEBOOKCONNECT_LIBRARY

INCLUDEPATH = qfacebook_lib_inc/

SOURCES += main.cpp \
    connect.cpp \
    qfacebook_lib/fbstreamdialog.cpp \
    qfacebook_lib/fbsession.cpp \
    qfacebook_lib/fbrequest.cpp \
    qfacebook_lib/fbpermissiondialog.cpp \
    qfacebook_lib/fblogindialog.cpp \
    qfacebook_lib/fbfeeddialog.cpp \
    qfacebook_lib/fberror.cpp \
    qfacebook_lib/fbdialog.cpp \
    qfacebook_lib/fbxmlhandler.cpp \
    newsobject.cpp \
    friendobject.cpp \
    albumdirobject.cpp \
    photoobject.cpp \
    commentobject.cpp

HEADERS  += \
    connect.h \
    dataobject.h \
    qfacebook_lib_inc/fbstreamdialog.h \
    qfacebook_lib_inc/fbsession.h \
    qfacebook_lib_inc/fbrequest.h \
    qfacebook_lib_inc/fbpermissiondialog.h \
    qfacebook_lib_inc/fblogindialog.h \
    qfacebook_lib_inc/fbfeeddialog.h \
    qfacebook_lib_inc/fberror.h \
    qfacebook_lib_inc/fbdialog.h \
    qfacebook_lib_inc/fbconnectglobal.h \
    qfacebook_lib_inc/fbxmlhandler.h \
    friendobject.h \
    newsobject.h \
    albumdir.h \
    photoobject.h \
    commentobject.h

//CONFIG += mobility

symbian {
    TARGET.UID3 = 0xecc89c21
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    fb_ribbon.PNG \
    fb_search.PNG \
    fb_background_main_screen.PNG \
    menu_icons/fb_menu_profile.PNG \
    menu_icons/fb_menu_photos.PNG \
    menu_icons/fb_menu_notes.PNG \
    menu_icons/fb_menu_news.PNG \
    menu_icons/fb_menu_inbox.PNG \
    menu_icons/fb_menu_friends.PNG \
    menu_icons/fb_menu_events.PNG \
    menu_icons/fb_menu_chat.PNG \
    menu_icons/fb_menu_requests.PNG \
    fb_big.jpg \
    photo_view.qml \
    newsfeed_view.qml \
    friend_view.qml \
    images/fb_search.PNG \
    images/fb_ribbon.PNG \
    images/fb_footer.PNG \
    images/fb_big.jpg \
    images/fb_background_main_screen.PNG \
    FriendView.qml \
    Facebook.qml \
    PhotoView.qml \
    NewsfeedView.qml \
    views/NewsfeedView.qml \
    views/FriendView.qml \
    views/PhotoView.qml \
    views/TopMenu.qml \
    subviews/TopMenu.qml

RESOURCES += \
    main.qrc
