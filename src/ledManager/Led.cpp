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
		std::cout<<"Cannot set the direction of gpio as output\n";
		return;
	}

	//If we reach till the end then it means LED was set properly
	m_valid = true;
}

bool Led::on()
{
	if(!m_valid)
	{
		std::cout<<"Led::on Incorrect Led "<<std::endl;
		return false;
	}
	if(!setValue(1))
	{
		std::cout<<"Led::on Cannot turn ON the Led"<<std::endl;
		return false;
	}
	std::cout<<"Led::on Led turned ON"<<std::endl;
	return true;
}

bool Led::off()
{
	if(!m_valid)
	{
		std::cout<<"Led::off Incorrect Led "<<std::endl;
		return false;
	}
	if(!setValue(0))
	{
		std::cout<<"Led::off Cannot turn OFF the Led"<<std::endl;
		return false;
	}
	std::cout<<"Led::on Led turned OFF"<<std::endl;
	return true;
}


Led::~Led() {
	// TODO Auto-generated destructor stub
}

