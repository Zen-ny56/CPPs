#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat Copy constructor has been called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) 
{
    if (this != &copy)
        WrongAnimal::operator=(copy);
    std::cout << "WrongCat Copy assignment operator has been called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat deconstructor has been called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}