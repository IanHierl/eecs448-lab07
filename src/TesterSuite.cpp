#include <iostream>
#include "LinkedListOfInts.h"
#include "TesterSuite.h"


TesterSuite::TesterSuite() {
  testCount = 0;
}

void TesterSuite::runTests() {
  testEmpty();
  testSize();
  testSearch();
}
/** Tests isEmpty on empty list, singleton list, small and large list
*   @pre None
*   @post prints test results to STIO
*   @return none
*/
void TesterSuite::testEmpty() {
  std::cout << "Begin isEmpty Tests\n";
  LinkedListOfInts testList;
  std::cout << "Test " << testCount++ << ": isEmpty returns true on empty list: ";
  if( testList.isEmpty() ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }
  std::cout << "Test " << testCount++ << ": isEmpty returns false on singleton list: ";
  testList.addFront( 1 );
  if( testList.isEmpty() ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  for( int i = 0; i < 9; i++ ) {
    testList.addFront( i );
  }

  std::cout << "Test " << testCount++ << ": isEmpty returns false on 10 element list: ";
  if( testList.isEmpty() ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  for( int i = 0; i < 990; i++ ) {
    testList.addFront( i );
  }

  std::cout << "Test " << testCount++ << ": isEmpty returns false on 1000 element list: ";
  if( testList.isEmpty() ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }
}

void TesterSuite::testSize() {
  std::cout << "Begin size Tests\n";
  LinkedListOfInts testList;
  std::cout << "Test " << testCount ++ << ": new list starts at size 0: ";
  if( testList.size() == 0 ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  for( int i = 0; i < 100; i++ ) {
    testList.addFront( i );
  }

  std::cout << "Test " << testCount++ << ": list with 100 elements added to front: ";
  if( testList.size() == 100 ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  for( int i = 0; i < 100; i++ ) {
    testList.addBack( i );
  }

  std::cout << "Test " << testCount++ << ": list with 100 elements added to back: ";
  if( testList.size() == 200 ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }
}

void TesterSuite::testSearch() {
  std::cout << "Begin search Tests\n";

  LinkedListOfInts testList;
  std::cout << "Test " << testCount++ << ": search on empty list: ";
  if( testList.search(1) ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  testList.addFront(1);

  std::cout << "Test " << testCount++ << ":search singleton list [1] for 1: ";
  if( testList.search(1) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  std::cout << "Test " << testCount++ << ":search singleton list [1] for 2: ";
  if( testList.search(2) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  for( int i = 2; i < 11; i++ ) {
    testList.addBack( i );
  }

  std::cout << "Test " << testCount++ << ":search list [1..10] for 5: ";
  if( testList.search(5) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  std::cout << "Test " << testCount++ << ":search list [1..10] for 11: ";
  if( testList.search(11) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }
}
