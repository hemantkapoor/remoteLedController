//============================================================================
// Name        : remoteLedController.cpp
// Author      : Hemant Kapoor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MessageManager.h"
#include "Utility.h"


int main() {
	std::cout << "Hello World" << std::endl;

	MessageManager::instance();

	while(true);
	return 0;
}
