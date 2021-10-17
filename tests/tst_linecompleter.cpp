#include <QtTest>

// add necessary includes here

// TODO add LineCompleterTest class and basic parse method
// TODO add unit test cases for parsing single lines
class LineCompleterTest : public QObject
{
Q_OBJECT

public:
    LineCompleterTest();
    ~LineCompleterTest();

private slots:
    void test_case1();

};

LineCompleterTest::LineCompleterTest()
{

}

LineCompleterTest::~LineCompleterTest()
{

}

void LineCompleterTest::test_case1()
{

}

QTEST_APPLESS_MAIN(LineCompleterTest)

#include "tst_linecompleter.moc"
