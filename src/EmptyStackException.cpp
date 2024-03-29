/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyStackException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:58:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EmptyStackException.hpp"

EmptyStackException::EmptyStackException( void ) {}

EmptyStackException::EmptyStackException( EmptyStackException const & e ) {
	*this = e;
}

EmptyStackException::~EmptyStackException( void ) throw() {}

EmptyStackException &    EmptyStackException::operator=( EmptyStackException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* EmptyStackException::what() const throw() {
	return "Empty stack. Cannot perform operation.";
}
