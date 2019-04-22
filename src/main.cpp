/**
*	@author Ian Hierl
*	@date 	April 22nd 2019
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>

#include "LinkedListOfInts.h"
#include "TesterSuite.h"

int main(int argc, char** argv)
{
	TesterSuite myTester;
	myTester.runTests();
	return (0);
}
