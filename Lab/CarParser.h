#pragma once
#include "DrivableBaseParser.h"

class CarParser : public DrivableBaseParser
{
public:
	CarParser() = default;

	virtual IDrivable* Parse(std::istream& stream) const override;
};

