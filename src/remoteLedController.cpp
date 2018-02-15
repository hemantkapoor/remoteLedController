//============================================================================
// Name        : remoteLedController.cpp
// Author      : Hemant Kapoor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MessageManager.h"
#include "Ledmanager.h"
#include "Utility.h"


int main() {
	std::cout << "Hello World" << std::endl;

	MessageManager::instance();
	Ledmanager::instance()->addLed(GPIO::P8_7,"RED_LED");

	while(true);
	return 0;
}
