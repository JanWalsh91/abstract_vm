/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerErrorException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 12:34:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class LexerErrorException : public std::exception {
	public:
		LexerErrorException( void );
		LexerErrorException( LexerErrorException const & e );
		virtual ~LexerErrorException( void ) throw();
		LexerErrorException &    operator=( LexerErrorException const & rhs ) ;
		virtual const char* what() const throw();
};
