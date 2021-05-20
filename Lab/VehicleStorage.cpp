#include "VehicleStorage.h"
#include "Car.h"
#include "Truck.h"
#include <typeinfo>
#include <stdexcept>

VehicleStorage::~VehicleStorage()
{
	for (auto it : _storage)
	{
		delete it.second;
	}
}

void VehicleStorage::Add(IDrivable* obj)
{
	if (!obj)
	{
		throw std::invalid_argument("Pointer is equal null!");
	}

	int currentIndex = nextIndex++;

	_storage[currentIndex] = obj;
	_indexes.insert(currentIndex);
	_indexByType[obj->GetType()].insert(currentIndex);

	if (obj->GetType() == CAR_TYPE)
	{
		Car* currentCarItem = dynamic_cast<Car*>(obj);

		if (currentCarItem) 
		{
			_indexByCarBodyType[currentCarItem->GetBodyType()].insert(currentIndex);
		}
	
	}
	else if (obj->GetType() == TRUCK_TYPE)
	{
		Truck* currentTruckItem = dynamic_cast<Truck*>(obj);

		if (currentTruckItem)
		{
			_indexByMaxCarryingCapacity[currentTruckItem->GetMaxCarryingÑapacity()].insert(currentIndex);
		}
	}

	_indexByBrand[obj->GetBrand()].insert(currentIndex);
	_indexBySpeed[obj->GetMaxSpeed()].insert(currentIndex);
	_indexByMileage[obj->GetMileage()].insert(currentIndex);
	_indexByOwners[obj->GetCountOfOwners()].insert(currentIndex);
}

void VehicleStorage::Erase(int index)
{
	if (_storage.find(index) != _storage.end())
	{
		IDrivable* currentItem = _storage[index];
		_indexes.erase(index);
		_indexByType[currentItem->GetType()].erase(index);

		if (currentItem->GetType() == CAR_TYPE)
		{
			Car* currentCarItem = dynamic_cast<Car*>(currentItem);
			_indexByCarBodyType[currentCarItem->GetBodyType()].erase(index);
		}
		
		if (currentItem->GetType() == TRUCK_TYPE)
		{
			Truck* currentTruckItem = dynamic_cast<Truck*>(currentItem);
			_indexByMaxCarryingCapacity[currentTruckItem->GetMaxCarryingÑapacity()].erase(index);
		}

		_indexByBrand[currentItem->GetBrand()].erase(index);
		_indexBySpeed[currentItem->GetMaxSpeed()].erase(index);
		_indexByMileage[currentItem->GetMaxSpeed()].erase(index);
		_indexByOwners[currentItem->GetCountOfOwners()].insert(index);
	}

	throw std::runtime_error("No such element!");
}

int VehicleStorage::Size() const
{
	return _storage.size();
}

IDrivable* VehicleStorage::operator[](int index)
{
	auto it = _storage.find(index);

	if (it != _storage.end())
	{
		return it->second;
	}

	throw std::runtime_error("No such item!");
}

const IDrivable* VehicleStorage::operator[](int index) const
{
	auto it = _storage.find(index);

	if (it != _storage.end())
	{
		return it->second;
	}

	throw std::runtime_error("No such item!");
}

std::vector<int> VehicleStorage::FindByType(const std::string& type) 
{
	if (type == CAR_TYPE)
	{
		return SetToVector(_indexByType[CAR_TYPE]);
	}

	if (type == TRUCK_TYPE)
	{
		return SetToVector(_indexByType[TRUCK_TYPE]);
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

std::vector<int> VehicleStorage::FindByMaxCarruingCapacity(int maxCarruingCapacity)
{
	return SetToVector(_indexByMaxCarryingCapacity[maxCarruingCapacity]);
}

std::vector<int> VehicleStorage::FindByCarBodyType(const std::string& carBodyType)
{
	return SetToVector(_indexByCarBodyType[carBodyType]);
}

std::vector<int> VehicleStorage::GetIndexes() const
{
	return SetToVector(_indexes);
}

std::vector<int> VehicleStorage::SetToVector(const std::set<int>& set) const
{
	std::vector<int> vec;

	for (auto i : set)
	{
		vec.push_back(i);
	}

	return vec;
}

