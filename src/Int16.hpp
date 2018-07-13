/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:54:20 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:58:14 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
# define INT16_HPP

# include "IOperand.hpp"
# include "IOperandFactory.hpp"

class Int16: public IOperand {
	
	public:
		Int16(std::string);
		Int16(Int16 const &);
		~Int16();

		Int16 &operator=(Int16 const & rhs);

		int getPrecision( void ) const;
		eOperandType getType( void ) const;
	
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		
		std::string const & toString( void ) const;
	
	private:
		Int16();
		std::string value;
};

#endif
