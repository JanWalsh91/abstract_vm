/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:40:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token() {}

Token::Token(std::string instruction) {
	printf("token constructor 1\n");
	printf("instruction: %s\n", instruction.c_str());
	if (instruction == "push" || instruction == "assert") {
		std::cout << "error: " << instruction << " requires value\n";
		std::exit(0);
	}
	for (int i = 0; i < 11; ++i) {
		if (eInstructionTypeNames[i] == instruction) {
			this->instruction = static_cast<eInstructionType>(i);
			break ;
		}
	}
	// this->instruction = eInstructionType::None;
	// this->type = eOperandType::None;
	this->value = "";
}

Token::Token(std::string instruction, std::string type, std::string value) {
	printf("token constructor 2\n");
	printf("instruction: %s, type: %s, value: %s\n", instruction.c_str(), type.c_str(), value.c_str());
	if (instruction != "push" && instruction != "assert") {
		std::cout << "error: " << instruction << " does not require value\n"; 
		std::exit(0);
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

std::ostream& operator<<( std::ostream& os, const Token & token ) {
	// printf("displaying token: ");
	// (void)token;
	
	os << eInstructionTypeNames[token.getInstruction()];
	if (token.getInstruction() == eInstructionType::Push || token.getInstruction() == eInstructionType::Assert) {
		os << ", type: " << eOperandTypeNames[token.getType()];
		os << ", value: " << token.getValue();
	}
    return os;
}