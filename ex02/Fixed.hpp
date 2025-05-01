/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:09 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 16:11:10 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef EX02_HPP
# define EX02_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fixpoint_nbr;
		static const int	_fractional_bits;
	public:
		Fixed();								//Default Constructor
		Fixed(const int input);					// Conversion constructor: initializes Fixed from an integer value
		Fixed(const float input);				// Conversion constructor: initializes Fixed from a float value
		Fixed(const Fixed &copy);				// Copy Constructor alias deep copy
		~Fixed();								// Destructor

		// overload Arithmetic operators
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		Fixed	&operator++(void); // pre-increment
		Fixed	&operator--(void); // pre-decrease
		Fixed	operator++(int); //post-increment
		Fixed	operator--(int); //post-decrease
		// overload Assignment Operators
		Fixed	&operator=(const Fixed &other);	// also overload the = function uses a reference
		// overload Comparison operators
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>(Fixed const &other) const;

		//min and max functions
		static const Fixed	&min(Fixed const &other1, Fixed const &other2);
		static const Fixed	&max(Fixed const &other1, Fixed const &other2);

		int		getRawBits(void)const;
		void	setRawBits(int raw);
		float	toFloat(void)const;
		int		toInt(void)const;
};

// Overloads the << operator to allow printing Fixed objects using std::cout
std::ostream &operator<<(std::ostream &outStream, Fixed const &fixedObj);
#endif
