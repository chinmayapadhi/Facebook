#include <QDebug>
#include "commentobject.h"

CommentObject::CommentObject(const QString &name, const QString &comment, const int last, QObject *parent)
    : QObject(parent), m_name(name), m_comment(comment), m_full_name(""), m_last(last)
{
}

QString CommentObject::name() const
{
    return m_name;
}

QString CommentObject::comment() const
{
    return m_comment;
}

QString CommentObject::full_name() const
{
    return m_full_name;
}

QString CommentObject::pic() const
{
    return m_pic;
}

int CommentObject::last() const
{
    return m_last;
}

void CommentObject::set_full_name(QString full_name)
{
    if (full_name.compare("") != 0)
    {
        m_full_name = full_name + ":";
    }
    else
    {
        m_full_name = "";
    }
}

void CommentObject::set_pic(QString pic)
{
    m_pic = pic;
}
