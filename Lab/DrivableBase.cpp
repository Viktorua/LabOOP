#include "DrivableBase.h"
#include <sstream>

DrivableBase::DrivableBase(const DrivableBaseData& baseData)
	: _baseData(baseData) {}

std::string DrivableBase::GetBrand() const
{
	return _baseData.brand;
}

double DrivableBase::GetMaxSpeed() const
{
	return _baseData.maxSpead;
}

double DrivableBase::GetMileage() const
{
	return _baseData.mileage;
}

int DrivableBase::GetCountOfOwners() const
{
	return _baseData.countOfOwners;
}

std::string DrivableBase::ToString() const
{
	std::ostringstream sout;
	sout << "Brand : " << _baseData.brand << std::endl;
	sout << "Max speed : " << _baseData.maxSpead << std::endl;
	sout << "Mileage : " << _baseData.mileage << std::endl;
	sout << "Count of owners : " << _baseData.countOfOwners << std::endl;

	return sout.str();
}
