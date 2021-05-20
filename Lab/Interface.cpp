#include "Interface.h"
#include "IDrivableParser.h"
#include "IDrivable.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>

void Interface::Run() 
{
	bool flag = true;

	while (flag)
	{
		try 
		{
			int action;
			PrintMainMenu();

			std::cin >> action;

			switch (action)
			{
			case NUMBERS_OF_MAIN_MENU::EXIT:
				flag = false;
				break;
			case NUMBERS_OF_MAIN_MENU::READ_DATA:
				ReadData();
				break;
			case NUMBERS_OF_MAIN_MENU::PRINT_STORAGE:
				PrintStorage();
				break;
			case NUMBERS_OF_MAIN_MENU::FIND:
				FindAndPrint();
				break;
			case NUMBERS_OF_MAIN_MENU::SELL:
				Sell();
				break;
			default:
				break;
			}
			std::cout << std::endl;
		}
		catch (const std::exception& er)
		{
			std::cerr << er.what() << std::endl << std::endl;
		}
	}
}

void Interface::PrintMainMenu() const
{
	std::cout << NUMBERS_OF_MAIN_MENU::READ_DATA << MAIN_MENU[NUMBERS_OF_MAIN_MENU::READ_DATA] << std::endl;
	std::cout << NUMBERS_OF_MAIN_MENU::PRINT_STORAGE << MAIN_MENU[NUMBERS_OF_MAIN_MENU::PRINT_STORAGE] << std::endl;
	std::cout << NUMBERS_OF_MAIN_MENU::FIND << MAIN_MENU[NUMBERS_OF_MAIN_MENU::FIND] << std::endl;
	std::cout << NUMBERS_OF_MAIN_MENU::SELL << MAIN_MENU[NUMBERS_OF_MAIN_MENU::SELL] << std::endl;
	std::cout << NUMBERS_OF_MAIN_MENU::EXIT << MAIN_MENU[NUMBERS_OF_MAIN_MENU::EXIT] << std::endl;
	std::cout << MAIN_MENU[NUMBERS_OF_MAIN_MENU::CHOOSE_MESSAGE];
}

void Interface::PrintInputMenu() const
{
	std::cout << INPUT_MESSAGE;
}

std::string Interface::ReadFileName() const
{
	PrintInputMenu();

	std::string fileName;
	std::cin >> fileName;

	return fileName;
}

void Interface::ReadData()
{
	PrintTutorial();
	PrintReadMenu();

	int choose;
	std::cin >> choose;

	switch (choose)
	{
	case NUMERS_OF_READ_DATA_MENU::FROM_FILE:
		ReadDataFromFile();
		break;
	case NUMERS_OF_READ_DATA_MENU::FROM_CONSOLE:
		ReadDataFromConsole();
	default:
		throw ("No such so option!");
		break;
	}
}

void Interface::ReadDataFromConsole()
{
	std::string typeOfParser;
	std::getline(std::cin, typeOfParser);

	IDrivableParser* parser = IDrivableParser::CreateParser(typeOfParser);

	_storage.Add(parser->Parse(std::cin));
}


