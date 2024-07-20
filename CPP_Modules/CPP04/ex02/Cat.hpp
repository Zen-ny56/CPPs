#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();
        void    makeSound() const;
        void    setBrainIdea();
        void    setBrainIdea(int index, const std::string &idea);
        std::string getBrainIdea(int index) const;
};