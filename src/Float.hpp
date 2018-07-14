/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:00:44 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 13:25:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <regex>

# include "IOperand.hpp"
# include "IOperandFactory.hpp"

class Float: public IOperand {
	
	public:
		Float(std::string);
		Float(Float const &);
		~Float();

		Float &operator=(Float const & rhs);

		int getPrecision( void ) const;
		eOperandType getType( void ) const;
	
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		
		std::string const & toString( void ) const;
	
	private:
		Float();
		std::string value;
};

#endif
