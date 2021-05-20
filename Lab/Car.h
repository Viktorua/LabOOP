#pragma once
#include "DrivableBase.h"

class Car : public DrivableBase
{
public:
	Car(const DrivableBaseData& baseData, const std::string& bodyType);

	std::string GetBodyType();
	virtual std::string GetType() const override;
	virtual std::string ToString() const override;
	
private:

	std::string _bodyType;
};

