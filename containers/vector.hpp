#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>

namespace ft {

	template< class T, class Allocator = std::allocator <T> >
	class Vector
	{
		public:

//______________Member type________________________________________________
			
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename std::size_t							size_type;
		typedef typename std::ptrdiff_t							difference_type;
		typedef	T&												reference;
		typedef	const T&										const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef typename std::reverse_iterator<iterator>		reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;


//______________Constructors and destructor_________________________________ 

		// default construct empty container with default constructed allocator
		Vector<T>() 

		// fill constructor: construct a container with n lements each one is a copy of val
		explicit Vector<T>(size_type n, const T& val = T(), const Allocator& alloc = Allocator())

		// range constructor: construct a container with as many elem as the range (fist, last)
		// with each elem contuct from its corresponding elem in that range in the same order
		template <class InputIterator>  vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())


		~Vector<T>()

	
//______________Operator overload___________________________________________


//______________Members functions___________________________________________

//ITERATORS

//ELEMENT ACCES

//CAPACITY

//MODIFIERS

		private:

		Allocator	_alloc;
		size_type	_n;
		size_type	_capacity;
		value_type	_val;
		iterator	_first;

	};
}

#endif