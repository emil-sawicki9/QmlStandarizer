#include "QmlStandarizerApplication.h"

#include <QCommandLineParser>
#include <QTimer>
#include <QThread>
#include <QDebug>

#include "globals.h"
#include "ProjectIterator.h"
#include "CodeBeautifier.h"

using namespace QmlStd;

QmlStandarizerApplication::QmlStandarizerApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
    , m_projectIterator(new ProjectIterator())
    , m_codeBeautifier(new CodeBeautifier())
{

}

QmlStandarizerApplication::~QmlStandarizerApplication()
{
    delete m_codeBeautifier;
    m_codeBeautifier = nullptr;
    delete m_projectIterator;
    m_projectIterator = nullptr;
}

int QmlStandarizerApplication::exec()
{
    return parseCommandLine();
}

int QmlStandarizerApplication::stop()
{
    QTimer::singleShot(10, this, &QCoreApplication::quit);
    return 1;
}

int QmlStandarizerApplication::parseCommandLine()
{
    QCommandLineParser cliParser;
    cliParser.setApplicationDescription(QStringLiteral("QML code beautifier"));
    cliParser.addHelpOption();

    //------------------------
    // Arguments names
    //------------------------
    const QString directoryOption = "directory";
    const QString projectDirOption = "p";
    const QString enableBeautifierOption = "b";
    const QString enableStandarizerOption = "s";
    const QString threadOption = "j";
    const QString logOption = "v";

    //------------------------
    // Arguments setup
    //------------------------
    cliParser.addPositionalArgument(directoryOption, "Path directory path.");
    cliParser.addOptions({
        {enableBeautifierOption, "Enable QML code beautifier"},
        // TODO uncommented when implemented
//        {enableStandarizerOption, "Enable QML code standarizer"},
        {threadOption, "Enable multithreading", "count"},
        {projectDirOption, "Project path.", "path"},
        {logOption, "Enable logs"}
    });


    //------------------------
    // Processing
    //------------------------
    cliParser.process(*this);

    if (cliParser.isSet(projectDirOption)) {
        // Checking project directory to obfuscate.
        const QString &dirPath = cliParser.value(projectDirOption);
        if (dirPath.isEmpty()) {
            qCritical("Directory path is mandatory!\nAdd -h option to show help.");
            return stop();
        } else {
            m_projectDir = QDir(dirPath);
            if (!m_projectDir.exists()) {
                qCritical() << QString("Project directory '%1' doesn't exist!").arg(dirPath);
                return stop();
            }
        }
    }

    // Enabling logs during obfuscation.
    if (cliParser.isSet(logOption)) {
        m_log = true;
        m_codeBeautifier->enableLogs();
    }

    if (cliParser.isSet(threadOption)) {
        const int threadCount = cliParser.value(threadOption).toInt();
        const int maxThreadCount = QThread::idealThreadCount();
        m_threadCount = (threadCount <= 0 || threadCount > maxThreadCount) ? maxThreadCount : threadCount;
        qDebug() << "Running obfuscator on " << m_threadCount << " threads";
    }

    m_enableBeautifier = cliParser.isSet(enableBeautifierOption);
    m_enableStandarizer = cliParser.isSet(enableStandarizerOption);

    if (!m_enableBeautifier && !m_enableStandarizer) {
        qWarning() << "No specific mode selected, running beautifier by default";
        m_enableBeautifier = true;
    }

    if (m_enableBeautifier) {
        beautifyCode();
    }

    if (m_enableStandarizer) {
        standarizeCode();
    }

    if (m_log) qDebug() << "";

    return 0;
}

void QmlStandarizerApplication::beautifyCode()
{
    QElapsedTimer timer;
    timer.start();

    auto lambda = [&] (const QString &filePath) { m_codeBeautifier->beautifyFile(filePath); };
    m_projectIterator->iterate(m_projectDir, lambda, m_threadCount);

    CONDITIONAL_LOG() << "";
    qDebug()<< GREEN(" Code beautifying finished in") << (static_cast<qreal>(timer.elapsed()) / 1000.0);
    CONDITIONAL_LOG() << "";
}

void QmlStandarizerApplication::standarizeCode()
{
    QElapsedTimer timer;
    timer.start();

    CONDITIONAL_LOG() << "";
    qDebug()<< GREEN(" Code standarization finished in") << (static_cast<qreal>(timer.elapsed()) / 1000.0);
    CONDITIONAL_LOG() << "";
}
