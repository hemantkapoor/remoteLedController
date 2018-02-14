/*
 * gpio.h
 *
 *  Created on: 28 Jan 2018
 *      Author: hemant
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <map>



namespace GPIO
{

//#define PIN_NUMBERS_TABLE

	enum PinNumbersEnum
	{
		P8_0, P8_1, P8_2, P8_3, P8_4, P8_5, P8_6, P8_7, P8_8, P8_9, P8_10, P8_11, P8_12, P8_13, P8_14, P8_15, P8_16, P8_17, P8_18, P8_19, P8_20, P8_21, P8_22, P8_23, P8_24, P8_25, P8_26, P8_27, P8_28, P8_29, P8_30, P8_31, P8_32, P8_33, P8_34, P8_35, P8_36, P8_37, P8_38, P8_39, P8_40, P8_41, P8_42, P8_43, P8_44, P8_45, P8_46,
		P9_0, P9_1, P9_2, P9_3, P9_4, P9_5, P9_6, P9_7, P9_8, P9_9, P9_10, P9_11, P9_12, P9_13, P9_14, P9_15, P9_16, P9_17, P9_18, P9_19, P9_20, P9_21, P9_22, P9_23, P9_24, P9_25, P9_26, P9_27, P9_28, P9_29, P9_30, P9_31, P9_32, P9_33, P9_34, P9_35, P9_36, P9_37, P9_38, P9_39, P9_40, P9_41A, P9_41B, P9_42A, P9_42B,  P9_43, P9_44, P9_45, P9_46
	};

	//Will map the enums with the numbers that Linux understands
	//If the value is 0 then the pin cannot be used as gpio or its been reserved.
	using GpioMappingMap = std::map<PinNumbersEnum,unsigned int>;

	const GpioMappingMap gpioMapping1 =
	{
			/*TODO: Update the values with the pin*/
			{P8_1 , 0},
			{P8_2 , 0},
			{P8_3 , 38},
			{P8_4 , 39},
			{P8_5 , 34},
			{P8_6 , 35},
			{P8_7 , 66},
			{P8_8 , 67},
			{P8_9 , 69},
			{P8_10 , 68},
			{P8_11 , 45},
			{P8_12 , 44},
			{P8_13 , 23},
			{P8_14 , 26},
			{P8_15 , 47},
			{P8_16 , 46},
			{P8_17 , 27},
			{P8_18 , 65},
			{P8_19 , 22},
			{P8_20 , 63},
			{P8_21 , 62},
			{P8_22 , 37},
			{P8_23 , 36},
			{P8_24 , 33},
			{P8_25 , 32},
			{P8_26 , 61},
			{P8_27 , 86},
			{P8_28 , 88},
			{P8_29 , 87},
			{P8_30 , 89},
			{P8_31 , 10},
			{P8_32 , 11},
			{P8_33 , 9},
			{P8_34 , 81},
			{P8_35 , 8},
			{P8_36 , 80},
			{P8_37 , 78},
			{P8_38 , 79},
			{P8_39 , 76},
			{P8_40 , 77},
			{P8_41 , 74},
			{P8_42 , 75},
			{P8_43 , 72},
			{P8_44 , 73},
			{P8_45 , 70},
			{P8_46 , 71},
			{P9_1 , 0},
			{P9_2 , 0},
			{P9_3 , 0},
			{P9_4 , 0},
			{P9_5 , 0},
			{P9_6 , 0},
			{P9_7 , 0},
			{P9_8 , 0},
			{P9_9 , 0},
			{P9_10 , 0},
			{P9_11 , 30},
			{P9_12 , 60},
			{P9_13 , 31},
			{P9_14 , 50},
			{P9_15 , 48},
			{P9_16 , 51},
			{P9_17 , 5},
			{P9_18 , 4},
			{P9_19 , 13},
			{P9_20 , 12},
			{P9_21 , 3},
			{P9_22 , 2},
			{P9_23 , 49},
			{P9_24 , 15},
			{P9_25 , 117},
			{P9_26 , 14},
			{P9_27 , 115},
			{P9_28 , 113},
			{P9_29 , 111},
			{P9_30 , 112},
			{P9_31 , 110},
			{P9_32 , 0},
			{P9_33 , 0},
			{P9_34 , 0},
			{P9_35 , 0},
			{P9_36 , 0},
			{P9_37 , 0},
			{P9_38 , 0},
			{P9_39 , 0},
			{P9_40 , 0},
			{P9_41A , 20},
			{P9_41B , 116},
			{P9_42A , 7},
			{P9_42B , 114},
			{P9_43 , 0},
			{P9_44 , 0},
			{P9_45 , 0},
			{P9_46 , 0}
	};

	enum GpioDirection
	{
		in,
		out
	};
}



class gpio {
public:
	gpio();
	gpio(GPIO::PinNumbersEnum);
	//Todo: Implement below gpio methods
	bool setDirection(GPIO::GpioDirection);
	bool setValue(int val);


