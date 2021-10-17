#include "ProjectIterator.h"

#include <QDirIterator>
#include <QDebug>
#include <QHashIterator>
#include <QFutureWatcher>

#include "globals.h"

using namespace QmlStd;

ProjectIterator::ProjectIterator()
{

}

void ProjectIterator::iterate(const QDir &dir, std::function<void(const QString&)> func, const int threadCount)
{
    const QString qmlExtension = "qml";
    QVector<QString> fileList;
    QDirIterator dirIt(dir,QDirIterator::Subdirectories);

    while (dirIt.hasNext()) {
        dirIt.next();
        const QString &path = dirIt.filePath();
        QFileInfo info = QFileInfo(path);
        // For every file that isn't skipped by exceptions call `func` method.
        if (info.isFile() && info.suffix() == qmlExtension) {
            fileList.push_back(path);
        }
    }

    if (threadCount > 1) {
        QFutureWatcher<void> futureWatcher;
        // TODO fix not working QtConcurrent
//        futureWatcher.setFuture(QtConcurrent::map(fileList, func));
        futureWatcher.waitForFinished();
    } else {
        for (int i = 0 ; i < fileList.size() ; i++) {
            func(fileList[i]);
        }
    }
}
