#include "DrivableBaseParser.h"
#include <string>
#include <sstream>

DrivableBaseData DrivableBaseParser::ParseMainData(std::istream& stream) const
{
	std::string field;
	std::string separator;
	std::string nameOfField;
	DrivableBaseData baseData;
	const int COUNT_OF_MAIN_FIELD = 4;

	

	for (int i = 0; i < COUNT_OF_MAIN_FIELD; i++)
	{
		std::getline(stream, field);

		std::istringstream sin(field);

		sin >> nameOfField;
		sin >> separator;

		if (separator != ":")
		{
			throw std::runtime_error("Bad data!");
		}

		if (nameOfField == "Brand")
		{
			if (!(sin >> baseData.brand))
			{
				throw std::runtime_error("Bad data!");
			}
		}
		else if (nameOfField == "MaxSpeed")
		{
			if (!(sin >> baseData.maxSpead))
			{
				throw std::runtime_error("Bad data!");
			}
		}
		else if (nameOfField == "Mileage")
		{
			if (!(sin >> baseData.mileage))
			{
				throw std::runtime_error("Bad data!");
			}
		}
		else if (nameOfField == "CountOfOwner")
		{
			if (!(sin >> baseData.countOfOwners))
			{
				throw std::runtime_error("Bad data!");
			}
		}

		std::string endOfline;
		if (sin >> endOfline)
		{
			throw std::runtime_error("Bad data!");
		}
	}

    return baseData;
}
