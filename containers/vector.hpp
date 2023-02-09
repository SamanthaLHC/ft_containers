/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:18 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/09 15:34:36 by sam              ###   ########.fr       */
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
		// si le type est invalide le code n’est juste pas généré mais la compilation se fera.

		// template <class InputIterator>
		// vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first,
		// 	InputIterator last,
		// 	const allocator_type& alloc = allocator_type()): _alloc(alloc),
		// 	// ces variables sont const, donc modifiables uniquement à la construction
		// 		_n(std::distance(first, last)), _capacity(_n + 1)
		// {
		// 	this->_vector_array = this->_alloc.allocate(this->_capacity);

		// 	//debug
		// 	std::cout << _n << std::endl;
		// 	std::cout << _vector_array << std::endl;
		// 	std::cout << first << std::endl;
		// 	std::cout << last << std::endl;	
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

	//______________Operator overload___________________________________________

		vector &operator=(const vector &rhs)
		{
			if (this != &rhs)
			{
				this->_alloc = rhs.get_allocator();
				this->_n = rhs.size();
				this->_capacity = rhs.capacity();

				this->_vector_array = this->_alloc.allocate(this->_n);
				for (size_type i = 0; i < this->_n; i++)
					this->_alloc.construct(this->_vector_array + i, rhs._vector_array[i]);
			}
			return *this;
		}

	//______________Members functions___________________________________________

	//ITERATORS_________________________________________________________________

		iterator begin()
		{
			return this->_vector_array;
		}
		const_iterator begin() const
		{
			return this->_vector_array;
		}

		iterator end()
		{
			return this->_vector_array + this->_n;
		}
		const_iterator end() const
		{
			return this->_vector_array + this->_n;
		}

  		reverse_iterator rbegin()
  		{
			return this->_vector_array + this->_n;
		}
		const_reverse_iterator rbegin() const
		{
			return this->_vector_array + this->_n;
		}

		reverse_iterator rend()
		{
			return this->_vector_array;
		}
		const_reverse_iterator rend() const
		{
			return this->_vector_array;
		}

// //ELEMENT ACCES_____________________________________________________________

		reference operator[] (size_type n)
		{
			return this->_vector_array[n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->_vector_array[n];
		}

		reference at (size_type n)
		{
			if (n > this->_n)
				throw std::out_of_range("out of range exception");
			return (this->_vector_array[n]);
		}

		const_reference at (size_type n) const
		{
			if (n > this->_n)
				throw std::out_of_range("out of range exception");
			return (this->_vector_array[n]);
		}

		reference front()
		{
			return *begin();
		}

		const_reference front() const
		{
			return *begin();
		}

		reference back()
		{
			return *(end() - 1);
		}
		const_reference back() const
		{
			return *(end() - 1);
		}

// //CAPACITY__________________________________________________________________

		size_type size() const
		{
			return this->_n;
		}

		size_type max_size() const
		{
			return this->_alloc.max_size();
		}

		// void resize (size_type n, value_type val = value_type())
		// {

		// }

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const
		{
			return this->_n == 0;
		}

		void reserve (size_type n)
		{
			if (n > max_size())
				throw std::length_error("length_error: vector::reserve");
			if (n > this->_capacity)
			{
				pointer tmp_arr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_n; i++)
					this->_alloc.construct(tmp_arr + i, this->_vector_array[i]);
				for (size_type i = 0; i < this->_n; i++)
				{
					if (this->_vector_array[i])
						this->_alloc.destroy(this->_vector_array + i);
				}
				this->_vector_array = tmp_arr;
			}
			this->_capacity = n;
		}

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

		void push_back (const value_type& val)
		{
			if (this->_capacity == 0)
				reserve(1);
			else
			{
				reserve(this->_n + 1);
				this->_alloc.construct(this->_vector_array + _n, val);
			}
			this->_n++;
		}

		void pop_back()
		{
			this->_alloc.destroy(this->end() - 2);
			this->_n--;
		}

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

		void clear()
		{
			if (this->_vector_array != NULL)
			{
				for (size_type i = 0; i < this->_n; i++)
				{
					if (this->_vector_array[i])
						this->_alloc.destroy(this->_vector_array + i);
				}
			}
			this->_n = 0;
		}

// //ALLOC_____________________________________________________________________

		allocator_type get_allocator() const
		{
			return allocator_type(this->_alloc);
		}

//============//
	private:
//============//

		Allocator 			_alloc;
		size_type			_n;
		size_type			_capacity;
		pointer				_vector_array;
	};

	// template <class Allocator>
	// bool operator==(const vector<bool,Allocator>& x,const vector<bool,Allocator>& y)
	// {}
}

#endif