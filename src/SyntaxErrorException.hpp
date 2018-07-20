/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxErrorException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/20 11:49:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ERROR_EXCEPTION_HPP
# define SYNTAX_ERROR_EXCEPTION_HPP

#include <exception>
#include <string>

class SyntaxErrorException : public std::runtime_error {
	public:
		SyntaxErrorException( std::string line );
		SyntaxErrorException( SyntaxErrorException const & e );
		virtual ~SyntaxErrorException( void ) throw();
		SyntaxErrorException &    operator=( SyntaxErrorException const & rhs ) ;

	private:
		SyntaxErrorException( void );
};

#endif
