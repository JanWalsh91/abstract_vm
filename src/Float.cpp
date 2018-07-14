/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:00:56 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:26:00 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

Float::Float() {}

Float::Float(std::string value) {
	float f = std::stod(value);

	if (std::isinf(f))
		throw new OverflowException();
	else {
		this->value = std::to_string(f);
		for (int i = this->value.size() - 1; i > 0; i--) {
			if (this->value[i] == '0' && this->value[i -1] != '.')
				this->value.erase(i, 1);
			else break ;
		}
	}
}

Float::Float( Float const & f ) {
	*this = f;
}

Float::~Float() {}

class Float	&Float::operator=(Float const & rhs) {
	this->value = rhs.value;
	return *this;
}

int		Float::getPrecision() const {
	return eOperandType::Float;
}

eOperandType Float::getType( void ) const {
	return eOperandType::Float;
}

IOperand const * Float::operator+( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		float res = static_cast<float>(std::atof(this->toString().c_str())) +
			static_cast<float>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Float, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 + *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Float::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		float res = static_cast<float>(std::atof(this->toString().c_str())) -
			static_cast<float>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Float, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 - *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Float::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		float res = static_cast<float>(std::atof(this->toString().c_str())) *
			static_cast<float>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Float, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 * *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Float::operator/( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<float>(std::atof(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		float res = static_cast<float>(std::atof(this->toString().c_str())) /
			static_cast<float>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Float, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 / *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Float::operator%( IOperand const & rhs ) const {
	(void)rhs;
	throw new OperandsNotIntegersException();
}

std::string const & Float::toString( void ) const {
	return this->value;
}
