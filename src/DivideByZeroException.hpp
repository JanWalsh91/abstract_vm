/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZeroException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:15:32 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:38:20 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class DivideByZeroException : public std::exception {
	public:
		DivideByZeroException( void );
		DivideByZeroException( DivideByZeroException const & e );
		virtual ~DivideByZeroException( void ) throw();
		DivideByZeroException &    operator=( DivideByZeroException const & rhs ) ;
		virtual const char* what() const throw();
};
