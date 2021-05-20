#include "Interface.h"
#include "IDrivableParser.h"
#include "IDrivable.h"
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

			std::cout << MAIN_MENU[NUMBERS_OF_MENU::POSITION_SIX];
			std::cin >> action;

			switch (action)
			{
			case NUMBERS_OF_MENU::POSITION_ZERO:
				flag = false;
				break;
			case NUMBERS_OF_MENU::POSITION_ONE:
				ReadDataFromFile();
				break;
			case NUMBERS_OF_MENU::POSITION_TWO:
				PrintStorage();
				break;
			case NUMBERS_OF_MENU::POSITION_THREE:
				FindAndPrint();
				break;
			case NUMBERS_OF_MENU::POSITION_FOUR:
				PrintTestDrive();
				break;
			case NUMBERS_OF_MENU::POSITION_FIVE:
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
	std::cout << NUMBERS_OF_MENU::POSITION_ONE << MAIN_MENU[NUMBERS_OF_MENU::POSITION_ONE] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_TWO << MAIN_MENU[NUMBERS_OF_MENU::POSITION_TWO] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_THREE << MAIN_MENU[NUMBERS_OF_MENU::POSITION_THREE] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_FOUR << MAIN_MENU[NUMBERS_OF_MENU::POSITION_FOUR] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_FIVE << MAIN_MENU[NUMBERS_OF_MENU::POSITION_FIVE] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_ZERO << MAIN_MENU[NUMBERS_OF_MENU::POSITION_ZERO] << std::endl;
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
	CheckEmpty();

	for (int i = 0; i < _storage.Size(); i++)
	{
		std::cout << _storage[i].first << " {\n";
		std::cout << "\t" << "Brand : " << _storage[i].second->GetBrand() << std::endl;
		std::cout << "\t" << "MaxSpeed : " << _storage[i].second->GetMaxSpeed() << std::endl;
		std::cout << "\t" << "Mileage : " << _storage[i].second->GetMileage() << std::endl;
		std::cout << "\t" << "CountOfOwner : " << _storage[i].second->GetCountOfOwners() << std::endl;
		std::cout << "}\n\n";
	}
}

void Interface::PrintTestDrive() const
{
	CheckEmpty();
	std::cout << "Please enter an index of eleme, which you what to test: ";
	int index;

	std::cin >> index;

	std::cout << _storage[index].second->TestDrive() << std::endl;
}

void Interface::CheckEmpty() const
{
	if (!_storage.Size())
	{
		throw std::logic_error("Storage is empty!");
	}
}

void Interface::PrintFindMenu() const
{
	std::cout << NUMBERS_OF_MENU::POSITION_ONE << FIND_MENU[NUMBERS_OF_MENU::POSITION_ZERO] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_TWO << FIND_MENU[NUMBERS_OF_MENU::POSITION_ONE] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_THREE << FIND_MENU[NUMBERS_OF_MENU::POSITION_TWO] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_FOUR << FIND_MENU[NUMBERS_OF_MENU::POSITION_THREE] << std::endl;
	std::cout << NUMBERS_OF_MENU::POSITION_FIVE << FIND_MENU[NUMBERS_OF_MENU::POSITION_FOUR] << std::endl;
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
	case NUMBERS_OF_MENU::POSITION_ONE:
	{	
		std::cout << "Input your brand: ";

		std::string brand;
		std::cin >> brand;

		indexes = _storage.FindByBrand(brand);
	}
		break;
	case NUMBERS_OF_MENU::POSITION_TWO:
	{
		std::cout << "Input your max speed: ";

		int maxSpeed;
		std::cin >> maxSpeed;

		indexes = _storage.FindBySpeed(maxSpeed);
	}
		break;
	case NUMBERS_OF_MENU::POSITION_THREE:
	{
		std::cout << "Input your mileage: ";

		int mileage;
		std::cin >> mileage;

		indexes = _storage.FindByMileage(mileage);
	}
		break;
	case NUMBERS_OF_MENU::POSITION_FOUR:
	{
		std::cout << "Input your count of owners: ";

		int countOfOwners;
		std::cin >> countOfOwners;

		indexes = _storage.FindByOwners(countOfOwners);
	}
		break;
	case NUMBERS_OF_MENU::POSITION_FIVE:
	{
		std::cout << "Input your type: ";

		std::string type;
		std::cin >> type;

		indexes = _storage.FindByType(type);
	}
		break;
	default:
		throw std::logic_error("Can`t find objects for this type of search\n");
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
			std::cout << _storage[i].first << " {\n";
			std::cout << "\t" << "Brand : " << _storage[i].second->GetBrand() << std::endl;
			std::cout << "\t" << "MaxSpeed : " << _storage[i].second->GetMaxSpeed() << std::endl;
			std::cout << "\t" << "Mileage : " << _storage[i].second->GetMileage() << std::endl;
			std::cout << "\t" << "CountOfOwner : " << _storage[i].second->GetCountOfOwners() << std::endl;
			std::cout << "}\n";
		}
	}
}

void Interface::Sell()
{
	std::cout << SELL_MESSAGE;
	int index;

	std::cin >> index;

	_storage.Erase(index);

	std::cout << "Selling secces!\n";
}


