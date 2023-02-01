#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>

namespace ft {

	template< class T, class Allocator = std::allocator <T> >
	class vector
	{
	//============//
		public:
	//============//

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

		// default construct: empty container with default constructed allocator
		vector()
		{

		}

		// fill constructor: construct a container with n elements each one is a copy of val
		explicit vector(size_type n, const T& val = T(), const Allocator& alloc = Allocator())
		{

		}

		// range constructor: construct a container with as many elem as the range (fist, last)
		// with each elem contuct from its corresponding elem in that range in the same order0
		template <class InputIterator>  
		vector (InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
		{

		}

		~vector()
		{

		}

//______________Operator overload___________________________________________

		vector &operator=(const &rhs)
		{
			if (this != &rhs)
			{

			}
			// array's copy to do + private attributes copy
			return *this;
		}



//______________Members functions___________________________________________

//ITERATORS_________________________________________________________________
  
		iterator begin()
		{

		}
		const_iterator begin() const
		{

		}

		iterator end()
		{

		}
		const_iterator end() const
		{

		}

  		reverse_iterator rbegin()
  		{

		}
		const_reverse_iterator rbegin() const
		{

		}

		reverse_iterator rend()
		{

		}
		const_reverse_iterator rend() const
		{

		}

//ELEMENT ACCES_____________________________________________________________

		reference operator[] (size_type n)
		{

		}
		const_reference operator[] (size_type n) const
		{

		}

		reference at (size_type n)
		{

		}

		const_reference at (size_type n) const
		{

		}

		reference front()
		{

		}

		const_reference front() const
		{
			
		}

		reference back()
		{

		}
		const_reference back() const
		{

		}

//CAPACITY__________________________________________________________________

		size_type size() const
		{

		}

		size_type max_size() const
		{

		}

		void resize (size_type n, value_type val = value_type())
		{

		}

		size_type capacity() const
		{

		}

		bool empty() const
		{

		}

		void reserve (size_type n)
		{

		}

//MODIFIERS_________________________________________________________________

		//range
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{

		}

		//fill
		void assign (size_type n, const value_type& val)
		{

		}

		void push_back (const value_type& val)
		{

		}

		void pop_back()
		{

		}

		//single elem
		iterator insert (iterator position, const value_type& val)
		{

		}
		
		//fill
		void insert (iterator position, size_type n, const value_type& val)
		{

		}

		//range
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{

		}

		iterator erase (iterator position)
		{

		}

		iterator erase (iterator first, iterator last)
		{

		}

		void swap (vector& other)
		{

		}

		void clear()
		{
			
		}

//ALLOC_____________________________________________________________________
	
		allocator_type get_allocator() const
		{
			
		}

	//============//
		private:
	//============//

		Allocator	_alloc;
		size_type	_n;
		size_type	_capacity;
		value_type	_val_type;
		iterator	_first;
		iterator	_last;
	};
}

#endif