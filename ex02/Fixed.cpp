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
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	// std::cout << "Int Constructor called" << std::endl;
	this->_fixpoint_nbr = input << this->_fractional_bits; //leftshift operator equal in this case to multiplicate by 256 because 2^8 = 256
	// std::cout << "fixpoint nbr after conversion for int "<< this->_fixpoint_nbr << std::endl;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float Constructor called" << std::endl;
	this->_fixpoint_nbr = roundf(input * (1 << this->_fractional_bits)); //float to fixed point value
// 	std::cout << "fixpoint nbr before rounding for float "<< input * (1 << this->_fractional_bits) << std::endl;
// 	std::cout << "fixpoint nbr after conversion for float "<< this->_fixpoint_nbr << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	this->_fixpoint_nbr = copy.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout << "Deconstructor called" << std::endl;
}

// overload Arithmetic operators
Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	result(this->toFloat() / other.toFloat());
	return (result);
}

Fixed	&Fixed::operator++(void) //pre++
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void) //pre--
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixpoint_nbr;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixpoint_nbr;
	return (temp);
}

// overload Assignment Operators
Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixpoint_nbr = other.getRawBits();
	return (*this);
}

// overload Comparison operators
bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}
Fixed	&Fixed::min(Fixed &other1, Fixed &other2)
{
	if (other1 < other2)
		return (other1);
	return (other2);
}

Fixed	&Fixed::max(Fixed &other1, Fixed &other2)
{
	if (other1 > other2)
		return (other1);
	return (other2);
}

const Fixed	&Fixed::min(Fixed const &other1, Fixed const &other2)
{
	if (other1 < other2)
		return (other1);
	return (other2);
}

const Fixed	&Fixed::max(Fixed const &other1, Fixed const &other2)
{
	if (other1 > other2)
		return (other1);
	return (other2);
}

int		Fixed::getRawBits(void)const
{
	return (this->_fixpoint_nbr);
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
	return (this->_fixpoint_nbr >> this->_fractional_bits); // right shift to divide
}

std::ostream& operator<<(std::ostream &outStream, const Fixed &fixedObj)
{
	outStream << fixedObj.toFloat();
	return (outStream);
}