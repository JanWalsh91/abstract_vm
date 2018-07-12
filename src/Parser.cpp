/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:29 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 14:37:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
	// this->tokens = std::vector<Token*>();
}

Parser::Parser(std::vector<Token*> tokens) {
	this->tokens = tokens;
}

Parser::Parser( Parser const & parser ) {
	*this = parser;
}

Parser::~Parser() {
}

Parser &Parser::operator=(Parser const & rhs) {
	(void)rhs;
	return *this;
}

void	Parser::setTokens(std::vector<Token*> tokens) {
	this->tokens = tokens;
}

void	Parser::parse() {
	std::cout << "parse\n";
	if (this->tokens.size() == 0) {
		return ;
	}
	
	
}