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

#ifndef NEWSOBJECT_H
#define NEWSOBJECT_H

#include <QObject>

class NewsObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ status);
    Q_PROPERTY(QString actor_id READ actor_id);
    Q_PROPERTY(QString name READ name);
    Q_PROPERTY(QString pic READ pic);
    Q_PROPERTY(QString post_id READ post_id);
    Q_PROPERTY(QString time READ time);
    Q_PROPERTY(int comments READ comments);

public:
    NewsObject(const QString &status, const QString &actor_id, const QString &name,
               const QString &pic, const QString &post_id, const QString &time,
               const int &comments, QObject *parent=0);

    QString status() const;
    QString name() const;
    QString pic() const;
    QString actor_id() const;
    QString post_id() const;
    QString time() const;
    int comments() const;

private:
    QString m_status;
    QString m_name;
    QString m_pic;
    QString m_actor_id;
    QString m_post_id;
    QString m_time;
    int m_comments;
};

#endif // NEWSOBJECT_H
