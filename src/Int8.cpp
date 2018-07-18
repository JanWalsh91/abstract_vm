/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:53:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/17 17:14:37 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

Int8::Int8() {}

Int8::Int8(std::string value) {
	try {
		long i = std::stol(value);
		if (std::numeric_limits<char>::min() <= i && i <= std::numeric_limits<char>::max())
			this->value = value;
		else throw OverflowException();
	} catch (...) {
		throw OverflowException();
	}
}

Int8::Int8( Int8 const & int8 ) {
	*this = int8;
}

Int8::~Int8() {}

class Int8	&Int8::operator=(Int8 const & rhs) {
	this->value = rhs.value;
	return *this;
}

int		Int8::getPrecision() const {
	return eOperandType::Int8;
}

eOperandType Int8::getType( void ) const {
	return eOperandType::Int8;
}

IOperand const * Int8::operator+( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) +
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<char>::min() <= res && res <= std::numeric_limits<char>::max())
			return IOperandFactory().createOperand(eOperandType::Int8, std::to_string(res));
		throw OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 + *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int8::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) -
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<char>::min() <= res && res <= std::numeric_limits<char>::max())
			return IOperandFactory().createOperand(eOperandType::Int8, std::to_string(res));
		throw OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 - *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int8::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) *
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<char>::min() <= res && res <= std::numeric_limits<char>::max())
			return IOperandFactory().createOperand(eOperandType::Int8, std::to_string(res));
		throw OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 * *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int8::operator/( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw DivideByZeroException(this, &rhs);
		long res = static_cast<long>(std::atol(this->toString().c_str())) /
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<char>::min() <= res && res <= std::numeric_limits<char>::max())
			return IOperandFactory().createOperand(eOperandType::Int8, std::to_string(res));
		throw OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 / *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int8::operator%( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw DivideByZeroException(this, &rhs);
		long res = static_cast<long>(std::atol(this->toString().c_str())) %
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<char>::min() <= res && res <= std::numeric_limits<char>::max())
			return IOperandFactory().createOperand(eOperandType::Int8, std::to_string(res));
		throw OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 % *o2;
	delete o1;
	delete o2;
	return result;
}

std::string const & Int8::toString( void ) const {
	return this->value;
}
