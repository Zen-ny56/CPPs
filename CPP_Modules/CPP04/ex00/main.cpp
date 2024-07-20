#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "Test Case 8: Mix of Animal and WrongAnimal" << std::endl;
    const Animal* dog = new Dog();
    const WrongAnimal* wrongCat = new WrongCat();

    dog->makeSound(); // should print "Woof!"
    wrongCat->makeSound(); // should print "WrongAnimal sound"

    delete dog;
    delete wrongCat;
    return 0;
}

// int main() {
//     std::cout << "Test Case 7: Multiple Instances" << std::endl;
//     Dog* dog1 = new Dog();
//     Dog* dog2 = new Dog();
//     Cat* cat1 = new Cat();
//     Cat* cat2 = new Cat();

//     dog1->makeSound();
//     dog2->makeSound();
//     cat1->makeSound();
//     cat2->makeSound();

//     delete dog1;
//     delete dog2;
//     delete cat1;
//     delete cat2;
//     return 0;
// }

// int main() {
//     std::cout << "Test Case 6: Dynamic Casting" << std::endl;
//     Animal* dog = new Dog();
//     Animal* cat = new Cat();

//     Dog* realDog = dynamic_cast<Dog*>(dog);
//     Cat* realCat = dynamic_cast<Cat*>(cat);

//     if (realDog) realDog->makeSound(); // should print "Woof!"
//     if (realCat) realCat->makeSound(); // should print "Meow!"

//     delete dog;
//     delete cat;
//     return 0;
// }

// int main() {
//     std::cout << "Test Case 5: Array of Animals" << std::endl;
//     Animal* animals[4];
//     animals[0] = new Dog();
//     animals[1] = new Cat();
//     animals[2] = new Dog();
//     animals[3] = new Cat();

//     for (int i = 0; i < 4; ++i) {
//         animals[i]->makeSound();
//     }

//     for (int i = 0; i < 4; ++i) {
//         delete animals[i];
//     }

//     return 0;
// }


// int main() {
//     std::cout << "Test Case 4: WrongAnimal and WrongCat Behavior" << std::endl;
//     const WrongAnimal* wrongCat = new WrongCat();
//     wrongCat->makeSound(); // should print "WrongAnimal sound"
//     delete wrongCat;
//     return 0;
// }

// int main() {
//     std::cout << "Test Case 3: Type Checking" << std::endl;
//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();
//     std::cout << dog->getType() << std::endl; // should print "Dog"
//     std::cout << cat->getType() << std::endl; // should print "Cat"
//     delete dog;
//     delete cat;
//     return 0;
// }

// int main() {
//     std::cout << "Test Case 2: Polymorphic Behavior" << std::endl;
//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();
//     dog->makeSound(); // should print "Woof!"
//     cat->makeSound(); // should print "Meow!"
//     delete dog;
//     delete cat;
//     return 0;
// }


// int main() {
//     std::cout << "Test Case 1: Basic Construction and Destruction" << std::endl;
//     const Animal* animal = new Animal();
//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();
//     delete animal;
//     delete dog;
//     delete cat;
//     return 0;
// }