/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:15:08 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/10 16:57:55 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
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

		reverse_iterator(){}
		explicit reverse_iterator( iterator_type x ){}
		
		//______________overload operator_________________________________

		template <class U> 
		reverse_iterator &operator=(const reverse_iterator<U>& other)
		{
			//stuff todo here
			return *this;
		}

		//______________members functions_________________________________

		//access the underlying iterator
		iterator_type base() const
		{
			
		}
		
		//access element pointed to
		reference operator*() const
		{

		}

		//access element pointed to
		pointer operator->() const
		{
			
		}

		// advances and decrements the iterator
		reverse_iterator& operator++()
		{

		}

		reverse_iterator operator++(int)
		{

		}
		
		reverse_iterator& operator--()
		{
			
		}
		
		reverse_iterator operator--(int)
		{

		}
		
		reverse_iterator operator+ (difference_type n) const
		{
			
		}
		
		reverse_iterator& operator+=(difference_type n)
		{

		}
		
		reverse_iterator operator- (difference_type n) const
		{

		}
		
		reverse_iterator& operator-=(difference_type n)
		{
			
		}
		
		reference operator[](difference_type n) const
		{
			
		}
	};

	// compares underlying iterators
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	bool operator>=( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		
	}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
	{

	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(	typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x)
	{
		
	}
}

#endif