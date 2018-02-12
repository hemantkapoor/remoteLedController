/*
 * Ledmanager.cpp
 *
 *  Created on: 12 Feb 2018
 *      Author: hemant
 */

#include "Ledmanager.h"
#include "Led.h"
#include <iostream>

//Static linkage
Ledmanager* Ledmanager::m_ledManager = nullptr;

Ledmanager::Ledmanager()
{
}

Ledmanager* Ledmanager::instance()
{
	if(m_ledManager == nullptr)
	{
		m_ledManager = new Ledmanager;
	}
	return m_ledManager;
}

bool Ledmanager::addLed(GPIO::PinNumbersEnum pinNumber)
{
	//If the Led is already added then return false
	if(m_ledRecords.find(pinNumber) != m_ledRecords.end())
	{
		std::cout<<"Led alread present "<<pinNumber;
		return false;
	}
	//Led currentLed;
	auto currentLed = new Led(pinNumber);
	m_ledRecords[pinNumber] = currentLed;
	return true;
}

Ledmanager::~Ledmanager() {
	//Delete all the Leds if they are present
	for(auto record : m_ledRecords)
	{
		auto led = record.second;
		delete led;
	}
}

