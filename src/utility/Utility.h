/*
 * Utility.h
 *
 *  Created on: 11 Feb 2018
 *      Author: hemant
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <vector>
#include <string>

class Utility {
public:
	//No constructor for singleton

	//Same goes for copy constructor
	Utility(const Utility&) = delete;
	//and assignment operator
	Utility& operator=(const Utility&) = delete;

	static Utility* instance();
	virtual ~Utility();
	std::vector<std::string> parseString(std::string&);
	int convertToNumber(const std::string&);


private:
	//Private functions
	Utility(){}
	static Utility* m_utility;
};

#endif /* UTILITY_H_ */
