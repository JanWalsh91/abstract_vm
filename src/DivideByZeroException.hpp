/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZeroException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:44:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDE_BY_ZERO_EXCEPTION_HPP
# define DIVIDE_BY_ZERO_EXCEPTION_HPP

#include <exception>
#include "IOperand.hpp"

class DivideByZeroException : public std::exception {
	public:
		DivideByZeroException( IOperand const * left, IOperand const * right );
		DivideByZeroException( DivideByZeroException const & e );
		virtual ~DivideByZeroException( void ) throw();
		DivideByZeroException &    operator=( DivideByZeroException const & rhs ) ;
		virtual const char* what() const throw();

	private:
		DivideByZeroException( void );
		IOperand const *	left;
		IOperand const *	right;
};

#endif