/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:15:08 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/13 17:59:20 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public std::iterator<typename iterator_traits<Iterator>::iterator_category,
												  typename iterator_traits<Iterator>::value_type,
												  typename iterator_traits<Iterator>::difference_type,
												  typename iterator_traits<Iterator>::pointer,
												  typename iterator_traits<Iterator>::reference>
	{
	protected:
		//objet membre
		Iterator current;

	public:

		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		//______________Constructors and destructor_________________________________

		reverse_iterator() : current()
		{	
		}
		
		explicit reverse_iterator( iterator_type x ): current(x)
		{
		}
		
		//______________overload operator_________________________________

		template <class U> 
		reverse_iterator &operator=(const reverse_iterator<U>& other)
		{
			this->current = other.current;
		}

		//______________members functions_________________________________

		//access the underlying iterator
		iterator_type base() const
		{
			return this->current;
		}
		
		//access element pointed to: return a reference
		reference operator*() const
		{
			Iterator tmp = this->current;
			return *--tmp;
		}

		//access element pointed to: return a ptr to the elem pointed to by the iter
		pointer operator->() const
		{
			return &(operator*());
		}

		// advances and decrements the iterator
		reverse_iterator& operator++()
		{
			--current;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}
		
		reverse_iterator& operator--()
		{
			++current;
			return *this;
		}
		
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++current;
			return tmp;
		}
		
		reverse_iterator operator+ (difference_type n) const
		{
			return reverse_iterator(this->current-n);
		}
		
		reverse_iterator& operator+=(difference_type n)
		{
			this->current -= n;
			return *this;
		}
		
		reverse_iterator operator- (difference_type n) const
		{
			return reverse_iterator(this->current+n);
		}
		
		reverse_iterator& operator-=(difference_type n)
		{
			this->current+=n;
			return *this;
		}
		
		reference operator[](difference_type n) const
		{
			return this->current[-n-1];
		}
	};

	// compares underlying iterators
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current == y.current;
	}
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current > y.current;
	}
	
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current != y.current;
	}
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current < y.current;
	}
	
	template <class Iterator>
	bool operator>=( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current <= y.current;
	}
	
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.current >= y.current;
	}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
	{
		return x.current - y.current;
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(	typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x)
	{
		return reverse_iterator<Iterator> (x.current - n);
	}
}

#endif