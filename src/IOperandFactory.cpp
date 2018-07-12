/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:36:02 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:42:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperandFactory.hpp"

IOperandFactory::IOperandFactory () {
	this->getOperand[0] = &IOperandFactory::createInt8;
	this->getOperand[1] = &IOperandFactory::createInt16;
	this->getOperand[2] = &IOperandFactory::createInt32;
	this->getOperand[3] = &IOperandFactory::createFloat;
	this->getOperand[4] = &IOperandFactory::createDouble;
}

IOperandFactory::IOperandFactory( IOperandFactory const & iOperandFactory ) {
	*this = iOperandFactory;
}

IOperandFactory::~IOperandFactory () {}

IOperandFactory &IOperandFactory::operator=(IOperandFactory const & rhs) {
	(void)rhs;
	return *this;
}

IOperand const * IOperandFactory::createOperand(eOperandType type, std::string const & value) const {
	IOperand const * newOperand = (this->*getOperand[type])(value);
	return newOperand;
}

IOperand const * IOperandFactory::createInt8( std::string const & value ) const {
	printf("IOperandFactory::createInt8\n");
	(void)value;
	return NULL;
}

IOperand const * IOperandFactory::createInt16( std::string const & value ) const {
	printf("IOperandFactory::createInt16\n");
	(void)value;
	return NULL;
	
}

IOperand const * IOperandFactory::createInt32( std::string const & value ) const {
	printf("IOperandFactory::createInt32\n");
	(void)value;
	return NULL;
	
}

IOperand const * IOperandFactory::createFloat( std::string const & value ) const {
	printf("IOperandFactory::createFloat\n");
	(void)value;
	return NULL;
	
}

IOperand const * IOperandFactory::createDouble( std::string const & value ) const {
	printf("IOperandFactory::createDouble\n");
	(void)value;
	return NULL;
	
}