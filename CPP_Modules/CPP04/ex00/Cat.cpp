#include "Cat.hpp"

Cat::Cat() :Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor has been called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat Copy constructor has been called" << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy) 
{
    if (this != &copy)
        Animal::operator=(copy);
    std::cout << "Cat Copy assignment operator has been called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat deconstructor has been called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}