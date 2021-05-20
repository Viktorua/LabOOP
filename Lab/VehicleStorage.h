#pragma once
#include "IDrivable.h"
#include <map>
#include <set>
#include <vector>

class VehicleStorage
{
	using Type = std::string;
	using VectorOfElement = std::vector<std::pair<Type, IDrivable*>>;
	using MapByBrand = std::map<std::string, std::set<int>>;
	using MapBySpeed = std::map<double, std::set<int>>;
	using MapByMileage = std::map<double, std::set<int>>;
	using MapByOwners = std::map<int, std::set<int>>;
	using MapByType = std::map<std::string, std::set<int>>;
public:
	VehicleStorage() = default;

	void Add(IDrivable* obj);
	void Erase(int index);
	int Size() const;

	std::pair<Type, IDrivable*>& operator[](int index);
	std::pair<Type, IDrivable*> operator[](int index) const;

	std::vector<int> FindByType(const std::string& type);
	std::vector<int> FindByBrand(const std::string& brand);
	std::vector<int> FindBySpeed(double speed);
	std::vector<int> FindByMileage(double mileage);
	std::vector<int> FindByOwners(int owners);

private:
	std::vector<int> SetToVector(const std::set<int>& set);

	VectorOfElement _defaultVector;
	MapByBrand _indexByBrand;
	MapBySpeed _indexBySpeed;
	MapByMileage _indexByMileage;
	MapByOwners _indexByOwners;
	MapByType _indexByType;

	const std::pair<std::string, std::string> CAR_TYPE = { "class Car", "Car" };
	const std::pair<std::string, std::string> TRUCK_TYPE = { "class Truck", "Truck" };
};

