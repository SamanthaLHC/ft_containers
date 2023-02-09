/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/09 13:45:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../containers/vector.hpp"
#include "integral_constant.hpp"

int main()
{

/*=============================================================================*/
//							test vector 's constructors
/*=============================================================================*/
	
	ft::vector<int> first;
	// std::cout << "default constructor: begin " << first.begin() << std::endl;
	// std::cout << "default constructor: size " << first.size() << std::endl;
	ft::vector<int> second (4, 100);
	// std::cout << "fill constructor : begin " <<  *second.begin() << std::endl;
	// std::cout << "fill constructor : end " <<  *(second.end() - 1) << std::endl;
	// for (size_t i = 0; i < second.size(); i++)
	// 	std::cout << *(second.begin() + i) << std::endl;
	// std::cout << "fill constructor : size " << second.size() << std::endl;
	// ft::vector<int> third (second.begin(), second.end());
	// std::cout << "range constructor : size " << third.size() << std::endl;
	// for (size_t i = 0; i < third.size(); i++)
	// 	std::cout << *(third.begin() + i) << std::endl;

/*=============================================================================*/
//							test operator=
/*=============================================================================*/
	
	// std::cout << "operator equal overload test: " << std::endl;
	ft::vector<int> forth = second;
	// for (size_t i = 0; i < forth.size(); i++)
	// 	std::cout << *(forth.begin() + i) << std::endl;

/*=============================================================================*/
//							test iterators
/*=============================================================================*/


/*=============================================================================*/
//							test capacity
/*=============================================================================*/

	// std::cout << "size : " << std::endl;
	// std::cout << second.size() << std::endl;
	// std::cout << "max size : " << std::endl;
	// std::cout << second.max_size() << std::endl;
	// std::cout << "capacity : " << std::endl;
	// std::cout << second.capacity() << std::endl;
	// std::cout << "empty default constructor empty bool : " << std::endl;
	// std::cout << first.empty() << std::endl;
	// std::cout << "not empty bool : " << std::endl;
	// std::cout << second.empty() << std::endl;

/*=============================================================================*/
//							test modifier
/*=============================================================================*/

//___________________________________-pop_back:

	// std::cout << "test pop back:" << std::endl;
	// std::cout << "size before pop: " << second.size() << std::endl;
	// second.pop_back();
	// for (size_t i = 0; i < second.size(); i++)
	// 	std::cout << *(second.begin() + i) << std::endl;
	// std::cout << "size after pop: " << second.size() << std::endl;

//___________________________________-push_back:

	std::cout << "test push back:" << std::endl;
	std::cout << "size before push: " << second.size() << std::endl;
	second.push_back(56);
	for (size_t i = 0; i < second.size(); i++)
		std::cout << *(second.begin() + i) << std::endl;
	std::cout << "size after push: " << second.size() << std::endl;

//___________________________________-clear:

//                !!!!!!!!!!!!!!!!!!!  FAIIIIILLLL

	// std::cout << "test clear: print vector before clearing: " << std::endl;
	// for (size_t i = 0; i < forth.size(); i++)
	// 	std::cout << *(forth.begin() + i) << std::endl;
	// forth.clear();
	// std::cout << "clear done: can't print tab" << std::endl;
	// for (size_t i = 0; i < forth.size(); i++)
	// 	std::cout << *(forth.begin() + i) << std::endl;
	// std::cout << "size: " << forth.size() << std::endl;
	// std::cout << "first elem: " << *forth.begin() << std::endl;

	
//___________________________________-reserve:

	// std::cout << "test reserve:" << std::endl;

//   ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//_____________________________________-resize:



}


























/*=============================================================================*/
//							main du sujet
/*=============================================================================*/


// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// else
// 	#include <map.hpp>
// 	#include <stack.hpp>
	// #include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;
	// return (0);
// }