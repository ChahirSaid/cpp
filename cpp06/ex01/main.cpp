/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 06:41:59 by schahir           #+#    #+#             */
/*   Updated: 2026/04/27 13:17:39 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.name = "name";
	data.value = 25;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized:" << deserialized << std::endl;
}
