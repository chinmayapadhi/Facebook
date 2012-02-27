#ifndef ALBUMDIR_H
#define ALBUMDIR_H

#include <QObject>

class AlbumDirObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name);
    Q_PROPERTY(QString aid READ aid);

public:
    AlbumDirObject(const QString &name, const QString &aid, QObject *parent=0);

    QString name() const;
    QString aid() const;

private:
    QString m_name;
    QString m_aid;
};

#endif // ALBUMDIR_H
