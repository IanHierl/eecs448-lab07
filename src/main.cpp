/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>

#include "LinkedListOfInts.h"

int main(int argc, char** argv)
{
	//Example of declaring a LinkedListOfInts
	LinkedListOfInts testableList;
  
  std::vector<int> output;
  output = testableList.toVector();
  std::cout << testableList.size() << "\n";
  std::cout << output.size() << "\n";

  if( testableList.isEmpty() ) {
    std::cout << "Empty list detected\n";
  } else {
    std::cout << "Non-empty list detected\n";
  }
  testableList.addFront( 4 );
  if( testableList.isEmpty() ) {
    std::cout << "Empty list detected\n";
  } else {
    std::cout << "Non-empty list detected\n";
  }
  std::cout << testableList.size() << "\n";
  testableList.removeFront();

  for( int i = 0; i < 10000; i++ )
  {
    testableList.addFront( (17646 * i + 960134) % 4096 );
  }
  if( testableList.isEmpty() ) {
    std::cout << "Empty list detected\n";
  } else {
    std::cout << "Non-empty list detected\n";
  }
  std::cout << testableList.size() << "\n";
   
  while( ! testableList.isEmpty() ) {
    if( testableList.removeFront() ) {
      std::cout << "Succesfully removed element\n";
    } else {
      std::cout << "Failed to remove element\n";
      break;
    }
  }

  std::cout << testableList.size() << "\n";
  
  //You won't do all the tests in main; that's what your Test class will be for
	//Example:
	//TestSuite myTester;
	//myTester.runTests();

	std::cout << "Running...\nAnd we're done.\nGoodbye.\n";
	
	return (0);

}

