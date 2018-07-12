/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:40:15 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 15:00:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>
# include <iostream>
# include "eOperandType.hpp"

class Token {

	public:
		Token(std::string instruction);
		Token(std::string instruction, std::string type, std::string value);
		Token(Token const &);
		~Token();
		
		// Getters
		std::string		getInstruction() const;
		eOperandType	getType() const;
		std::string		getValue() const;

		Token &operator=(Token const & rhs);
	
	private:
		std::string		instruction;
		eOperandType	type;
		std::string		value;

		Token();
		
};

std::ostream& operator<<( std::ostream& os, const Token & token );

#endif