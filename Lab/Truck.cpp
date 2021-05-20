#include "Truck.h"
#include <sstream>
#include <iostream>

Truck::Truck(const DrivableBaseData& baseData, int maxCarrying�apacity)
 : DrivableBase(baseData), _maxCarrying�apacity(maxCarrying�apacity){
}

int Truck::GetMaxCarrying�apacity()
{
	return _maxCarrying�apacity;
}

std::string Truck::GetType() const
{
	return "Truck";
}

std::string Truck::ToString() const
{
	std::ostringstream sout;

	sout << GetType() << std::endl;
	sout << DrivableBase::ToString();
	sout << "Max carrying capacity : " << _maxCarrying�apacity;

	return sout.str();
}


