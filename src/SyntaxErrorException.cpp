/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxErrorException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 13:58:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SyntaxErrorException.hpp"

SyntaxErrorException::SyntaxErrorException( void ) {}

SyntaxErrorException::SyntaxErrorException( std::string line, size_t lineN ) : 
	line(line),
	lineN(lineN) {	
}

SyntaxErrorException::SyntaxErrorException( SyntaxErrorException const & e ) {
	*this = e;
}

SyntaxErrorException::~SyntaxErrorException( void ) throw() {}

SyntaxErrorException &    SyntaxErrorException::operator=( SyntaxErrorException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* SyntaxErrorException::what() const throw() {
	std::string message = "";
	message += "Syntax error [Line " + std::to_string(this->lineN) + "]: " + this->line;
	return message.c_str();
}
