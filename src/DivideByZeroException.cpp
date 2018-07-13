/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZeroException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:46:12 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:46:19 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DivideByZeroException.hpp"

DivideByZeroException::DivideByZeroException( void ) {}

DivideByZeroException::DivideByZeroException( DivideByZeroException const & e ) {
	*this = e;
}

DivideByZeroException::~DivideByZeroException( void ) throw() {}

DivideByZeroException &    DivideByZeroException::operator=( DivideByZeroException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* DivideByZeroException::what() const throw() {
	return "Divide By Zero Exception";
}
