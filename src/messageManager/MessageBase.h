/*
 * MessageBase.h
 *
 *  Created on: 11 Feb 2018
 *      Author: hemant
 */

#ifndef MESSAGEBASE_H_
#define MESSAGEBASE_H_

#include <vector>

class MessageBase {
public:
	MessageBase() = delete;
	virtual void handleCommand(std::vector<std::string>&) = 0;
	virtual ~MessageBase() = delete;
};

#endif /* MESSAGEBASE_H_ */
