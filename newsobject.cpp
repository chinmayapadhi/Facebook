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

#include <QDebug>
#include "newsobject.h"

NewsObject::NewsObject(const QString &status, const QString &actor_id, const QString &name,
                       const QString &pic, const QString &post_id, const QString &time,
                       const int &comments, QObject *parent)
    : m_status(status), m_actor_id(actor_id), m_name(name), m_pic(pic), m_post_id(post_id),
    m_time(time), m_comments(comments)
{
}

QString NewsObject::status() const
{
    return m_status;
}

QString NewsObject::actor_id() const
{
    return m_actor_id;
}

QString NewsObject::name() const
{
    return m_name;
}

QString NewsObject::time() const
{
    return m_time;
}

QString NewsObject::pic() const
{
    return m_pic;
}

QString NewsObject::post_id() const
{
    return m_post_id;
}

int NewsObject::comments() const
{
    return m_comments;
}
