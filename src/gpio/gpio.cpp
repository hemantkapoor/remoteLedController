/*
 * gpio.cpp
 *
 *  Created on: 28 Jan 2018
 *      Author: hemant
 */

#include <iostream>
#include <map>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "gpio.h"

gpio::gpio():m_pinEnum(GPIO::P8_1)
{

}

gpio::~gpio()
{
	//We remove the gpio
	if(m_valid)
	{
		auto pinIndex = GPIO::gpioMapping1.find(m_pinEnum);
		//First check if this is a valid pin
		if(pinIndex == GPIO::gpioMapping1.end())
		{
			std::cout<<"gpio destructor cannot find pin mapping\n";
			return;
		}
		//Now lets un-export the gpio pin
		auto fileNode = open(gpioUnexportString.c_str(),O_WRONLY);
		if(fileNode == -1)
		{
			std::cout<<"Unable to open "<<gpioUnexportString<<" file \n";
			return;
		}

		//Once the file is open then we write the pin number
		auto pinNumber = pinIndex->second;
		auto count = write(fileNode,(void*)&pinNumber,sizeof(pinNumber));

		//Todo: Proper error handling
		if(count <= 0)
		{
			std::cout<<"Unable to write to "<<gpioUnexportString<<" file \n";
			return;
		}

	}
}

gpio::gpio(GPIO::PinNumbersEnum pinNumber):m_pinEnum(pinNumber)
{
	auto pinIndex = GPIO::gpioMapping1.find(pinNumber);
	//First check if this is a valid pin
	if(pinIndex != GPIO::gpioMapping1.end())
	{
		//Now check if the pin is reserved or not
		auto pinNumber = pinIndex->second;
		std::cout<<"pin Number Selected = "<<pinNumber<<std::endl;
		if(pinNumber != 0)
		{
			//We have a hit. Now populate the path
			auto gpioFullPath = GPIO_PATH + GPIO_NAME + std::to_string(pinIndex->second);
			std::cout<<"GPIO path = "<<gpioFullPath<<std::endl;
			//No lets check if the path exists or not
			//TODO
			/*if(Directory exists)*/


			//Now lets export the gpio pin
			auto fileNode = open(gpioExportString.c_str(),O_WRONLY);
			if(fileNode == -1)
			{
				std::cout<<"Unable to open "<<gpioExportString<<" file \n";
				return;
			}

			//Once the file is open then we write the pin number
			auto count = write(fileNode,(void*)&pinNumber,sizeof(pinNumber));

			//Todo: Proper error handling
			if(count <= 0)
			{
				std::cout<<"Unable to write to "<<gpioExportString<<" file \n";
				return;
			}


			//If we reach to the end then we copy the gpio path
			//The GPIO directory must have been created by now
			//Todo: Check if the directory is created.
			m_gpioFullPath = gpioFullPath;
			m_valid = false;

		}
	}
}


bool gpio::setDirection(GPIO::GpioDirection direction)
{
	//For now just return m_valid
	//Todo: Implement functionality
	return m_valid;
}
