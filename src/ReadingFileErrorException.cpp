/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadingFileErrorException.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/19 12:54:28 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReadingFileErrorException.hpp"

ReadingFileErrorException::ReadingFileErrorException( void ) {}

ReadingFileErrorException::ReadingFileErrorException( ReadingFileErrorException const & e ) {
	*this = e;
}

ReadingFileErrorException::~ReadingFileErrorException( void ) throw() {}

ReadingFileErrorException &    ReadingFileErrorException::operator=( ReadingFileErrorException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* ReadingFileErrorException::what() const throw() {
	return "Error reading file";
}
