#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include <QObject>

class PhotoObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString src_small READ src_small);
    Q_PROPERTY(QString src READ src);
    Q_PROPERTY(QString caption READ caption);

public:
    PhotoObject(const QString &src_small, const QString &src, const QString &caption, QObject *parent=0);

    QString src_small() const;
    QString src() const;
    QString caption() const;

private:
    QString m_src;
    QString m_src_small;
    QString m_caption;
};

#endif // PHOTOOBJECT_H
