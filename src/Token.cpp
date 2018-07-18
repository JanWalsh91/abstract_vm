/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 10:38:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token() {}

Token::Token(size_t line, std::string instruction) {
	this->line = line;
	if (instruction == "push" || instruction == "assert") {
		throw SyntaxErrorException(instruction, line);
	}
	for (int i = 0; i < INSTRUCTION_NUM; ++i) {
		if (eInstructionTypeNames[i] == instruction) {
			this->instruction = static_cast<eInstructionType>(i);
			break ;
		}
	}
	this->value = "";
}

Token::Token(size_t line, std::string instruction, std::string type, std::string value) {
	this->line = line;
	if (instruction != "push" && instruction != "assert") {
		throw SyntaxErrorException(instruction, line);
	}
	for (int i = 0; i < 5; ++i) {
		if (eOperandTypeNames[i] == type) {
			this->type = static_cast<eOperandType>(i);
			break ;
		}
	}
	for (int i = 0; i < 11; ++i) {
		if (eInstructionTypeNames[i] == instruction) {
			this->instruction = static_cast<eInstructionType>(i);
			break ;
		}
	}
	this->value = value;
}

Token::Token( Token const & token ) {
	*this = token;
}

Token::~Token() {
}

Token &Token::operator=(Token const & rhs) {
	(void)rhs;
	return *this;
}

eInstructionType		Token::getInstruction() const {
	return this->instruction;	
}

eOperandType	Token::getType() const {
	return this->type;
}

std::string		Token::getValue() const {
	return this->value;
}

size_t			Token::getLine() const {
	return this->line;
}

std::ostream& operator<<( std::ostream& os, const Token & token ) {
	os << "[Line " << token.getLine() << "]: ";
	os << eInstructionTypeNames[token.getInstruction()];
	if (token.getInstruction() == eInstructionType::Push || token.getInstruction() == eInstructionType::Assert) {
		os << ", type: " << eOperandTypeNames[token.getType()];
		os << ", value: " << token.getValue();
	}
    return os;
}