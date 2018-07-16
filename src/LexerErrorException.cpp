/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerErrorException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:35:44 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexerErrorException.hpp"

LexerErrorException::LexerErrorException( void ) {}

LexerErrorException::LexerErrorException( LexerErrorException const & e ) {
	*this = e;
}

LexerErrorException::~LexerErrorException( void ) throw() {}

LexerErrorException &    LexerErrorException::operator=( LexerErrorException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* LexerErrorException::what() const throw() {
	return "Errors found in Lexer.";
}
