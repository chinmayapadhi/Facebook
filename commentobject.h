#ifndef COMMENTOBJECT_H
#define COMMENTOBJECT_H

#include <QObject>

class CommentObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name);
    Q_PROPERTY(QString comment READ comment);
    Q_PROPERTY(QString full_name READ full_name WRITE set_full_name);
    Q_PROPERTY(QString pic READ pic WRITE set_pic);
    Q_PROPERTY(int last READ last)

public:
    CommentObject(const QString &name, const QString &comment, const int last, QObject *parent=0);

    QString name() const;
    QString comment() const;
    QString full_name() const;
    QString pic() const;
    int last() const;
    void set_full_name(QString full_name);
    void set_pic(QString pic);

private:
    QString m_name;
    QString m_comment;
    QString m_full_name;
    QString m_pic;
    int m_last;
};

#endif // COMMENTOBJECT_H
