/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertionFalseException.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:09:00 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 14:30:12 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssertionFalseException.hpp"

AssertionFalseException::AssertionFalseException( void ) {
	this->left = NULL;
}

AssertionFalseException::AssertionFalseException( IOperand const * left, eOperandType type, std::string value ):
	left(left),
	type(type),
	value(value) {
}

AssertionFalseException::AssertionFalseException( AssertionFalseException const & e ) {
	*this = e;
}

AssertionFalseException::~AssertionFalseException( void ) throw() {}

AssertionFalseException &    AssertionFalseException::operator=( AssertionFalseException const & rhs ) {
	this->left = rhs.left;
	this->type = rhs.type;
	this->value = rhs.value;
	return *this;
}

const char* AssertionFalseException::what() const throw() {
	std::string message = "Assertion False: ";

	if (!this->left)
		return "Assertion False exception";
	message += eOperandTypeNames[this->left->getType()] + "(" + this->left->toString() + ") ≠ ";
	message += eOperandTypeNames[type] + "(" + value + ")";
	return message.c_str();
}
