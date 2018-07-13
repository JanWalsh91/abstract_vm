/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 16:37:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"

int    main() {

	// float a = 922337203685477580800.000000;
	// a++;
	// float b = std::numeric_limits<float>::max();
	// printf("a: %f\n", a);
	// printf("limit: %f\n", b);

	// TODO add exception protection

	// Lexer *lexer = new Lexer("test.txt");
	Lexer *lexer = new Lexer("test.1.txt");
	lexer->printTokens();
	std::vector<Token*> tokens = lexer->getTokens();
	
	Parser *parser = new Parser(tokens);
	
	parser->parse();
	
	return (0);
}
