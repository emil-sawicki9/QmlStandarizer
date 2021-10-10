#ifndef CODEBEAUTIFIER_H
#define CODEBEAUTIFIER_H

#include <QString>

namespace QmlStd {
class CodeBeautifier
{
public:
    CodeBeautifier();

    void enableLogs();

    void beautifyFile(const QString &filePath);

private:
    QByteArray parseLine(const QByteArray &line, const QString &filePath);

    bool m_log = false;
};
}

#endif // CODEBEAUTIFIER_H
