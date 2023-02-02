/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:45 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/02 15:24:18 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <utility>   // oiur std::move
#include <memory>   // pour std::allocator
#include <deque>

	namespace ft {

	template <class T, class Container = std::deque<T> >
	class stack 
	{
		public:
	
	//______________Member type________________________________________

		typedef Container 								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type 			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;


	//______________Constructors and destructor________________________

	// explicit stack (const container_type& ctnr = Container())
	// {
		
	// }

	// ~stack()
	// {
		
	// }

	//______________Operator overload__________________________________

	// stack &operator=( const stack& other ): c(other.c)
	// {
	// 	if (this != other)
	// 		this->c = std::move(other.c);
	// 	return *this;
	// }

	//ELEMENT ACCES____________________________________________________

	// value_type& top()
	// {
		
	// }
	
	// const value_type& top() const
	// {
		
	// }
	
	//CAPACITY_________________________________________________________

	// bool empty() const
	// {
		
	// }
	
	//size_type size() const
	// {
		
	// }

	//MOFIFIERS________________________________________________________

	// void push( const value_type& value )
	// {
		
	// }
	
	// void pop()
	// {
		// 
	// }

	
		protected:
	
		Container c;

	};

	//NON MEMBER FUNCTIONS____________________________________________________
	
	// template <class T, class Container>
	
	// bool operator==(const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
	// template <class T, class Container>
	
	// bool operator< (const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
	// template <class T, class Container>
	
	// bool operator!=(const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
	// template <class T, class Container>
	
	// bool operator> (const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
	// template <class T, class Container>
	
	// bool operator>=(const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
	// template <class T, class Container>
	
	// bool operator<=(const stack<T, Container>& x,
	
	// const stack<T, Container>& y);
	
		}

#endif