#include "IDrivableParser.h"
#include "CarParser.h"
#include "TruckParser.h"

IDrivableParser* IDrivableParser::CreateParser(const std::string& type)
{
	if (type == "Car")
	{
		return new CarParser();
	}

	if (type == "Truck")
	{
		return new TruckParser();
	}

	throw std::runtime_error("Cannot create object of this type!");
}
