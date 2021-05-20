#pragma once
#include "IDrivableParser.h"
#include "DrivableBaseData.h"
#include <ios>

class DrivableBaseParser : public IDrivableParser
{
public:
	DrivableBaseData ParseMainData(std::istream& stream) const;
};

