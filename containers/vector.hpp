#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>

namespace ft {

	template< class T, class Allocator = std::allocator <T> >
	class Vector
	{
		public:

//______________Member type________________________________________________
			
			typedef T								value_type;
			typedef Allocator						allocator_type;
			typedef typename std::size_t			size_type;
			typedef typename std::ptrdiff_t			difference_type;
			typedef typename Allocator::pointer		pointer;

//______________Constructors and destructor_________________________________
		Vector<T>() : 
	
//______________Operator overload___________________________________________


//______________Members functions___________________________________________

//ITERATORS

//ELEMENT ACCES

//CAPACITY

//MODIFIERS

		private:

	}
}

#endif