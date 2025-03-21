#pragma once

#include <iostream>
#include <string.h>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal();
        std::string getType() const;
        virtual void makeSound() const;
};
