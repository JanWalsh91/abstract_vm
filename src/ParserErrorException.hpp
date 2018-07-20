/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserErrorException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/19 14:22:25 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERROR_EXCEPTION_HPP
# define PARSER_ERROR_EXCEPTION_HPP

# include <exception>

class ParserErrorException : public std::exception {
	public:
		ParserErrorException( void );
		ParserErrorException( ParserErrorException const & e );
		virtual ~ParserErrorException( void ) throw();
		ParserErrorException &    operator=( ParserErrorException const & rhs ) ;
		virtual const char* what() const throw();
};

#endif
