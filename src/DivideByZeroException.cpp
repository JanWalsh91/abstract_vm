/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZeroException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:46:12 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 14:32:53 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DivideByZeroException.hpp"

DivideByZeroException::DivideByZeroException( void ) {}

DivideByZeroException::DivideByZeroException( IOperand const * left, IOperand const * right ) :
	left(left),
	right(right) {
	
}

DivideByZeroException::DivideByZeroException( DivideByZeroException const & e ) {
	*this = e;
}

DivideByZeroException::~DivideByZeroException( void ) throw() {}

DivideByZeroException &    DivideByZeroException::operator=( DivideByZeroException const & rhs ) {
	this->right = rhs.right;
	this->right = rhs.right;
	return *this;
}

const char* DivideByZeroException::what() const throw() {
	std::string message = "Cannot divide by zero: ";

	if (!this->left || !this->right)
		return "Divide by 0 exception";
	message += eOperandTypeNames[this->left->getType()] + "(" + this->left->toString() + ") by ";
	message += eOperandTypeNames[this->right->getType()] + "(" + this->right->toString() + ")";
	return message.c_str();
}
