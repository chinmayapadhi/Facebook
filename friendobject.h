/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef FRIENDOBJECT_H
#define FRIENDOBJECT_H

#include <QObject>

class FriendObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name) // WRITE setName)
    Q_PROPERTY(QString pic READ pic)
    Q_PROPERTY(QString uid READ uid)

public:
    FriendObject(const QString &name, const QString &pic, const QString &uid, QObject *parent=0);

    QString name() const;
    QString pic() const;
    QString uid() const;

private:
    QString m_name;
    QString m_pic;
    QString m_uid;
};

#endif // FRIENDOBJECT_H
