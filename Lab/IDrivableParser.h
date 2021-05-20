#pragma once
#include "IDrivable.h"
#include <ios>

class IDrivableParser
{
public:
	virtual IDrivable* Parse(std::istream& stream) const = 0;

	static IDrivableParser* CreateParser(const std::string& type);
};

