#include  "Cat.hpp"

Cat::Cat() :Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor has been called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Cat Copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) 
{
    if (this != &copy)
        Animal::operator=(copy);
    *brain = *copy.brain;
    std::cout << "Cat Copy assignment operator has been called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat deconstructor has been called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
    return (brain->getIdea(index));
}