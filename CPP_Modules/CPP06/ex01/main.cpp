#include "Serializer.hpp"

int main()
{
	// Create an instance of Data and populate it with values
	Data originalData;
	originalData.name = "Alice";
	originalData.age = 28;
	originalData.height = 5.7f;

	// Print the original Data values
	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Age: " << originalData.age << std::endl;
	std::cout << "Height: " << originalData.height << std::endl;

	// Serialize the Data pointer
	unsigned long serialized = Serializer::serialize(&originalData);

	// Deserialize the uintptr_t back into a Data pointer
	Data* deserialized = Serializer::deserialize(serialized);

	// Verify that the deserialized pointer matches the original pointer
	if (deserialized == &originalData) {
		std::cout << "\nSerialization and Deserialization successful!" << std::endl;
		std::cout << "Deserialized Data:" << std::endl;
		std::cout << "Name: " << deserialized->name << std::endl;
		std::cout << "Age: " << deserialized->age << std::endl;
		std::cout << "Height: " << deserialized->height << std::endl;
	} else {
		std::cout << "\nSerialization and Deserialization failed!" << std::endl;
	}

	return 0;
}