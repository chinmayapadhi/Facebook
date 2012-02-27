#include <QDebug>
#include "albumdir.h"

AlbumDirObject::AlbumDirObject(const QString &name, const QString &aid, QObject *parent)
    : QObject(parent), m_name(name), m_aid(aid)
{
}

QString AlbumDirObject::name() const
{
    return m_name;
}

QString AlbumDirObject::aid() const
{
    return m_aid;
}
