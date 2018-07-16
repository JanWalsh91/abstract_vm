/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadingFileErrorException.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:00:00 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class ReadingFileErrorException : public std::exception {
	public:
		ReadingFileErrorException( void );
		ReadingFileErrorException( ReadingFileErrorException const & e );
		virtual ~ReadingFileErrorException( void ) throw();
		ReadingFileErrorException &    operator=( ReadingFileErrorException const & rhs ) ;
		virtual const char* what() const throw();
};
