#pragma once
#include <string>

class IDrivable
{
public:
	virtual std::string GetBrand() const = 0;
	virtual double GetMaxSpeed() const = 0;
	virtual double GetMileage() const = 0; // Пробег
	virtual int GetCountOfOwners() const = 0; // Количество владельцев
	virtual std::string GetType() const = 0;
	virtual std::string ToString() const = 0;
};

