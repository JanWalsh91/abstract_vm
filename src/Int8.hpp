/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:54:20 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:58:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include "IOperand.hpp"
# include "IOperandFactory.hpp"

class Int8: public IOperand {
	
	public:
		Int8(std::string);
		Int8(Int8 const &);
		~Int8();

		Int8 &operator=(Int8 const & rhs);

		int getPrecision( void ) const;
		eOperandType getType( void ) const;
	
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		
		std::string const & toString( void ) const;
	
	private:
		Int8();
		std::string value;
};

#endif
