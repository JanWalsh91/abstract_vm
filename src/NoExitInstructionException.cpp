/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoExitInstructionException.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:05:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NoExitInstructionException.hpp"

NoExitInstructionException::NoExitInstructionException( void ) {}

NoExitInstructionException::NoExitInstructionException( NoExitInstructionException const & e ) {
	*this = e;
}

NoExitInstructionException::~NoExitInstructionException( void ) throw() {}

NoExitInstructionException &    NoExitInstructionException::operator=( NoExitInstructionException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* NoExitInstructionException::what() const throw() {
	return "Error: program missing exit instruction";
}
