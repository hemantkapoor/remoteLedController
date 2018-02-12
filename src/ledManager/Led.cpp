/*
 * Led.cpp
 *
 *  Created on: 28 Jan 2018
 *      Author: hemant
 */

#include "Led.h"
#include <iostream>

Led::Led():m_valid(false) {
	// TODO Auto-generated constructor stub

}

Led::Led(GPIO::PinNumbersEnum pinNumber):gpio(pinNumber),m_valid(false)
{
	//Set the direction of pin to be output
	if(!setDirection(GPIO::out))
	{
		std::cout<<"Cannot set the direction of gpio as output";
		return;
	}

	//If we reach till the end then it means LED was set properly
	m_valid = true;
}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

