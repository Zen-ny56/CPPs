#include "Dog.hpp"

Dog::Dog() :Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor has been called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog Copy constructor has been called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy) 
{
    if (this != &copy)
        Animal::operator=(copy);
    std::cout << "Dog Copy assignment operator has been called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog deconstructor has been called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}