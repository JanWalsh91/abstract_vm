/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertionFalseException.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:00:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <string>
#include "IOperand.hpp"
#include "eOperandType.hpp"

class AssertionFalseException : public std::exception {
	public:
		AssertionFalseException( IOperand const * left, eOperandType type, std::string value );
		AssertionFalseException( AssertionFalseException const & e );
		virtual ~AssertionFalseException( void ) throw();
		AssertionFalseException &    operator=( AssertionFalseException const & rhs ) ;
		virtual const char* what() const throw();
	
	private:
		AssertionFalseException( void );
		IOperand const		*left;
		eOperandType		type;
		std::string			value;
};