	//gpio control functions
	virtual ~gpio();
private:
	std::string m_gpioFullPath;
	GPIO::PinNumbersEnum m_pinEnum; //required for destructor
	//With C++11 we can do below initialisation
	bool m_valid = false;
	//gpio path
	//C++ 11 string literal
	const std::string GPIO_PATH = R"(/sys/class/gpio/)";
	const std::string GPIO_NAME = "gpio";
	const std::string gpioExportString = GPIO_PATH + "export";
	const std::string gpioUnexportString = GPIO_PATH + "unexport";
	const std::string gpioDirection = "direction";
	const std::string gpioValue = "value";
};

#endif /* GPIO_H_ */



#ifdef NEVER
	const GpioMappingMap::value_type gpioMapping[] =
	{
			/*TODO: Update the values with the pin*/
			std::make_pair(P8_1 , 0),
			std::make_pair(P8_2 , 0),
			std::make_pair(P8_3 , 38),
			std::make_pair(P8_4 , 39),
			std::make_pair(P8_5 , 34),
			std::make_pair(P8_6 , 35),
			std::make_pair(P8_7 , 66),
			std::make_pair(P8_8 , 67),
			std::make_pair(P8_9 , 69),
			std::make_pair(P8_10 , 68),
			std::make_pair(P8_11 , 45),
			std::make_pair(P8_12 , 44),
			std::make_pair(P8_13 , 23),
			std::make_pair(P8_14 , 26),
			std::make_pair(P8_15 , 47),
			std::make_pair(P8_16 , 46),
			std::make_pair(P8_17 , 27),
			std::make_pair(P8_18 , 65),
			std::make_pair(P8_19 , 22),
			std::make_pair(P8_20 , 63),
			std::make_pair(P8_21 , 62),
			std::make_pair(P8_22 , 37),
			std::make_pair(P8_23 , 36),
			std::make_pair(P8_24 , 33),
			std::make_pair(P8_25 , 32),
			std::make_pair(P8_26 , 61),
			std::make_pair(P8_27 , 86),
			std::make_pair(P8_28 , 88),
			std::make_pair(P8_29 , 87),
			std::make_pair(P8_30 , 89),
			std::make_pair(P8_31 , 10),
			std::make_pair(P8_32 , 11),
			std::make_pair(P8_33 , 9),
			std::make_pair(P8_34 , 81),
			std::make_pair(P8_35 , 8),
			std::make_pair(P8_36 , 80),
			std::make_pair(P8_37 , 78),
			std::make_pair(P8_38 , 79),
			std::make_pair(P8_39 , 76),
			std::make_pair(P8_40 , 77),
			std::make_pair(P8_41 , 74),
			std::make_pair(P8_42 , 75),
			std::make_pair(P8_43 , 72),
			std::make_pair(P8_44 , 73),
			std::make_pair(P8_45 , 70),
			std::make_pair(P8_46 , 71),
			std::make_pair(P9_1 , 0),
			std::make_pair(P9_2 , 0),
			std::make_pair(P9_3 , 0),
			std::make_pair(P9_4 , 0),
			std::make_pair(P9_5 , 0),
			std::make_pair(P9_6 , 0),
			std::make_pair(P9_7 , 0),
			std::make_pair(P9_8 , 0),
			std::make_pair(P9_9 , 0),
			std::make_pair(P9_10 , 0),
			std::make_pair(P9_11 , 30),
			std::make_pair(P9_12 , 60),
			std::make_pair(P9_13 , 31),
			std::make_pair(P9_14 , 50),
			std::make_pair(P9_15 , 48),
			std::make_pair(P9_16 , 51),
			std::make_pair(P9_17 , 5),
			std::make_pair(P9_18 , 4),
			std::make_pair(P9_19 , 13),
			std::make_pair(P9_20 , 12),
			std::make_pair(P9_21 , 3),
			std::make_pair(P9_22 , 2),
			std::make_pair(P9_23 , 49),
			std::make_pair(P9_24 , 15),
			std::make_pair(P9_25 , 117),
			std::make_pair(P9_26 , 14),
			std::make_pair(P9_27 , 115),
			std::make_pair(P9_28 , 113),
			std::make_pair(P9_29 , 111),
			std::make_pair(P9_30 , 112),
			std::make_pair(P9_31 , 110),
			std::make_pair(P9_32 , 0),
			std::make_pair(P9_33 , 0),
			std::make_pair(P9_34 , 0),
			std::make_pair(P9_35 , 0),
			std::make_pair(P9_36 , 0),
			std::make_pair(P9_37 , 0),
			std::make_pair(P9_38 , 0),
			std::make_pair(P9_39 , 0),
			std::make_pair(P9_40 , 0),
			std::make_pair(P9_41A , 20),
			std::make_pair(P9_41B , 116),
			std::make_pair(P9_42A , 7),
			std::make_pair(P9_42B , 114),
			std::make_pair(P9_43 , 0),
			std::make_pair(P9_44 , 0),
			std::make_pair(P9_45 , 0),
			std::make_pair(P9_46 , 0)
	};

#endif
