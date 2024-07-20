#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :type("Unknown")
{
    std::cout << "WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal Copy constructor has been called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    if (this != &copy)
    {
        this->type = copy.getType();
    }
    std::cout << "WrongAnimal Copy assignment operator has been called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal deconstructor has been called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound has been made" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
