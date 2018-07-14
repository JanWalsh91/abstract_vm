/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyStackException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:35:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class EmptyStackException : public std::exception {
	public:
		EmptyStackException( void );
		EmptyStackException( EmptyStackException const & e );
		virtual ~EmptyStackException( void ) throw();
		EmptyStackException &    operator=( EmptyStackException const & rhs ) ;
		virtual const char* what() const throw();
};
