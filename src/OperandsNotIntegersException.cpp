/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandsNotIntegersException.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:17 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:58:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandsNotIntegersException.hpp"

OperandsNotIntegersException::OperandsNotIntegersException( void ) {}

OperandsNotIntegersException::OperandsNotIntegersException( OperandsNotIntegersException const & e ) {
	*this = e;
}

OperandsNotIntegersException::~OperandsNotIntegersException( void ) throw() {}

OperandsNotIntegersException &    OperandsNotIntegersException::operator=( OperandsNotIntegersException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* OperandsNotIntegersException::what() const throw() {
	return "Operands are not integers. Cannot perform operation";
}
