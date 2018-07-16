/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxErrorException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:49:05 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ERROR_EXCEPTION_HPP
# define SYNTAX_ERROR_EXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>

class SyntaxErrorException : public std::exception {
	public:
		SyntaxErrorException( std::string line, size_t lineN );
		SyntaxErrorException( SyntaxErrorException const & e );
		virtual ~SyntaxErrorException( void ) throw();
		SyntaxErrorException &    operator=( SyntaxErrorException const & rhs ) ;
		virtual const char* what() const throw();

	private:
		SyntaxErrorException( void );
		std::string line;
		size_t lineN;
};

#endif
