#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    Dog originalDog;
    originalDog.setBrainIdea(0, "Chase the cat");

    Dog copiedDog = originalDog; // Using copy constructor
    // std::cout << "Original Dog's Idea: " << originalDog.getBrainIdea(0) << std::endl;
    // std::cout << "Copied Dog's Idea: " << copiedDog.getBrainIdea(0) << std::endl;

    // copiedDog.setBrainIdea(0, "Sleep");
    // std::cout << "After changing copied dog:" << std::endl;
    // std::cout << "Original Dog's Idea: " << originalDog.getBrainIdea(0) << std::endl;
    // std::cout << "Copied Dog's Idea: " << copiedDog.getBrainIdea(0) << std::endl;

    // Cat originalCat;
    // originalCat.setBrainIdea(0, "Climb the tree");

    // Cat copiedCat = originalCat; // Using copy constructor
    // std::cout << "Original Cat's Idea: " << originalCat.getBrainIdea(0) << std::endl;
    // std::cout << "Copied Cat's Idea: " << copiedCat.getBrainIdea(0) << std::endl;

    // copiedCat.setBrainIdea(0, "Nap");
    // std::cout << "After changing copied cat:" << std::endl;
    // std::cout << "Original Cat's Idea: " << originalCat.getBrainIdea(0) << std::endl;
    // std::cout << "Copied Cat's Idea: " << copiedCat.getBrainIdea(0) << std::endl;

    return 0;
}