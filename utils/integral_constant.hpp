/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:47 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/06 16:01:00 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP

namespace ft
{
	template <typename T, T val>
	struct integral_constant
	{
		const static T value = val;
		typedef T 							value_type;
		typedef integral_constant<T, val> 	type;
		value_type							operator()()
		{
			return value;
		}
	};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
}

#endif