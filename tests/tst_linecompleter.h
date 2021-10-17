#ifndef TST_LINECOMPLETER_H
#define TST_LINECOMPLETER_H

#include <QObject>

class LineCompleterTest : public QObject
{
Q_OBJECT
public:
    LineCompleterTest();
    ~LineCompleterTest();

private:
    void checkEqual(const QStringList &left, const QStringList &right);

private slots:
    void test_completeLines_data();
    void test_completeLines();
};

#endif // TST_LINECOMPLETER_H
