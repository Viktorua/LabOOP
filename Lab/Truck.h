#pragma once
#include "DrivableBase.h"

class Truck : public DrivableBase
{
public:
	Truck(const DrivableBaseData& baseData, int maxCarrying—apacity);

	int GetMaxCarrying—apacity();
	virtual std::string GetType() const override;
	virtual std::string ToString() const override;

private:

	int _maxCarrying—apacity;
};

