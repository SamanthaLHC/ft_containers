/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:45 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/09 16:11:58 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory> // pour std::allocator
#include <vector.hpp>
// #include "vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		//______________Member type________________________________________

		typedef Container 								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

		//______________Constructors and destructor________________________

		// à la fois costructeur par défaut et copy constructeur
		explicit stack(const container_type &ctnr = Container()): c(ctnr) {}

		stack(const stack &cpy) : c(cpy.c) {}

		~stack() {}

		//______________Operator overload__________________________________

		stack &operator=(const stack &other)
		{
			if (this != &other)
				c = other.c;
			return *this;
		}

		// ELEMENT ACCES____________________________________________________

		value_type& top()
		{
			return c.back();
		}

		const value_type& top() const
		{
			return c.back();
		}

		// CAPACITY_________________________________________________________

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return c.size();
		}

		// MOFIFIERS________________________________________________________

		void push(const value_type &value)
		{
			return c.push_back(value);
		}

		void pop()
		{
			return c.pop_back();
		}

	protected:
		Container c;
	};

	// NON MEMBER FUNCTIONS____________________________________________________

	template <class T, class Container>
	bool operator==(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x == y;
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x < y;
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x != y;
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x > y;
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x >= y;
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &x, const stack<T, Container> &y)
	{
		return x <= y;
	}
}

#endif