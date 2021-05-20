#include "VehicleStorage.h"
#include "Car.h"
#include <typeinfo>
#include <stdexcept>

void VehicleStorage::Add(IDrivable* obj)
{

	if (typeid(*obj).name() == CAR_TYPE.first)
	{
		_defaultVector.push_back(std::make_pair(CAR_TYPE.second, obj));
		_indexByType[CAR_TYPE.second].insert(_defaultVector.size() - 1);
	}
	else if (typeid(*obj).name() == TRUCK_TYPE.first)
	{
		_defaultVector.push_back(std::make_pair(TRUCK_TYPE.second, obj));
		_indexByType[TRUCK_TYPE.second].insert(_defaultVector.size() - 1);
	}

	dynamic_cast<Car*>(_defaultVector[0].second)->f();
	_indexByBrand[_defaultVector[_defaultVector.size() - 1].second->GetBrand()].insert(_defaultVector.size() - 1);
	_indexBySpeed[_defaultVector[_defaultVector.size() - 1].second->GetMaxSpeed()].insert(_defaultVector.size() - 1);
	_indexByMileage[_defaultVector[_defaultVector.size() - 1].second->GetMileage()].insert(_defaultVector.size() - 1);
	_indexByOwners[_defaultVector[_defaultVector.size() - 1].second->GetCountOfOwners()].insert(_defaultVector.size() - 1);	
}

void VehicleStorage::Erase(int index)
{
	if (0 <= index && index < _defaultVector.size())
	{
		auto it = _defaultVector.begin();
		for (int i = 0; i < index; i++, it++);

		_indexByBrand[_defaultVector[index].second->GetBrand()].erase(index);
		_indexBySpeed[_defaultVector[index].second->GetMaxSpeed()].erase(index);
		_indexByMileage[_defaultVector[index].second->GetMileage()].erase(index);
		_indexByOwners[_defaultVector[index].second->GetCountOfOwners()].erase(index);
		_defaultVector.erase(it);
		return;
	}

	throw std::out_of_range("No such element!");
}

int VehicleStorage::Size() const
{
	return _defaultVector.size();
}

std::pair<VehicleStorage::Type, IDrivable*>& VehicleStorage::operator[](int index)
{
	if (index < 0 || index >= _defaultVector.size())
	{
		throw std::out_of_range("Out of range of container!");
	}

	return _defaultVector[index];
}

std::pair<VehicleStorage::Type, IDrivable*> VehicleStorage::operator[](int index) const
{
	if (index < 0 || index >= _defaultVector.size())
	{
		throw std::out_of_range("Out of range of container!");
	}

	return _defaultVector[index];
}

std::vector<int> VehicleStorage::FindByType(const std::string& type) 
{
	if (type == CAR_TYPE.second)
	{
		return SetToVector(_indexByType[CAR_TYPE.second]);
	}

	if (type == TRUCK_TYPE.second)
	{
		return SetToVector(_indexByType[TRUCK_TYPE.second]);
	}

	return std::vector<int>();
}

std::vector<int> VehicleStorage::FindByBrand(const std::string& brand)
{
	return SetToVector(_indexByBrand[brand]);
}

std::vector<int> VehicleStorage::FindBySpeed(double speed)
{
	return SetToVector(_indexBySpeed[speed]);
}

std::vector<int> VehicleStorage::FindByMileage(double mileage)
{
	return SetToVector(_indexByMileage[mileage]);
}

std::vector<int> VehicleStorage::FindByOwners(int owners)
{
	return SetToVector(_indexByOwners[owners]);
}

std::vector<int> VehicleStorage::SetToVector(const std::set<int>& set)
{
	std::vector<int> vec;

	for (auto i : set)
	{
		vec.push_back(i);
	}

	return vec;
}

