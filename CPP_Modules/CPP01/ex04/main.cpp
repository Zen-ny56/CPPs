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
	if (ac != 4)
	{
		std::cerr << "3 parameters allowed" << std::endl;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	if (s1.empty()){std::cerr << "Put something meaningful" << std::endl;}
	//Reading from file
	std::ifstream infile(filename);
	if (!infile.is_open()){std::cerr << "Could not open the file" << std::endl;}
	//Creating new file
	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open()){std::cerr << "Could not create the file" << std::endl;}
	//Replace
	replaceAndWrite(infile, outfile, s1, s2);
}