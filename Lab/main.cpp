#include "CarParser.h"
#include "Car.h"
#include <iostream>

int main()
{
	//Interface().Run();

	IDrivable* car = new Car({ "T", 151, 15, 10 }, "SEDAN");

	std::cout << car->GetType() << std::endl;
	std::cout << car->ToString() << std::endl;
	std::cout <<  dynamic_cast<Car*>(car)->GetBodyType() << std::endl;

	IDrivableParser* parser = IDrivableParser::CreateParser("Car");

	IDrivable* car1 = parser->Parse(std::cin);

}