void Interface::ReadDataFromFile()
{
	std::ifstream fin(ReadFileName());
	std::string typeOfParser;

	if (!fin.is_open())
	{
		std::cout << "Can`t open the file!\n";
		return;
	}

	try
	{
		while (!fin.eof())
		{
			std::getline(fin, typeOfParser);

			IDrivableParser* parser = IDrivableParser::CreateParser(typeOfParser);

			_storage.Add(parser->Parse(fin));

			std::string freeSpace;
			std::getline(fin, freeSpace);

			delete parser;
		}

		std::cout << "Reading success!\n";
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
}
void Interface::PrintStorage() const
{
	IsStorageEmpty();

	std::cout << "\nYour storage:\n";

	for (auto i : _storage.GetIndexes())
	{
		std::cout << "=================================\n";
		std::cout << _storage[i]->ToString() << std::endl;
		std::cout << "=================================\n";
	}
}

void Interface::PrintReadMenu() const
{
	std::cout << READ_DATA_MENU[NUMERS_OF_READ_DATA_MENU::SELECT_TYPE] << std::endl;
	std::cout << NUMERS_OF_READ_DATA_MENU::FROM_FILE << READ_DATA_MENU[NUMERS_OF_READ_DATA_MENU::FROM_FILE] << std::endl;
	std::cout << NUMERS_OF_READ_DATA_MENU::FROM_CONSOLE << READ_DATA_MENU[NUMERS_OF_READ_DATA_MENU::FROM_CONSOLE] << std::endl;
	std::cout << READ_DATA_MENU[NUMERS_OF_READ_DATA_MENU::CHOOSE];
}

void Interface::PrintTutorial() const
{
	std::cout << "\nYour data must be written in the form (without \"{\" and \"}\"):\n";
	std::cout << "{Type(Car/Truck)}\n";
	std::cout << "Brand : {Name of brand}\n";
	std::cout << "MaxSpeed : {Max speed}\n";
	std::cout << "Mileage : {Mileage}\n";
	std::cout << "CarBodyType : {Car body type}/ MaxCarryingCapacity : {Max carrying capacity}\n\n";
}

std::string Interface::IndexesToString() const
{
	std::ostringstream sout;
	sout << "{ ";
	
	auto indexes = _storage.GetIndexes();

	for (int i = 0; i < indexes.size() - 1; i++)
	{
		sout << indexes[i] << ", ";
	}
	sout << indexes[indexes.size() - 1] << " }";

	return sout.str();
}


void Interface::IsStorageEmpty() const
{
	if (!_storage.Size())
	{
		throw std::logic_error("Storage is empty!");
	}
}

void Interface::PrintFindMenu() const
{
	std::cout << NUMERS_OF_FIND_MENU::OF_BRAND					<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_BRAND] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_MAX_SPEED				<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_MAX_SPEED] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_MILEAGE				<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_MILEAGE] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_COUNT_OF_OWNERS		<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_COUNT_OF_OWNERS] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_CAR_BODY_TYPE			<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_CAR_BODY_TYPE] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_MAX_CARRYING_CAPACITY  << FIND_MENU[NUMERS_OF_FIND_MENU::OF_MAX_CARRYING_CAPACITY] << std::endl;
	std::cout << NUMERS_OF_FIND_MENU::OF_TYPE					<< FIND_MENU[NUMERS_OF_FIND_MENU::OF_TYPE] << std::endl;
}

void Interface::FindAndPrint() 
{
	PrintFindMenu();

	std::cout << "Select your search type: ";

	int answer;
	std::vector<int> indexes;

	std::cin >> answer;

	switch (answer)
	{
	case NUMERS_OF_FIND_MENU::OF_BRAND:
	{	
		std::cout << "Input your brand: ";

		std::string brand;
		std::cin >> brand;

		indexes = _storage.FindByBrand(brand);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_MAX_SPEED:
	{
		std::cout << "Input your max speed: ";

		int maxSpeed;
		std::cin >> maxSpeed;

		indexes = _storage.FindBySpeed(maxSpeed);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_MILEAGE:
	{
		std::cout << "Input your mileage: ";

		int mileage;
		std::cin >> mileage;

		indexes = _storage.FindByMileage(mileage);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_COUNT_OF_OWNERS:
	{
		std::cout << "Input your count of owners: ";

		int countOfOwners;
		std::cin >> countOfOwners;

		indexes = _storage.FindByOwners(countOfOwners);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_CAR_BODY_TYPE:
	{
		std::cout << "Input your type: ";

		std::string carBodyType;
		std::cin >> carBodyType;

		indexes = _storage.FindByCarBodyType(carBodyType);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_MAX_CARRYING_CAPACITY:
	{
		std::cout << "Input your max carrying capacity: ";

		int capacity;
		std::cin >> capacity;

		indexes = _storage.FindByMaxCarruingCapacity(capacity);
	}
		break;
	case NUMERS_OF_FIND_MENU::OF_TYPE:
	{
		std::cout << "Input your type (Car/Truck): ";

		std::string type;
		std::cin >> type;

		indexes = _storage.FindByType(type);
	}
		break;
	default:
		throw std::logic_error("There is no such option!");
		break;
	}

	if (indexes.empty())
	{
		std::cout << "There are no such items in the storage\n";
	}
	else
	{
		std::cout << std::endl;
		for (int i : indexes)
		{
			std::cout << _storage[i]->ToString() << std::endl;
		}
	}
}

void Interface::Sell()
{
	IsStorageEmpty();

	std::cout << SELL_MESSAGE << IndexesToString() << ": ";
	int index;

	std::cin >> index;

	_storage.Erase(index);

	std::cout << "Selling success!\n";
}


