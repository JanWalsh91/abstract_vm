/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertionFalseException.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:09:00 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 13:09:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssertionFalseException.hpp"

AssertionFalseException::AssertionFalseException( void ) {}

AssertionFalseException::AssertionFalseException( AssertionFalseException const & e ) {
	*this = e;
}

AssertionFalseException::~AssertionFalseException( void ) throw() {}

AssertionFalseException &    AssertionFalseException::operator=( AssertionFalseException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* AssertionFalseException::what() const throw() {
	return "Assertion is False Exception";
}
