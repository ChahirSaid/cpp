/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 06:41:59 by schahir           #+#    #+#             */
/*   Updated: 2026/04/23 14:45:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data.value = 42;
	data.name = "Test Data";

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Data value: " << data.value << std::endl;
	std::cout << "Data name: " << data.name << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "\nSerialized: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized address: " << deserialized << std::endl;

	if (deserialized == &data)
		std::cout << "\nSuccess! Deserialized pointer matches original." << std::endl;
	else
		std::cout << "\nError! Pointers don't match." << std::endl;

	std::cout << "Deserialized Data value: " << deserialized->value << std::endl;
	std::cout << "Deserialized Data name: " << deserialized->name << std::endl;

	return 0;
}
