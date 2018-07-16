/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:48:18 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERFLOW_EXCEPTION_HPP
# define OVERFLOW_EXCEPTION_HPP

# include <exception>
# include <stdexcept>

class OverflowException : public std::overflow_error {
	public:
		OverflowException( void );
		OverflowException( OverflowException const & e );
		virtual ~OverflowException( void ) throw();
		OverflowException &    operator=( OverflowException const & rhs ) ;
		virtual const char* what() const throw();
};

#endif
