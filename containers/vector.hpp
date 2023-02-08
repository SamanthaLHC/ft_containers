/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:18 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/08 16:29:07 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <is_integral.hpp>
#include <enable_if.hpp>
// #include "enable_if.hpp"
// #include "is_integral.hpp"

namespace ft
{

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		//============//
			public:
		//============//

		//______________Member type________________________________________________

		typedef T 												value_type;
		typedef Allocator 										allocator_type;
		typedef typename std::size_t 							size_type;
		typedef typename std::ptrdiff_t 						difference_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef typename Allocator::pointer 					pointer;
		typedef typename Allocator::const_pointer 				const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef typename std::reverse_iterator<iterator>		reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;

		//______________Constructors and destructor_________________________________

		// le mot explicit permet au compilator de comprendre que le template n'est pas généré
		// à ce moment là et qu'il aura besoin d'un .hpp ds lequel il y a la def du template

		// default construct: empty container with default constructed allocator
		vector(const allocator_type &alloc = Allocator()) : 
			_alloc(alloc), _n(0), _capacity(0), _vector_array(NULL) {}

		// fill constructor: construct a container with n elements each one is a copy of val
		vector(size_type n, const T &val = T(), const Allocator &alloc = Allocator()) : 
			_alloc(alloc), _n(n), _capacity(n)
		{
			this->_vector_array = this->_alloc.allocate(n);
			// si allocate fail: une exception est jetée (try / catch ???)
			if (_vector_array != NULL)
			{
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(this->_vector_array + i, val);
			}
		}

		// range constructor: construct a container with as many elem as the range (fist, last)
		// with each elem contuct from its corresponding elem in that range in the same order.
		//contains all the elements between first and last,
		//including the element pointed by first but not the element pointed by last.


		//  inputiterator est un object complex, pour faire un range on a besoin d'un objet complex
		// qui permet d'acceder à de la donnée d'un autre container. on s'assure avec enable _if
		// que le type input iterator n'est pas un integral

		// template <class InputIterator>
		// vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first,
		// 	InputIterator last,
		// 	const allocator_type& alloc = allocator_type()): _alloc(alloc),
		// 	// ces variables sont const, donc modifiables uniquement à la construction
		// 		_n(std::distance(first, last)), _capacity(_n + 1)
		// {
		// 	this->_vector_array = this->_alloc.allocate(this->_n);

		// 	std::cout << _n << std::endl;
		// 	std::cout << _vector_array << std::endl;
		// 	std::cout << first << std::endl;
		// 	std::cout << last << std::endl;
			
		// 	this->_vector_array = std::copy(first, last, this->_vector_array);
		// }

		vector(const vector &cpy) : _alloc(Allocator()), _n(cpy._n), _capacity(cpy._capacity), 
									_vector_array(cpy._vector_array)
		{
			*this = cpy;
		}

		~vector()
		{
			if (this->_vector_array != NULL)
			{
				for (size_type i = 0; i < this->_n; i++)
				{
					if (this->_vector_array[i])
						this->_alloc.destroy(this->_vector_array + i);
				}
				this->_alloc.deallocate(this->_vector_array, this->_n);
			}
		}

		// //______________Operator overload___________________________________________

		// 		vector &operator=(const &rhs)
		// 		{
		// 			if (this != &rhs)
		// 			{

		// 			}
		// 			// array's copy to do + private attributes copy
		// 			return *this;
		// 		}

		// //______________Members functions___________________________________________

		// //ITERATORS_________________________________________________________________

		iterator begin()
		{
			return this->_vector_array;
		}
		// 		const_iterator begin() const
		// 		{

		// 		}

		iterator end()
		{
			return this->_vector_array + this->_n;
		}
		// 		const_iterator end() const
		// 		{

		// 		}

		//   		reverse_iterator rbegin()
		//   		{

		// 		}
		// 		const_reverse_iterator rbegin() const
		// 		{

		// 		}

		// 		reverse_iterator rend()
		// 		{

		// 		}
		// 		const_reverse_iterator rend() const
		// 		{

		// 		}

		// //ELEMENT ACCES_____________________________________________________________

		// 		reference operator[] (size_type n)
		// 		{

		// 		}
		// 		const_reference operator[] (size_type n) const
		// 		{

		// 		}

		// 		reference at (size_type n)
		// 		{

		// 		}

		// 		const_reference at (size_type n) const
		// 		{

		// 		}

		// 		reference front()
		// 		{

		// 		}

		// 		const_reference front() const
		// 		{

		// 		}

		// 		reference back()
		// 		{

		// 		}
		// 		const_reference back() const
		// 		{

		// 		}

		// //CAPACITY__________________________________________________________________

		size_type size() const
		{
			return this->_n;
		}

		// 		size_type max_size() const
		// 		{

		// 		}

		// 		void resize (size_type n, value_type val = value_type())
		// 		{

		// 		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		// 		bool empty() const
		// 		{

		// 		}

		// 		void reserve (size_type n)
		// 		{

		// 		}

		// //MODIFIERS_________________________________________________________________

		// 		//range
		// 		template <class InputIterator>
		// 		void assign (InputIterator first, InputIterator last)
		// 		{

		// 		}

		// 		//fill
		// 		void assign (size_type n, const value_type& val)
		// 		{

		// 		}

		// 		void push_back (const value_type& val)
		// 		{

		// 		}

		// 		void pop_back()
		// 		{

		// 		}

		// 		//single elem
		// 		iterator insert (iterator position, const value_type& val)
		// 		{

		// 		}

		// 		//fill
		// 		void insert (iterator position, size_type n, const value_type& val)
		// 		{

		// 		}

		// 		//range
		// 		template <class InputIterator>
		// 		void insert (iterator position, InputIterator first, InputIterator last)
		// 		{

		// 		}

		// 		iterator erase (iterator position)
		// 		{

		// 		}

		// 		iterator erase (iterator first, iterator last)
		// 		{

		// 		}

		// 		void swap (vector& other)
		// 		{

		// 		}

		// 		void clear()
		// 		{

		// 		}

		// //ALLOC_____________________________________________________________________

		// 		allocator_type get_allocator() const
		// 		{

		// 		}

		//============//
	private:
		//============//

		Allocator 			_alloc;
		size_type const 	_n;
		size_type const 	_capacity;
		pointer				_vector_array;
	};

	// template <class Allocator>
	// bool operator==(const vector<bool,Allocator>& x,const vector<bool,Allocator>& y)
	// {}
}

#endif