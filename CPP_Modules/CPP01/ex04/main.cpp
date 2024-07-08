/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:34:51 by naadam            #+#    #+#             */
/*   Updated: 2024/06/24 18:53:36 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAndWrite(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	outfile << content;
}

int main(int ac, char **av)
{
    // Compilation errors
	if (ac != 4)
	{
		std::cerr << "3 parameters allowed" << std::endl;
		return (1);
    }
	std::string filename = av[1];
	std::string s1 = av[2];
    std::string s2 = av[3];
    
    if (s1.empty())
	{
		std::cerr << "Put something meaningful" << std::endl;
		return 1;
    }
    // Reading from file
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
	{
		std::cerr << "Could not open the file" << std::endl;
		return 1;
    }
    // Creating new file
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
	{
		std::cerr << "Could not create the file" << std::endl;
		return 1;
    }    
    // Replace
    replaceAndWrite(infile, outfile, s1, s2);
    //Close file
    infile.close();
    outfile.close();

    return 0;
}

//Handle permissions