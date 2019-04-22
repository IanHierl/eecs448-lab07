#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedListOfInts.h"
#include "TesterSuite.h"


TesterSuite::TesterSuite() {
  testCount = 0;
}

void TesterSuite::runTests() {
  testAddFront();
  testAddBack();
  testEmpty();
  testSize();
  testSearch();
}

void TesterSuite::testAddFront() {
  std::vector<int> baseLine;
  LinkedListOfInts testList;
  for( int i = 0; i < 4096; i++ ) {
    testList.addFront( i );
    baseLine.push_back( i );
  }

  std::vector<int> toCheck;
  bool fail;
  toCheck = testList.toVector();
  std::reverse( toCheck.begin(), toCheck.end() );
  std::cout << "Test " << testCount++ << ": test order of list on [0..4095] addFront: ";
  fail = false;
  for( int i = 0; i < baseLine.size(); i++ ) {
    if( toCheck[i] != baseLine[i] ) {
      fail = true;
      std::cout << "Failed\n";
      break;
    }
  }
  if( !fail ) {
    std::cout << "Passed\n";
  }
  delete *testList;
}

void TesterSuite::testAddBack() {
  std::vector<int> baseLine;
  LinkedListOfInts testList;
  for( int i = 0; i < 4096; i++ ) {
    testList.addFront( i );
    baseLine.push_back( i );
  }

  std::vector<int> toCheck;
  toCheck = testList.toVector();
  std::cout << "Test " << testCount++ << ": test order of list on [0..4095] addBack: ";
  bool fail;
  fail = false;
  for( int i = 0; i < baseLine.size(); i++ ) {
    if( toCheck[i] != baseLine[i] ) {
      fail = true;
      std::cout << "Failed\n";
      break;
    }
  }
  if( !fail ) {
    std::cout << "Passed\n";
  }
  delete *testList;
}

void TesterSuite::testRemoves() {
  LinkedListOfInts testList;
  std::cout << "Test " << testCount++ << ": remove front on empty list: ";
  if( testList.removeFront() ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  std::cout << "Test " << testCount++ << ": remove back on empty list: ";
  if( testList.removeBack() ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  testList.addFront( 1 );
  std::cout << "Test " << testCount++ << ": remove front on singleton list [1]: ";
  if( testList.removeFront() ) {
    if( testList.size() == 0 ) {
      std::cout << "Passed\n";
    } else {
      std::cout << "Failed\n";
    }
  } else {
    std::cout << "Failed\n";
  }

  delete *testList;
  testList = new LinkedListOfInts();

  testList.addFront( 1 );
  std::cout << "Test " << testCount++ << ": remove back on singleton list [1]: ";
  if( testList.removeBack() ) {
    if( testList.size() == 0 ) {
      std::cout << "Passed\n";
    } else {
      std::cout << "Failed\n";
    }
  } else {
    std::cout << "Failed\n";
  }
  std::cout << "Test " << testCount++ << ": remove front on singleton list [1]: ";
  if( testList.removeFront() ) {
    if( testList.size() == 0 ) {
      std::cout << "Passed\n";
    } else {
      std::cout << "Failed\n";
    }
  } else {
    std::cout << "Failed\n";
  }
  delete *testList;
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
  delete *testList;
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
  delete *testList;
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

  std::cout << "Test " << testCount++ << ": search singleton list [1] for 1: ";
  if( testList.search(1) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  std::cout << "Test " << testCount++ << ": search singleton list [1] for 2: ";
  if( testList.search(2) ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  for( int i = 2; i < 11; i++ ) {
    testList.addBack( i );
  }

  std::cout << "Test " << testCount++ << ": search list [1..10] for 5: ";
  if( testList.search(5) ) {
    std::cout << "Passed\n";
  } else {
    std::cout << "Failed\n";
  }

  std::cout << "Test " << testCount++ << ": search list [1..10] for 11: ";
  if( testList.search(11) ) {
    std::cout << "Failed\n";
  } else {
    std::cout << "Passed\n";
  }

  std::cout << "Test " << testCount++ << ": search in list with multiple 5 entries for 5: ";
  testList.addFront( 5 );
  testList.addBack( 5 );
  if( testList.search(5) ) {
    std::cout << "Passed\n":
  } else {
    std::cout << "Failed\n";
  }
  delete *testList;
}
