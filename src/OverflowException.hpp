/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 13:41:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stdexcept>

class OverflowException : public std::overflow_error {
	public:
		OverflowException( void );
		OverflowException( OverflowException const & e );
		virtual ~OverflowException( void ) throw();
		OverflowException &    operator=( OverflowException const & rhs ) ;
		virtual const char* what() const throw();
};
