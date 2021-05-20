#include "CarParser.h"
#include "Car.h"
#include <sstream>

IDrivable* CarParser::Parse(std::istream& stream) const
{
	DrivableBaseData baseData = ParseMainData(stream);
	std::string field;
	std::string separator;
	std::string nameOfField;
	std::string bodyType;
	std::getline(stream, field);

	std::istringstream sin(field);

	sin >> nameOfField;
	sin >> separator;

	if (separator != ":")
	{
		throw std::runtime_error("Bad data!");
	}

	if (nameOfField == "CarBodyType")
	{
		if (!(sin >> bodyType))
		{
			throw std::runtime_error("Bad data!");
		}
	}

	return new Car(baseData, bodyType);
}
