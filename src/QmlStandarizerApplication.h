#ifndef QMLSTANDARIZERAPPLICATION_H
#define QMLSTANDARIZERAPPLICATION_H

#include <QCoreApplication>
#include <QDir>

namespace QmlStd {
class ProjectIterator;
class CodeBeautifier;

class QmlStandarizerApplication : public QCoreApplication
{
public:
    QmlStandarizerApplication(int &argc, char **argv);
    ~QmlStandarizerApplication();

    int exec();

private:
    int stop();
    int parseCommandLine();
    void beautifyCode();
    void standarizeCode();

    ProjectIterator *m_projectIterator = nullptr;
    CodeBeautifier *m_codeBeautifier = nullptr;

    // Project directory to obfuscate.
    QDir m_projectDir;
    int m_threadCount = 0;
    bool m_enableBeautifier = false;
    bool m_enableStandarizer = false;
    // Enable logs in ObfuscationManager.
    bool m_log = false;
};
}

#endif // QMLSTANDARIZERAPPLICATION_H
