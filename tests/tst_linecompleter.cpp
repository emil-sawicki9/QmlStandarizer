#include "tst_linecompleter.h"

#include <QtTest>

#include "LineCompleter.h"

LineCompleterTest::LineCompleterTest()
{

}

LineCompleterTest::~LineCompleterTest()
{

}

void LineCompleterTest::checkEqual(const QStringList &left, const QStringList &right)
{
    QCOMPARE(left.size(), right.size());
    for (int i = 0 ; i < left.size() ; i++) {
        QCOMPARE(left[i], right[i]);
    }
}

void LineCompleterTest::test_completeLines_data()
{
    QTest::addColumn<QByteArray>("data");
    QTest::addColumn<QStringList>("expected");

    QTest::newRow("Empty data") << QByteArray() << QStringList();
    QTest::newRow("Formatted object property lines")
        << QByteArray("visible: true\n"
                      "opacity: 0.2")
        << QStringList { "visible: true",
                         "opacity: 0.2" };
}

void LineCompleterTest::test_completeLines()
{
    QFETCH(QByteArray, data);
    QFETCH(QStringList, expected);
    LineCompleter completer;
    checkEqual(completer.completeLines(data), expected);
}

#ifndef SINGLE_MAIN
QTEST_APPLESS_MAIN(LineCompleterTest)
#endif
