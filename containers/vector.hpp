/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:18 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/21 13:30:48 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>
#include <algorithm>
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/equal.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/lexicographical_compare.hpp"

namespace ft
{

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		//============//
			public:
		//============//

		//______________Member type________________________________________________

		typedef T												value_type;
		typedef Allocator 										allocator_type;
		typedef typename std::size_t 							size_type;
		typedef typename std::ptrdiff_t 						difference_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer 				const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef typename ft::reverse_iterator<iterator> 		reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

		//______________Constructors and destructor_________________________________

		// le mot explicit permet au compilator de comprendre que le template n'est pas généré
		// à ce moment là et qu'il aura besoin d'un .hpp ds lequel il y a la def du template

		// default construct: empty container with default constructed allocator
		explicit vector(const allocator_type &alloc = Allocator()) : _alloc(alloc), _n(0), _capacity(0), _vector_array(NULL) {}

		// fill constructor: construct a container with n elements each one is a copy of val
		explicit vector(size_type n, const T &val = T(), const Allocator &alloc = Allocator()) : _alloc(alloc), _n(n), _capacity(n)
		{
			// si allocate fail: une exception est jetée (try / catch ???)
			this->_vector_array = this->_alloc.allocate(n);
			for (size_type i = 0; i < this->_n; i++)
				this->_alloc.construct(this->_vector_array + i, val);
		}

		// range constructor: construct a container with as many elem as the range (fist, last)

		//  inputiterator est un object complex, pour faire un range on a besoin d'un objet complex
		// qui permet d'acceder à de la donnée d'un autre container. on s'assure avec enable _if
		// que le type input iterator n'est pas un integral
		// si le type est invalide le code n’est juste pas généré mais la compilation se fera.

		template <class InputIterator>
		vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first,
			   InputIterator last,
			   const allocator_type &alloc = allocator_type()) : _alloc(alloc),
																 // ces variables sont const, donc modifiables uniquement à la construction
																 _n(std::distance(first, last)), _capacity(_n + 1)
		{
			this->_vector_array = this->_alloc.allocate(this->_n);
			for (size_type i = 0; i < this->_n; i++)
				this->_alloc.construct(this->_vector_array + i, *(first + i));
		}

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
					this->_alloc.destroy(this->_vector_array + i);
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

		// ITERATORS_________________________________________________________________

		iterator begin()
		{
			iterator iter(this->_vector_array);
			return iter;
		}
		const_iterator begin() const
		{
			const_iterator iter(this->_vector_array);
			return iter;
		}

		iterator end()
		{
			iterator iter(_vector_array + this->_n);
			return iter;
		}
		const_iterator end() const
		{
			const_iterator iter(_vector_array + this->_n);
			return iter;
		}

		reverse_iterator rbegin()
		{
			reverse_iterator iter(end());
			return iter;
		}
		const_reverse_iterator rbegin() const
		{
			const_reverse_iterator iter(end());
			return iter;
		}

		reverse_iterator rend()
		{
			reverse_iterator iter(begin());
			return iter;
		}
		const_reverse_iterator rend() const
		{
			const_reverse_iterator iter(begin());
			return iter;
		}

		// //ELEMENT ACCES_____________________________________________________________

		reference operator[](size_type n)
		{
			return this->_vector_array[n];
		}
		const_reference operator[](size_type n) const
		{
			return this->_vector_array[n];
		}

		reference at(size_type n)
		{
			if (n > this->_n)
				throw std::out_of_range("out of range exception");
			return (this->_vector_array[n]);
		}

		const_reference at(size_type n) const
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

		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->_n)
			{
				while (this->_n > n)
					this->pop_back();
			}
			else if (this->_n < n)
			{
				while (this->_n != n)
					this->push_back(val);
			}
			this->_n = n;
		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const
		{
			return this->_n == 0;
		}

		void reserve(size_type n)
		{
			if (n <= this->_capacity)
				return;
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			pointer tmp_arr = this->_alloc.allocate(n);
			for (size_type i = 0; i < this->_n; i++)
			{
				this->_alloc.construct(tmp_arr + i, this->_vector_array[i]);
				this->_alloc.destroy(this->_vector_array + i);
			}
			if (this->_capacity > 0)
				this->_alloc.deallocate(this->_vector_array, this->_capacity);
			this->_vector_array = tmp_arr;
			this->_capacity = n;
		}

		// //MODIFIERS_________________________________________________________________

		// 		//range
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			erase(begin(), end());
			insert(begin(), first, last);
		}

		// 		//fill
		void assign(size_type n, const value_type &val)
		{
			erase(begin(), end());
			insert(begin(), n, val);
		}

		void push_back(const value_type &val)
		{
			if (this->_capacity == 0)
				reserve(1);
			if (this->_n == this->_capacity)
				reserve(this->_n * 2);
			this->_alloc.construct(this->_vector_array + _n, val);
			this->_n++;
		}

		void pop_back()
		{
			this->_alloc.destroy(this->end() - 2);
			this->_n--;
		}

		//single elem
		iterator insert (iterator position, const value_type& val)
		{
			size_type dist = position - this->begin();
			if (this->_capacity == 0)
				reserve (1);
			if (this->_n == this->_capacity)
				reserve(this->_n * 2);
			iterator mv = this->end();
			position = this->begin() + dist;
			for (; mv != position; mv--)
			{
				this->_alloc.construct(mv, *(mv - 1));
				this->_alloc.destroy(mv - 1);
			}
			this->_alloc.construct(position, val);
			this->_n++;
			return position;
		}

		//fill
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type dist = position - this->begin();
			size_type size = this->_n + n;
			if (this->_capacity == 0)
				reserve (1);
			if (size <= this->_capacity)
				reserve(size * 2);
			iterator it = this->end();
			position = this->begin() + dist;
			iterator mv = (this->begin() - 1) + n;
			for (; it != position - 1; it--)
			{
				this->_alloc.construct(mv, *(it - 1));
				this->_alloc.destroy(it - 1);
			}
			for (; position != mv; position++)
				this->_alloc.construct(position, val);
			this->_n =+ n;
		}

		// // //range
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last)
		// {
		// 	size_type range = std::distance(first, last);
		// }

		// delete one element at the pos position
		iterator erase(iterator position)
		{
			this->_alloc.destroy(position);
			for (size_type i = 1; position + i != this->end(); i++)
				this->_alloc.construct(position + i - 1, *(position + i));
			this->_n--;
			return position;
		}

		// delete a range of element from first to last
		iterator erase(iterator first, iterator last)
		{
			size_type dist = std::distance(first, last);
			while (dist > 0)
			{
				this->erase(first);
				dist--;
			}
			this->_n -= dist;
			return first;
		}

		void swap(vector &other)
		{
			std::swap(this->_alloc, other._alloc);
			std::swap(this->_n, other._n);
			std::swap(this->_capacity, other._capacity);
			std::swap(this->_vector_array, other._vector_array);
		}

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

		Allocator _alloc;
		size_type _n;
		size_type _capacity;
		pointer _vector_array;
	};

	template <class T, class Allocator>
	bool operator==(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <class T, class Allocator>
	bool operator!=(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return !(x == y);
	}

	template <class T, class Allocator>
	bool operator<(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool operator>(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return y < x;
	}

	template <class T, class Allocator>
	bool operator>=(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return !(x < y);
	}

	template <class T, class Allocator>
	bool operator<=(const vector<bool, Allocator> &x, const vector<bool, Allocator> &y)
	{
		return !(x < y);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif