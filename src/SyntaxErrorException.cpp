/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxErrorException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/20 11:44:21 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SyntaxErrorException.hpp"

SyntaxErrorException::SyntaxErrorException( void ) : std::runtime_error("") {}

SyntaxErrorException::SyntaxErrorException( std::string line ) : 
	std::runtime_error("Syntax Error: " + line) {	
}

SyntaxErrorException::SyntaxErrorException( SyntaxErrorException const & e ) : std::runtime_error("") {
	*this = e;
}

SyntaxErrorException::~SyntaxErrorException( void ) throw() {}

SyntaxErrorException &    SyntaxErrorException::operator=( SyntaxErrorException const & rhs ) {
	(void)rhs;
	return *this;
}
