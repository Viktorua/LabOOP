#pragma once
#include "VehicleStorage.h"

class Interface
{
	enum NUMBERS_OF_MENU
	{
		POSITION_ZERO,
		POSITION_ONE,
		POSITION_TWO,
		POSITION_THREE,
		POSITION_FOUR,	
		POSITION_FIVE,
		POSITION_SIX
	};
public:
	void Run();

private:
	void PrintMainMenu() const;
	void PrintInputMenu() const;
	std::string ReadFileName() const;
	void ReadDataFromFile();
	void PrintStorage() const;
	void PrintTestDrive() const;
	void CheckEmpty() const;
	void PrintFindMenu() const;
	void FindAndPrint();
	void Sell();

	VehicleStorage _storage;
	
	const char* INPUT_MESSAGE = "Enter the name of the file from which you want to read data (*.txt): ";

	const char* MAIN_MENU[7] =
	{
		". Exit",
		". Read data from file",
		". Print storage",
		". Find",
		". Test drive",
		". Sell",
		"Your choose: "
	};
	
	const char* FIND_MENU[5]
	{
		". Find of brand",
		". Find of max speed",
		". Find of mileage",
		". Find of count of owners",
		". Find of type"
	};

	const char* SELL_MESSAGE = "Enter index which you want to sell (begin from 0): ";
};

