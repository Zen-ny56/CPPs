#pragma once 

#include <string>
#include <iostream>

struct Data 
{
	std::string name;
	int age;
	float height;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
	public:
		~Serializer();
		static unsigned long serialize(Data* ptr);
		static Data* deserialize(unsigned long raw);
};
