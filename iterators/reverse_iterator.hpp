/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:15:08 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/23 11:28:38 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public 
		std::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
					  typename ft::iterator_traits<Iterator>::value_type,
					  typename ft::iterator_traits<Iterator>::difference_type,
					  typename ft::iterator_traits<Iterator>::pointer,
					  typename ft::iterator_traits<Iterator>::reference>
	{
	protected:
		//objet membre
		Iterator current;

	public:

		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		//______________Constructors and destructor_________________________________

		reverse_iterator() : current()
		{	
		}
		
		explicit reverse_iterator( iterator_type x ): current(x)
		{
		}
		
		template <class U> 
		reverse_iterator(const reverse_iterator<U>& u)
		{
			current = u.base();
		}
		
		
		//______________overload operator_________________________________

		template <class U> 
		reverse_iterator &operator=(const reverse_iterator<U>& other)
		{
			this->current = other.base();
			return *this;
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


//__________________________________________FRIENDSHIP


	// template <class Iterator_type>
	// friend bool operator==(const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend bool operator<(const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend bool operator!=(const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend bool operator>(const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend bool operator>=( const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend bool operator<=(const reverse_iterator<Iterator_type>& x, const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend typename reverse_iterator<Iterator_type>::difference_type operator-(const reverse_iterator<Iterator_type>& x,
	// 	const reverse_iterator<Iterator_type>& y);
	
	// template <class Iterator_type>
	// friend reverse_iterator<Iterator_type> operator+(	typename reverse_iterator<Iterator_type>::difference_type n,
	// 	const reverse_iterator<Iterator_type>& x);
	
	};

	// compares underlying iterators
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() == y.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() > y.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() != y.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() < y.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool operator>=( const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() <= y.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() >= y.base();
	}
	
	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y)
	{
		return y.base() - x.base();
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(	typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x)
	{
		return reverse_iterator<Iterator> (x.base() - n);
	}
}

#endif