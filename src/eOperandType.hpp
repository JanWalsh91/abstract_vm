/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eOperandType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:47:35 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:28:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EOPERAND_TYPE
# define EOPERAND_TYPE

# include <string>

enum eOperandType { Int8, Int16, Int32, Float, Double };
const std::string eOperandTypeNames[] { "int8", "int16", "int32", "float", "double" };

#endif