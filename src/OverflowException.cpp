/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:17 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:58:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OverflowException.hpp"

OverflowException::OverflowException( void ) {}

OverflowException::OverflowException( OverflowException const & e ) {
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
