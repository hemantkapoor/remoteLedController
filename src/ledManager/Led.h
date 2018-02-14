/*
 * Led.h
 *
 *  Created on: 28 Jan 2018
 *      Author: hemant
 */

#ifndef LED_H_
#define LED_H_

#include "gpio.h"

class Led : private gpio
{
public:
	Led();
	Led(GPIO::PinNumbersEnum);
	virtual ~Led();

	bool isValid() const {
		return m_valid;
	}

	bool on();
	bool off();


private:
	bool m_valid; //Set to true if pin selected

};

#endif /* LED_H_ */
