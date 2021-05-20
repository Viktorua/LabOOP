#include "TruckParser.h"
#include "Truck.h"
#include <string>
#include <sstream>

IDrivable* TruckParser::Parse(std::istream& stream) const
{
	DrivableBaseData baseData = ParseMainData(stream);
	std::string field;
	std::string separator;
	std::string nameOfField;
	int maxCarryingCapacity;
	std::getline(stream, field);

	std::istringstream sin(field);

	sin >> nameOfField;
	sin >> separator;

	if (separator != ":")
	{
		throw std::runtime_error("Bad data!");
	}

	if (nameOfField == "MaxCarryingCapacity")
	{
		if (!(sin >> maxCarryingCapacity))
		{
			throw std::runtime_error("Bad data!");
		}
	}

	return new Truck(baseData, maxCarryingCapacity);
}
