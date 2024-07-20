#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain *brain;
    public:
        Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();
        void    makeSound() const;
        void    setBrainIdea(int index, const std::string &idea);
        std::string getBrainIdea(int index) const;
};