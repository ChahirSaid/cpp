/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:52:40 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 18:52:40 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace_line(std::string &line, std::string &s1, std::string &s2)
{
	std::string new_line;
	size_t pos = 0;
	size_t found = 0;

	while ((found = line.find(s1, pos))!= std::string::npos)
	{
		new_line += line.substr(pos, found - pos);
		new_line += s2;
		pos = found + s1.size();
	}
	new_line += line.substr(pos);
	return new_line;
}


int main(int ac, char **av)
{
	if (ac != 4)
		return std::cout << "invalid arguments count" << std::endl, 1;
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (filename.empty() || s1.empty())
		return std::cout << "file name and target can't be empty" << std::endl, 1;

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		return std::cout << "failed opening file" << std::endl, 1;
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
		return std::cout << "failed creating file" << std::endl, 1;

	std::string line;
	while(std::getline(infile, line))
	{
		outfile << replace_line(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}