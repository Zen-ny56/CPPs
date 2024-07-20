#include "AAnimal.hpp"

AAnimal::AAnimal() :type("Unknown")
{
    std::cout << "AAnimal constructor has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy): type(copy.type)
{
    std::cout << "AAnimal Copy constructor has been called" << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
    if (this != &copy)
    {
        this->type = copy.getType();
    }
    std::cout << "AAnimal Copy assignment operator has been called" << std::endl;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal deconstructor has been called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}
