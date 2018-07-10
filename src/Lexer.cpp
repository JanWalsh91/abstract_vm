/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:34 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/10 17:15:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer() {
	std::cout << "Lexer constructor\n";
}

Lexer::Lexer(std::string file) {
	this->readFile(file);
}

Lexer::Lexer( Lexer const & lexer ) {
	*this = lexer;
}

Lexer::~Lexer() {
}

Lexer &Lexer::operator=(Lexer const & rhs) {
	(void)rhs;
	return *this;
}

void	Lexer::readFile(std::string file) {
	std::ifstream is(file);
	std::string line;
	
	if ( is.is_open() ) {
		while (std::getline(is, line)) {
   			std::istringstream iss(line);
			printf("%s\n", iss.str().c_str());
		}
	
	}
	else {
		std::cout << "error" << std::endl;
	}
}
