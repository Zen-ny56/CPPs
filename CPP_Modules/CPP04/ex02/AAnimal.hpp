#pragma once

#include <iostream>
#include <string.h>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();
        std::string getType() const;
        virtual void makeSound() const = 0;
};
