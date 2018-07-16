/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExitCalledBeforeEndOfProgramException.hpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:45:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CALLED_BEFORE_END_OF_PROGRAM_EXCEPTION_HPP
# define EXIT_CALLED_BEFORE_END_OF_PROGRAM_EXCEPTION_HPP

# include <exception>

class ExitCalledBeforeEndOfProgramException : public std::exception {
	public:
		ExitCalledBeforeEndOfProgramException( void );
		ExitCalledBeforeEndOfProgramException( ExitCalledBeforeEndOfProgramException const & e );
		virtual ~ExitCalledBeforeEndOfProgramException( void ) throw();
		ExitCalledBeforeEndOfProgramException &    operator=( ExitCalledBeforeEndOfProgramException const & rhs ) ;
		virtual const char* what() const throw();
};

#endif