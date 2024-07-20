#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();
        void    makeSound() const;
};