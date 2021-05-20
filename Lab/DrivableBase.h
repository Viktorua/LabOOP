#pragma once
#include "IDrivable.h"
#include "DrivableBaseData.h"

class DrivableBase : public IDrivable
{
public:

	DrivableBase(const DrivableBaseData& baseData);

	std::string GetBrand() const override;
	double GetMaxSpeed() const override;
	double GetMileage() const override; // ������
	int GetCountOfOwners() const override; // ���������� ����������

	virtual std::string ToString() const override;

private:
	struct DrivableBaseData _baseData;
};



