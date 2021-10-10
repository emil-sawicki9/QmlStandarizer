#include "CodeBeautifier.h"

#include <QFile>
#include <QDebug>

#include "globals.h"

using namespace QmlStd;

CodeBeautifier::CodeBeautifier()
{

}

void CodeBeautifier::enableLogs()
{
    m_log = true;
}

void CodeBeautifier::beautifyFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite))
        qFatal("Cannot open file %s", qPrintable(filePath));

    CONDITIONAL_LOG() << BLUE("[C++]") << qPrintable(filePath);
    QVector<QByteArray> lines;

    bool passedImports = false;
    while (!file.atEnd()) {
        const QByteArray line = file.readLine();
        if ((!passedImports && !line.startsWith("import")) && !line.trimmed().isEmpty()) {
            passedImports = true;
            lines.append(parseLine(line, filePath));
        } else {
            lines.append(line);
        }
    }

    file.resize(0);
    for(int i = 0 ; i < lines.size(); i++)
        file.write(lines[i]);

    file.close();
}

QByteArray CodeBeautifier::parseLine(const QByteArray &line, const QString &filePath)
{
    return line;
}
