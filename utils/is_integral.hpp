/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:16:12 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/06 17:34:34 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "integral_constant.hpp"

namespace ft
{
	template <class T>
	struct is_integral : false_type
	{
	};

	template <class T>
	struct is_integral<const T> : is_integral<T>
	{
	};

	template <>
	struct is_integral<bool> : true_type
	{
	};

	template <>
	struct is_integral<char> : true_type
	{
	};

	template <>
	struct is_integral<char16_t> : true_type
	{
	};

	template <>
	struct is_integral<char32_t> : true_type
	{
	};

	template <>
	struct is_integral<wchar_t> : true_type
	{
	};

	template <>
	struct is_integral<signed char> : true_type
	{
	};

	template <>
	struct is_integral<short int> : true_type
	{
	};

	template <>
	struct is_integral<int> : true_type
	{
	};

	template <>
	struct is_integral<long int> : true_type
	{
	};

	template <>
	struct is_integral<long long int> : true_type
	{
	};

	template <>
	struct is_integral<unsigned char> : true_type
	{
	};

	template <>
	struct is_integral<unsigned short int> : true_type
	{
	};

	template <>
	struct is_integral<unsigned int> : true_type
	{
	};

	template <>
	struct is_integral<unsigned long int> : true_type
	{
	};

	template <>
	struct is_integral<unsigned long long int> : true_type
	{
	};
}

#endif