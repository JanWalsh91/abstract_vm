/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandsNotIntegersException.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:46:49 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 15:46:56 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class OperandsNotIntegersException : public std::exception {
	public:
		OperandsNotIntegersException( void );
		OperandsNotIntegersException( OperandsNotIntegersException const & e );
		virtual ~OperandsNotIntegersException( void ) throw();
		OperandsNotIntegersException &    operator=( OperandsNotIntegersException const & rhs ) ;
		virtual const char* what() const throw();
};
