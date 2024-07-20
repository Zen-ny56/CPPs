#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		virtual ~Cat();
        void    makeSound() const;
};