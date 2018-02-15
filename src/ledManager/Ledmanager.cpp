/*
 * Ledmanager.cpp
 *
 *  Created on: 12 Feb 2018
 *      Author: hemant
 */
#include <iostream>
#include "MessageManager.h"
#include "Led.h"
#include "Ledmanager.h"
#include "Utility.h"

//Static linkage
Ledmanager* Ledmanager::m_ledManager = nullptr;

Ledmanager::Ledmanager()
{
	//Register the command
	MessageManager::instance()->registerCommand(SetLedCommand,this);
}

Ledmanager* Ledmanager::instance()
{
	if(m_ledManager == nullptr)
	{
		m_ledManager = new Ledmanager;
	}
	return m_ledManager;
}

bool Ledmanager::addLed(GPIO::PinNumbersEnum pinNumber, const std::string& ledName)
{
	//Check if pin exists
	if(m_ledPinNumberRecords.find(pinNumber) != m_ledPinNumberRecords.end())
	{
		std::cout<<"Pin Already allocated\n";
		return false;
	}
	//Now check if name is present
	if(m_ledRecords.find(ledName) != m_ledRecords.end())
	{
		std::cout<<"Led name already present "<<pinNumber;
		return false;
	}
	//Led currentLed;
	auto currentLed = new Led(pinNumber);
	m_ledRecords[ledName] = currentLed;
	m_ledPinNumberRecords.insert(pinNumber);
	return true;
}

void Ledmanager::handleCommand(std::vector<std::string>& messageVector)
{
	//The Message should be atleast 2 words
	auto messageLength = messageVector.size();
	if(messageLength < 2)
	{
		//Send a nack
		MessageManager::instance()->sendResponse("NACK 1");
		return;
	}
	auto command = messageVector[0];

	auto ledName = messageVector[1];
	//first find if the Led is present
	Led* currentLed=nullptr;
	auto ledIterator = m_ledRecords.find(ledName);
	if(ledIterator == m_ledRecords.end())
	{
		MessageManager::instance()->sendResponse("NACK 2");
		return;
	}
	currentLed = ledIterator->second;
	if(command ==  SetLedCommand)
	{
		if(messageVector[2] == "on")
		{
			currentLed->on();
			MessageManager::instance()->sendResponse("ACK");
			return;
		}
		else if(messageVector[2] == "off")
		{
			currentLed->off();
			MessageManager::instance()->sendResponse("ACK");
			return;
		}
		else
		{
			MessageManager::instance()->sendResponse("NACK 3");
			return;
		}
	}
	else
	{
		MessageManager::instance()->sendResponse("NACK 4");
		return;
	}
}

Ledmanager::~Ledmanager() {
	//Delete all the Leds if they are present
	for(auto record : m_ledRecords)
	{
		auto led = record.second;
		delete led;
	}
}

