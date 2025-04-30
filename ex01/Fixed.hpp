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


# ifndef CPP0X_TEMPLATE_HPP
# define CPP0X_TEMPLATE_HPP

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
		Fixed(const Fixed &other);				// Copy Constructor alias deep copy
		Fixed &operator=(const Fixed &other);	// Copy Assignment Constructor / also overload function
		~Fixed();								// Destructor
		int		getRawBits(void)const;
		void	setRawBits(int raw);
		float	toFloat(void)const;
		int		toInt(void)const;
};

// Overloads the << operator to allow printing Fixed objects using std::cout
std::ostream &operator<<(std::ostream &outStream, Fixed const &fixedObj);
#endif
