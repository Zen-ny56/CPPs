#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor has been called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
    std::cout << "Brain copy constructor has been called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy)
{
    if (this != &copy)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = copy.ideas[i];
            i++;
        }
    }
    std::cout << "Brain copy assignment operator has been called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain deconstructor has been called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}