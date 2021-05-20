#include "Truck.h"
#include <sstream>
#include <iostream>

Truck::Truck(const DrivableBaseData& baseData, int maxCarryingÑapacity)
 : DrivableBase(baseData), _maxCarryingÑapacity(maxCarryingÑapacity){
}

int Truck::GetMaxCarryingÑapacity()
{
	return _maxCarryingÑapacity;
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
	sout << "Max carrying capacity : " << _maxCarryingÑapacity;

	return sout.str();
}


