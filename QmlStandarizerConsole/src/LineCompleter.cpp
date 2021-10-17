#include "LineCompleter.h"

LineCompleter::LineCompleter()
{

}

QStringList LineCompleter::completeLines(const QByteArray &data) const
{
    if (data.isEmpty()) {
        return {};
    }

    QStringList result;
    QList<QByteArray> lines = data.split('\n');


    for (const auto &line : lines) {
        result.append(line);
    }

    return result;
}
