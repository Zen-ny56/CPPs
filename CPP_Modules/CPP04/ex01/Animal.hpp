#pragma once

#include <iostream>
#include <string.h>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;
};
