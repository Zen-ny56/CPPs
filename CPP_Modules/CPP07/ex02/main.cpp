#include "Array.hpp"
#include <iostream>

int main() {
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

    // Test parameterized constructor
    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;

    // Access and modify elements
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;  // Assign values to the array
    }

    // Print elements
    std::cout << "intArray elements: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copiedArray(intArray);
    std::cout << "Copied array elements: ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    // Test modifying the copied array doesn't affect the original
    copiedArray[0] = 100;
    std::cout << "After modifying copiedArray[0]:\n";
    std::cout << "intArray[0]: " << intArray[0] << std::endl;
    std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array elements: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    // Test out-of-bounds exception
    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;  // Should print "Index out of bounds"
    }

    return 0;
}