/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 15:04:11 by jwalsh           ###   ########.fr       */
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
	this->instruction = instruction;
	this->type = eOperandType::None;
	this->value = "";
}

Token::Token(std::string instruction, std::string type, std::string value) {
	printf("token constructor 2\n");
	printf("instruction: %s, type: %s, value: %s\n", instruction.c_str(), type.c_str(), value.c_str());
	if (instruction != "push" && instruction != "assert") {
		std::cout << "error: " << instruction << " does not require value\n"; 
		std::exit(0);
	}
	this->instruction = instruction;
	if (type == "int8")
		this->type = eOperandType::Int8;
	else if (type == "int16")
		this->type = eOperandType::Int16;
	else if (type == "int32")
		this->type = eOperandType::Int32;
	else if (type == "float")
		this->type = eOperandType::Float;
	else if (type == "double")
		this->type = eOperandType::Double;
	else {
		std::cout << "error: invlaid operand type\n";
		std::exit(0);
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

std::string		Token::getInstruction() const {
	return this->instruction;	
}

eOperandType	Token::getType() const {
	return this->type;
}

std::string		Token::getValue() const {
	return this->value;
}


std::ostream& operator<<( std::ostream& os, const Token & token ) {
	// printf("<< op. instruction: %s\n", token.getInstruction().c_str());
	if (token.getInstruction().size() > 0)
		os << token.getInstruction();
	if (token.getType() != eOperandType::None)
		os << ", type: " << token.getType();
	if (token.getValue().size() > 0)
		os << ", value: " << token.getValue();
    return os;
}