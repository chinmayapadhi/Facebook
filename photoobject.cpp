#include <QDebug>
#include "photoobject.h"

PhotoObject::PhotoObject(const QString &src_small, const QString &src, const QString &caption, QObject *parent)
    : QObject(parent), m_src_small(src_small), m_src(src), m_caption(caption)
{
}

QString PhotoObject::src_small() const
{
    return m_src_small;
}

QString PhotoObject::src() const
{
    return m_src;
}

QString PhotoObject::caption() const
{
    return m_caption;
}
