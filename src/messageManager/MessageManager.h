/*
 * MessageManager.h
 *
 *  Created on: 9 Feb 2018
 *      Author: hemant
 */

#ifndef MESSAGEMANAGER_H_
#define MESSAGEMANAGER_H_

#include <memory>
#include <map>

class TcpServer;
class MessageBase;

class MessageManager {
public:
	//No constructor for singleton

	//Same goes for copy constructor
	MessageManager(const MessageManager&) = delete;
	//and assignment operator
	MessageManager& operator=(const MessageManager&) = delete;

	bool registerCommand(const std::string&,MessageBase*);
	bool sendResponse(const std::string&);

	static MessageManager* instance();
	virtual ~MessageManager();

private:
	//Private functions
	MessageManager();
	static MessageManager* m_messageManager;
	void parseMessage(std::string&);
	MessageBase* getMessageHandler(std::string command);

	//Private members
	std::unique_ptr<TcpServer> m_server;
	bool m_connectionEstablised = false;
	std::map<std::string,MessageBase*> m_commandTable;

	//Some important constants
	const int portNumber = 5000;
};

#endif /* MESSAGEMANAGER_H_ */
