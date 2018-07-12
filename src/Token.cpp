/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 13:40:25 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token() {}

Token::Token(std::string instruction) {
	printf("token constructor 1\n");
	printf("instruction: %s\n", instruction.c_str());
	this->instruction = instruction;
	this->type = "";
	this->value = "";
}

Token::Token(std::string instruction, std::string type, std::string value) {
	printf("token constructor 2\n");
	printf("instruction: %s, type: %s, value: %s\n", instruction.c_str(), type.c_str(), value.c_str());
	this->instruction = instruction;
	this->type = type;
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

std::string Token::getInstruction() const {
	return this->instruction;	
}

std::string Token::getType() const {
	return this->type;
}

std::string Token::getValue() const {
	return this->value;
}


std::ostream& operator<<( std::ostream& os, const Token & token ) {
	// printf("<< op. instruction: %s\n", token.getInstruction().c_str());
	if (token.getInstruction().size() > 0)
		os << token.getInstruction();
	if (token.getType().size() > 0)
		os << ", type: " << token.getType();
	if (token.getValue().size() > 0)
		os << ", value: " << token.getValue();
    return os;
}