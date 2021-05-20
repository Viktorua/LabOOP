#pragma once
#include "IDrivable.h"
#include <map>
#include <set>
#include <vector>

class VehicleStorage
{
	using MapOfItem = std::map<int, IDrivable*>;
	using MapByBrand = std::map<std::string, std::set<int>>;
	using MapBySpeed = std::map<double, std::set<int>>;
	using MapByMileage = std::map<double, std::set<int>>;
	using MapByOwners = std::map<int, std::set<int>>;
	using MapByMaxCarryingCapacity = std::map<int, std::set<int>>;
	using MapByCarBodyType = std::map<std::string, std::set<int>>;
	using MapByType = std::map<std::string, std::set<int>>;
	using SetOfAllIndexes = std::set<int>;
public:
	VehicleStorage() = default;
	~VehicleStorage();

	void Add(IDrivable* obj);
	void Erase(int index);
	int Size() const;

	IDrivable* operator[](int index);
	const IDrivable* operator[](int index) const;

	std::vector<int> FindByType(const std::string& type);
	std::vector<int> FindByBrand(const std::string& brand);
	std::vector<int> FindBySpeed(double speed);
	std::vector<int> FindByMileage(double mileage);
	std::vector<int> FindByOwners(int owners);
	std::vector<int> FindByMaxCarruingCapacity(int maxCarruingCapacity);
	std::vector<int> FindByCarBodyType(const std::string& carBodyType);
	std::vector<int> GetIndexes() const;


private:
	std::vector<int> SetToVector(const std::set<int>& set) const;

	MapOfItem _storage;
	MapByBrand _indexByBrand;
	MapBySpeed _indexBySpeed;
	MapByMileage _indexByMileage;
	MapByOwners _indexByOwners;
	MapByCarBodyType _indexByCarBodyType;
	MapByMaxCarryingCapacity _indexByMaxCarryingCapacity;
	MapByType _indexByType;
	SetOfAllIndexes _indexes;

	int nextIndex = 0;

	const std::string CAR_TYPE = "Car";
	const std::string TRUCK_TYPE = "Truck";
};

