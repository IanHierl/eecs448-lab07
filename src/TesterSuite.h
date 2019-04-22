#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"

extern class TesterSuite {
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
