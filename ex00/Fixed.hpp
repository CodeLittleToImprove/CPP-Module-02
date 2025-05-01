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


# ifndef EX00_HPP
# define EX00_HPP

#include <iostream>



class	Fixed
{
	private:
		int					_fixpoint_nbr;
		static const int	_fractional_bits;
	public:
		Fixed();								//Default Constructor
		Fixed(const Fixed &copy);				// Copy Constructor alias deep copy
		Fixed &operator = (const Fixed &other);	// Copy Assignment Constructor
		~Fixed();								// Destructor
		int		getRawBits(void)const;
		void	setRawBits(int raw);
};

#endif
