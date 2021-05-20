#pragma once
#include "DrivableBaseParser.h"

class TruckParser : public DrivableBaseParser
{
public:
	TruckParser() = default;

	virtual IDrivable* Parse(std::istream& stream) const override;
};