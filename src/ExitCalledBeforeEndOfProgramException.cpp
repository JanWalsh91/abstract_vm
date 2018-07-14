/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughOperandsException.1.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:45:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExitCalledBeforeEndOfProgramException.hpp"

ExitCalledBeforeEndOfProgramException::ExitCalledBeforeEndOfProgramException( void ) {}

ExitCalledBeforeEndOfProgramException::ExitCalledBeforeEndOfProgramException( ExitCalledBeforeEndOfProgramException const & e ) {
	*this = e;
}

ExitCalledBeforeEndOfProgramException::~ExitCalledBeforeEndOfProgramException( void ) throw() {}

ExitCalledBeforeEndOfProgramException &    ExitCalledBeforeEndOfProgramException::operator=( ExitCalledBeforeEndOfProgramException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* ExitCalledBeforeEndOfProgramException::what() const throw() {
	return "Assertion is False Exception";
}
