/*
 * MessageManager.cpp
 *
 *  Created on: 9 Feb 2018
 *      Author: hemant
 */


#include <iostream>
#include <functional>
#include "MessageManager.h"
#include "TcpServer.h"


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


void MessageManager::parseMessage(const std::string& str)
{
	//For now just look pretty
	std::cout<<"Message Manager "<<str<<std::endl;
}
MessageManager::~MessageManager() {
	// TODO Auto-generated destructor stub
}

