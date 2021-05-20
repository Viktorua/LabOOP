#include "Car.h"
#include <sstream>

Car::Car(const DrivableBaseData& baseData, const std::string& bodyType)
	: DrivableBase(baseData), _bodyType(bodyType) {}

std::string Car::GetBodyType()
{
	return _bodyType;
}

std::string Car::GetType() const
{
	return "Car";
}

std::string Car::ToString() const
{
	std::ostringstream sout;

	sout << DrivableBase::ToString();
	sout << "Car body type : " << _bodyType;

	return sout.str();
}
