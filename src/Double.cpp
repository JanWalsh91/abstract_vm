/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:39:38 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:27:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

Double::Double() {}

Double::Double(std::string value) {
	double d = std::stod(value);

	if (std::isinf(d))
		throw new OverflowException();
	else {
		this->value = std::to_string(d);
		for (int i = this->value.size() - 1; i > 0; i--) {
			if (this->value[i] == '0' && this->value[i -1] != '.')
				this->value.erase(i, 1);
			else break ;
		}
	}
}

Double::Double( Double const & d ) {
	*this = d;
}

Double::~Double() {}

class Double	&Double::operator=(Double const & rhs) {
	this->value = rhs.value;
	return *this;
}

int		Double::getPrecision() const {
	return eOperandType::Double;
}

eOperandType Double::getType( void ) const {
	return eOperandType::Double;
}

IOperand const * Double::operator+( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		double res = static_cast<double>(std::atof(this->toString().c_str())) +
			static_cast<double>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Double, std::to_string(res));
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

IOperand const * Double::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		double res = static_cast<double>(std::atof(this->toString().c_str())) -
			static_cast<double>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Double, std::to_string(res));
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

IOperand const * Double::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		double res = static_cast<double>(std::atof(this->toString().c_str())) *
			static_cast<double>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Double, std::to_string(res));
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

IOperand const * Double::operator/( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<double>(std::atof(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		double res = static_cast<double>(std::atof(this->toString().c_str())) /
			static_cast<double>(std::atof(rhs.toString().c_str()));
		if (!std::isinf(res))
			return IOperandFactory().createOperand(eOperandType::Double, std::to_string(res));
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

IOperand const * Double::operator%( IOperand const & rhs ) const {
	(void)rhs;
	throw new OperandsNotIntegersException();
}

std::string const & Double::toString( void ) const {
	return this->value;
}
