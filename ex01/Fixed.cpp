/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:05 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 16:11:06 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	_fixpoint_nbr = 0;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_fixpoint_nbr = copy.getRawBits();
}

Fixed::Fixed(const int input)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_fixpoint_nbr = input << this->_fractional_bits; //leftshift operator
}

Fixed::Fixed(const float input)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_fixpoint_nbr = roundf(input * (1 << this->_fractional_bits)); //float to fixed point value
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixpoint_nbr = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

int		Fixed::getRawBits(void)const
{
	return this->_fixpoint_nbr;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixpoint_nbr = raw;
}

float	Fixed::toFloat(void)const
{
	return (static_cast<float>(this->_fixpoint_nbr)
		/ static_cast<float>(1 << this->_fractional_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fixpoint_nbr >> this->_fractional_bits);
}

std::ostream& operator<<(std::ostream &outStream, const Fixed &fixedObj)
{
	outStream << fixedObj.toFloat();
	return outStream;
}