/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:30 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

// int main(void)
// {
// 	Fixed		a;
// 	Fixed const	b(Fixed(5.05f) * Fixed(2));
//
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return 0;
// }

// example for when fixpoint nbr is better
// #include <iomanip>  // for std::setprecision
// int main(void)
// {
// 	float price = 0.1f;   // €0.10
// 	float total = 0.0f;
//
// 	for (int i = 0; i < 10; ++i)
// 		total += price;
//
// 	std::cout << std::fixed << std::setprecision(10);
// 	std::cout << "Total: " << total << std::endl;
// 	std::cout << "Is total == 1.0? " << (total == 1.0f ? "Yes" : "No") << std::endl;
//
// // also change fractional_bits to 31
// 	Fixed price_2(0.1f);
// 	Fixed total_2;
//
// 	for (int i = 0; i < 10; ++i)
// 		total_2 = total_2 + price_2;
//
// 	std::cout << std::fixed << std::setprecision(10);
// 	std::cout << "Total2: " << total_2 << std::endl;
// 	std::cout << "Is total == 1.0? " << (total_2 == Fixed(1.0f) ? "Yes" : "No") << std::endl;
// }


int main(void)
{
	Fixed		a(2.5f);
	Fixed		b(1.25f);
	Fixed		c;
	const Fixed	ca(4.2f);
	const Fixed	cb(9.1f);

	std::cout << "Initial values:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl << std::endl;

	// Arithmetic
	std::cout << "--- Arithmetic ---" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl << std::endl;

	// Comparison
	std::cout << "--- Comparison ---" << std::endl;
	std::cout << "a == b? " << (a == b) << std::endl;
	std::cout << "a != b? " << (a != b) << std::endl;
	std::cout << "a > b?  " << (a > b) << std::endl;
	std::cout << "a < b?  " << (a < b) << std::endl;
	std::cout << "a >= b? " << (a >= b) << std::endl;
	std::cout << "a <= b? " << (a <= b) << std::endl << std::endl;

	// Assignment
	std::cout << "--- Assignment ---" << std::endl;
	c = a;
	std::cout << "c = a -> c = " << c << std::endl << std::endl;

	// Pre-increment / Pre-decrement
	std::cout << "--- Pre-increment/decrement ---" << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl << std::endl;

	// Post-increment / Post-decrement
	std::cout << "--- Post-increment/decrement ---" << std::endl;
	std::cout << "a++ = " << a++ << " (before)" << std::endl;
	std::cout << "After a++: " << a << std::endl;
	std::cout << "a-- = " << a-- << " (before)" << std::endl;
	std::cout << "After a--: " << a << std::endl << std::endl;

	// Min/Max
	std::cout << "--- Min / Max ---" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	// Const Min/Max
	std::cout << "--- Const Min / Max ---" << std::endl;
	std::cout << "min(ca, cb) = " << Fixed::min(ca, cb) << std::endl;
	std::cout << "max(ca, cb) = " << Fixed::max(ca, cb) << std::endl;

	return 0;
}



