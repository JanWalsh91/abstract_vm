/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 15:02:34 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERFLOW_EXCEPTION_HPP
# define OVERFLOW_EXCEPTION_HPP

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
