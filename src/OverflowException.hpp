/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:20:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class OverflowException : public std::exception {
	public:
		OverflowException( void );
		OverflowException( OverflowException const & e );
		virtual ~OverflowException( void ) throw();
		OverflowException &    operator=( OverflowException const & rhs ) ;
		virtual const char* what() const throw();
};
