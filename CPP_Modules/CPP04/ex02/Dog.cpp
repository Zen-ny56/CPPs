#include  "Dog.hpp"

Dog::Dog() :AAnimal()
{
    this->type = "Dog";
    std::cout << "Dog constructor has been called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Dog Copy constructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) 
{
    if (this != &copy)
        AAnimal::operator=(copy);
    *brain = *copy.brain;
    std::cout << "Dog Copy assignment operator has been called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog deconstructor has been called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
    return (brain->getIdea(index));
}