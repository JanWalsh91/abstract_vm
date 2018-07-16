/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughOperandsException.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:58:50 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotEnoughOperandsException.hpp"

NotEnoughOperandsException::NotEnoughOperandsException( void ) {}

NotEnoughOperandsException::NotEnoughOperandsException( NotEnoughOperandsException const & e ) {
	*this = e;
}

NotEnoughOperandsException::~NotEnoughOperandsException( void ) throw() {}

NotEnoughOperandsException &    NotEnoughOperandsException::operator=( NotEnoughOperandsException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* NotEnoughOperandsException::what() const throw() {
	return "Not enough operands to perform operation";
}
