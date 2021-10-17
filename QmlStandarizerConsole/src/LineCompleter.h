#ifndef LINECOMPLETER_H
#define LINECOMPLETER_H

#include <QObject>

class LineCompleter : public QObject
{
    Q_OBJECT
public:
    LineCompleter();

    QStringList completeLines(const QByteArray &data) const;
};

#endif // LINECOMPLETER_H
