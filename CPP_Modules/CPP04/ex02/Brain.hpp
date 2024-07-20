#pragma once

#include <iostream>
#include <string.h>

class Brain
{   private:
        std::string ideas[100];
    public:
        Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();
        std::string getIdea(int index) const;
        void    setIdea(int index, const std::string& idea);
};