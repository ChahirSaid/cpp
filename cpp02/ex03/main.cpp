/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:28:59 by schahir           #+#    #+#             */
/*   Updated: 2025/12/10 09:36:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point p1(2.5f, 2.0f);
    Point p2(5.0f, 5.0f);
    Point p3(0.0f, 2.5f);

    std::cout << "p1 inside:  " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2 outside: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3 on edge: " << bsp(a, b, c, p3) << std::endl;

    return 0;
}