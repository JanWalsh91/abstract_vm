/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExitCalledBeforeEndOfProgramException.cpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:38:30 by jwalsh           ###   ########.fr       */
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
	return "Error: 'exit' called before end of program";
}
