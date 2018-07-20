/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:40:15 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/19 12:59:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>
# include <iostream>

# include "eOperandType.hpp"
# include "eInstructionType.hpp"
# include "SyntaxErrorException.hpp"

class Token {

	public:
		Token(size_t line, std::string instruction);
		Token(size_t line, std::string instruction, std::string type, std::string value);
		Token(Token const &);
		~Token();
		
		eInstructionType	getInstruction() const;
		eOperandType		getType() const;
		std::string			getValue() const;
		size_t				getLine() const;

		Token &operator=(Token const & rhs);
	
	private:
		eInstructionType	instruction;
		eOperandType		type;
		std::string			value;
		size_t				line;

		Token();
		
};

std::ostream& operator<<( std::ostream& os, const Token & token );

#endif