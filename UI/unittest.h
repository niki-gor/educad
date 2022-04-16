#ifndef UNITTEST_H
#define UNITTEST_H
#include <QtTest/QTest>

class UnitTest : public QObject
{
    Q_OBJECT
public:
    UnitTest();
    void testCanvas();
    void testContextEdit ();
    void testController ();
    void testGUIObjects ();
    void testGUIObservers();
    void testToolbar();
};

#endif // UNITTEST_H
