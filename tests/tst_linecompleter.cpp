#include <QtTest>

// add necessary includes here

class LineCompleter : public QObject
{
Q_OBJECT

public:
    LineCompleter();
    ~LineCompleter();

private slots:
    void test_case1();

};

LineCompleter::LineCompleter()
{

}

LineCompleter::~LineCompleter()
{

}

void LineCompleter::test_case1()
{

}

QTEST_APPLESS_MAIN(LineCompleter)

#include "tst_linecompleter.moc"
