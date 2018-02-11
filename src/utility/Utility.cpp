/*
 * Utility.cpp
 *
 *  Created on: 11 Feb 2018
 *      Author: hemant
 */

#include <utility/Utility.h>
#include <sstream>
#include <iostream>
#include <iterator>

//Static linkage
Utility* Utility::m_utility = nullptr;

Utility* Utility::instance()
{
	if(m_utility == nullptr)
	{
		m_utility = new Utility;
	}
	return m_utility;
}

std::vector<std::string> Utility::parseString(std::string& str)
{
	if(str.empty())
	{
		return std::vector<std::string>();
	}
	std::stringstream ss(str);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vectorString(begin, end);
	return vectorString;
}

Utility::~Utility()
{
	if(m_utility != nullptr)
	{
		delete m_utility;
	}
}

