#ifndef PROJECTITERATOR_H
#define PROJECTITERATOR_H

#include <QObject>
#include <functional>

class QDir;

namespace QmlStd
{
class ProjectIterator
{
public:
    explicit ProjectIterator();

    // Iterate every qml file
    void iterate(const QDir &dir, std::function<void(const QString&)> func, const int threadCount);
};
}

#endif // PROJECTITERATOR_H
