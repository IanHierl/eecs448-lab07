#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedListOfInts.h"

class TesterSuite {
private:
  int testCount;
public:
  TesterSuite();
  void runTests();
  void testAddFront();
  void testAddBack();
  void testEmpty();
  void testSize();
  void testSearch();
};
