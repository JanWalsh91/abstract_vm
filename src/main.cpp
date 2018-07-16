/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 17:21:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"

// # include <cstdlib>
// # include <sstream>
// # include <iostream>
// # include <limits>
// # include <cmath>

void	free_tokens(std::vector<Token*> tokens) {
	printf("free_tokens\n");
	for (uint i = 0; i < tokens.size(); ++i) {
		delete tokens[i];
	}
}

int    main(int ac, char **av) {

	try {
		Lexer *lexer = new Lexer();

		try {
			if (ac == 1)
				lexer->readFromSI();
			else	
				lexer->readFile(av[1]);
		} catch (const std::exception & e) {
			std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
			std::vector<Token*> tokens = lexer->getTokens();
			free_tokens(tokens);
			delete lexer;
			return (0);
		}
		
		lexer->printTokens();
		
		std::vector<Token*> tokens = lexer->getTokens();
		
		Parser *parser = new Parser(tokens);
		
		// (void)parser;
		parser->parse();
		free_tokens(tokens);
		delete lexer;
		delete parser;
	} catch (const std::exception & e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	return (0);
}
