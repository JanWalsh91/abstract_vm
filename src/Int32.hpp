/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:54:20 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 14:37:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
# define INT32_HPP

# include "IOperand.hpp"
# include "IOperandFactory.hpp"

class Int32: public IOperand {
	
	public:
		Int32(std::string);
		Int32(Int32 const &);
		~Int32();

		Int32 &operator=(Int32 const & rhs);

		int getPrecision( void ) const;
		eOperandType getType( void ) const;
	
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		
		std::string const & toString( void ) const;
	
	private:
		Int32();
		std::string value;
};

#endif
