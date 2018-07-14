/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 16:14:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"

// # include <cstdlib>
// # include <sstream>
// # include <iostream>
// # include <limits>
// # include <cmath>

int    main(int ac, char **av) {


	// std::string s1 = "-1234567891234567891234567869123456789123456789.0";
	// std::string s2 = "123456789.0";
	// std::stringstream ss;
	// ss.str(s1);
	// float f;

	// ss >> f;
	// if (ss.fail())
	// 	printf("ss fail\n");
	// f = std::stod(s1);
	// printf("original: %s\n", ss.str().c_str());
	// std::cout << "then    : " << std::fixed << f << std::endl;

	// double f = 12345678912345678912345678912345.0;
	// for (int i = 0; i < 10; i++) {
	// 	f *= 100;
		
	// 	if (std::numeric_limits<float>::min() <= i && i <= std::numeric_limits<float>::max()) {
	// 		printf("float within limits\n");
	// 	}
	// 	if (std::isinf(f))
	// 		printf("float overflowed\n");
	// 	printf("f: %f\n", f);
	// }
	// float f2 = f;
	// printf("f2: %f\n", f2);


	// std::string s1 = "1234567891234567891234567869.0";
	// std::string s2 = "123456789.0";
	// std::string s3 = "Hello world";

	// float d;
	// d = std::atof(s2.c_str());
	// d = 123456789.0f;
	// printf("original: %s\n", s2.c_str());
	// printf("float   : %f\n", d);

	// int n = 100000;
	// long n2 = n;
	// for (int i = 0; i < 10; i++) {
	// 	n *= 100;
	// 	n2 *= 100;
	// 	if (std::numeric_limits<int>::min() <= n2 && n2 <= std::numeric_limits<int>::max()) {}
	// 	else
	// 		printf("n overflowed\n");
	// 	printf("n  : %d\n", n);
	// 	printf("n2 : %lu\n", n2);
	// }
	// printf("int min: %d\n", std::numeric_limits<int>::min());
	// printf("int max: %d\n", std::numeric_limits<int>::max());



	// TODO add exception protection

	Lexer *lexer = new Lexer();

	if (ac == 1)
		lexer->readFromSI();
	else	
		lexer->readFile(av[1]);
	
	if (lexer->hasError()) {
		delete lexer;
		return (0);
	}
	lexer->printTokens();
	
	std::vector<Token*> tokens = lexer->getTokens();
	
	Parser *parser = new Parser(tokens);
	
	parser->parse();
	
	return (0);
}
