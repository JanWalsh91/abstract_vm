/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandsNotIntegersException.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:46:49 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 15:01:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDS_NOT_INTEGERS_EXCEPTION_HPP
# define OPERANDS_NOT_INTEGERS_EXCEPTION_HPP

# include <exception>

class OperandsNotIntegersException : public std::exception {
	public:
		OperandsNotIntegersException( void );
		OperandsNotIntegersException( OperandsNotIntegersException const & e );
		virtual ~OperandsNotIntegersException( void ) throw();
		OperandsNotIntegersException &    operator=( OperandsNotIntegersException const & rhs ) ;
		virtual const char* what() const throw();
};

#endif
