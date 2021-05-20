#pragma once
#include "VehicleStorage.h"

class Interface
{
	enum NUMBERS_OF_MAIN_MENU
	{
		EXIT,
		READ_DATA,
		PRINT_STORAGE,
		FIND,
		SELL,	
		CHOOSE_MESSAGE
	};

	enum NUMERS_OF_FIND_MENU
	{
		OF_BRAND,
		OF_MAX_SPEED,
		OF_MILEAGE,
		OF_COUNT_OF_OWNERS,
		OF_CAR_BODY_TYPE,
		OF_MAX_CARRYING_CAPACITY,
		OF_TYPE
	};

	enum NUMERS_OF_READ_DATA_MENU
	{
		SELECT_TYPE,
		FROM_FILE,
		FROM_CONSOLE,
		CHOOSE
	};

public:
	void Run();
	
private:
	void PrintMainMenu() const;
	void PrintInputMenu() const;
	void PrintFindMenu() const;
	void PrintStorage() const;
	void PrintReadMenu() const;
	void PrintTutorial() const;
	std::string IndexesToString() const;

	std::string ReadFileName() const;
	void ReadData();
	void ReadDataFromFile();
	void ReadDataFromConsole();

	void IsStorageEmpty() const;
	void FindAndPrint();
	void Sell();

	VehicleStorage _storage;
	
	const char* INPUT_MESSAGE = "Enter the name of the file from which you want to read data (*.txt): ";

	const char* MAIN_MENU[7] =
	{
		". Exit",
		". Read data",
		". Print storage",
		". Find",
		". Sell",
		"Your choose: "
	};
	
	const char* FIND_MENU[7]
	{
		". Find of brand",
		". Find of max speed",
		". Find of mileage",
		". Find of count of owners",
		". Find of car body type",
		". Find of max carrying capacity",
		". Find of type"
	};

	const char* READ_DATA_MENU[4] =
	{
		"Select input type:",
		". From file",
		". From console",
		"Your choose: "
	};

	const char* SELL_MESSAGE = "Enter index which you want to sell from ";
};

