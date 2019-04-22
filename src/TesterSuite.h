#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"

class TesterSuite {
private:
  int testCount;
public:
  TesterSuite();
  void runTests();
  void testEmpty();
  void testSize();
  void testSearch();
};

#endif
