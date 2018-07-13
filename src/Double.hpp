/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:00:44 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 16:39:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include "IOperand.hpp"
# include "IOperandFactory.hpp"

class Double: public IOperand {
	
	public:
		Double(std::string);
		Double(Double const &);
		~Double();

		Double &operator=(Double const & rhs);

		int getPrecision( void ) const;
		eOperandType getType( void ) const;
	
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		
		std::string const & toString( void ) const;
	
	private:
		Double();
		std::string value;
};

#endif
