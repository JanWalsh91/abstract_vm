/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:17 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 13:48:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OverflowException.hpp"

OverflowException::OverflowException( void ) : overflow_error(" ") {}

OverflowException::OverflowException( OverflowException const & e ) : overflow_error(" ") {
	*this = e;
}

OverflowException::~OverflowException( void ) throw() {}

OverflowException &    OverflowException::operator=( OverflowException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* OverflowException::what() const throw() {
	return "Overflow";
}
