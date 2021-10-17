#ifdef SINGLE_MAIN
#include <QDebug>

#include <QCoreApplication>
#include <QFile>
#include <QTest>

#include <iostream>

#include "tst_linecompleter.h"

int performUnitTest(QObject * test, int argc, char *argv[]) {
    const QString testName = test->metaObject()->className();

    int failedCount = 0;
    qDebug() << "Starting UnitTest:" << testName;

    failedCount += QTest::qExec(test, argc, argv);

    if (failedCount == 0) {
        qDebug() << testName << "passed";
    } else {
        qDebug() << failedCount << "tests failed in" << testName;
    }

    return failedCount;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QVector<QObject*> tests;
    int totalFailedTestCount = 0;

    for (QObject * test : tests) {
        totalFailedTestCount += performUnitTest(test, argc, argv);
    }

    tests << new LineCompleterTest();

    qDeleteAll(tests);
    tests.clear();

    if (totalFailedTestCount > 0) {
        qDebug() << totalFailedTestCount << "TESTS FAILED";
    } else {
        qDebug() << "ALL TESTS PASSED";
    }

    return totalFailedTestCount;
}
#endif
