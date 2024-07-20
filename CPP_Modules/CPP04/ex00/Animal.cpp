#include "Animal.hpp"

Animal::Animal() :type("Unknown")
{
    std::cout << "Animal constructor has been called" << std::endl;
}

Animal::Animal(const Animal& copy) :type(copy.type)
{
    std::cout << "Animal Copy constructor has been called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this != &copy)
    {
        this->type = copy.getType();
    }
    std::cout << "Animal Copy assignment operator has been called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal deconstructor has been called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound has been made" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
