/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:40:15 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:23:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>
# include <iostream>
# include "eOperandType.hpp"
# include "eInstructionType.hpp"

class Token {

	public:
		Token(std::string instruction);
		Token(std::string instruction, std::string type, std::string value);
		Token(Token const &);
		~Token();
		
		// Getters
		eInstructionType	getInstruction() const;
		eOperandType		getType() const;
		std::string			getValue() const;

		Token &operator=(Token const & rhs);
	
	private:
		eInstructionType	instruction;
		eOperandType		type;
		std::string			value;

		Token();
		
};

std::ostream& operator<<( std::ostream& os, const Token & token );

#endif