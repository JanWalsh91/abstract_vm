/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserErrorException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/19 14:23:44 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserErrorException.hpp"

ParserErrorException::ParserErrorException( void ) {}

ParserErrorException::ParserErrorException( ParserErrorException const & e ) {
	*this = e;
}

ParserErrorException::~ParserErrorException( void ) throw() {}

ParserErrorException &    ParserErrorException::operator=( ParserErrorException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* ParserErrorException::what() const throw() {
	return "Errors found while parsing.";
}
