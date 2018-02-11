/*
 * MessageManager.cpp
 *
 *  Created on: 9 Feb 2018
 *      Author: hemant
 */


#include <iostream>
#include <functional>
#include "MessageBase.h"
#include "MessageManager.h"
#include "TcpServer.h"
#include "Utility.h"


//Static linkage
MessageManager* MessageManager::m_messageManager = nullptr;

MessageManager* MessageManager::instance()
{
	if(m_messageManager == nullptr)
	{
		m_messageManager = new MessageManager;
	}
	return m_messageManager;
}

MessageManager::MessageManager()
{
	m_server = std::unique_ptr<TcpServer>(new TcpServer());
	if(m_server->connect(portNumber))
	{
		using namespace std::placeholders;
		m_server->startListening(std::bind(&MessageManager::parseMessage,this,_1));
	}
}


void MessageManager::parseMessage(std::string& str)
{
	//For now just look pretty
	std::cout<<"Message Manager "<<str<<std::endl;

	std::vector<std::string> vString = Utility::instance()->parseString(str);

	if(vString.empty())
	{
		//Nothing to do
		return;
	}

	auto messageHandler = getMessageHandler(vString[0]);

	if(messageHandler == nullptr)
	{
		//Command not present... Send nack
		m_server->sendMessage("NACK\r");
		return;
	}
	//Let the message Handler do rest of the job.
	messageHandler->handleCommand(vString);
}

bool MessageManager::registerCommand(const std::string& command,MessageBase* message)
{
	//First check if the command is already register
	if(getMessageHandler(command) != nullptr)
	{
		std::cout<<"Command already present\n";
		return false;
	}
	m_commandTable[command] = message;
	std::cout<<command<<" added\n";
	return true;
}

bool MessageManager::sendResponse(const std::string& str)
{
	if(str.empty())
	{
		return false;
	}
	return m_server->sendMessage(str);
}

//Private helper methods
MessageBase* MessageManager::getMessageHandler(std::string command)
{
	//First check if the command exists
	auto findCommand = m_commandTable.find(command);
	if(findCommand == m_commandTable.end())
	{
		return nullptr;
	}
	return findCommand->second;
}


MessageManager::~MessageManager()
{
	if(m_messageManager != nullptr)
	{
		delete m_messageManager;
	}
}

