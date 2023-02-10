/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/10 14:46:11 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include <vector>
#include <deque>
#include <stack>
#include "integral_constant.hpp"

	using namespace ft;
	
int main()
{

// std::cout << "=============================================================================" << std::endl;
// std::cout << "			test vector                                        " << std::endl;
// std::cout << "=============================================================================" << std::endl;
/*=============================================================================*/
//							test vector 's constructors
/*=============================================================================*/
	
	vector<int> first;
	std::cout << "default constructor: begin " << first.begin() << std::endl;
	// // std::cout << "default constructor: size " << first.size() << std::endl;
	// std::vector<int> second (4, 100);
	// vector<int> second (4, 100);
	// std::cout << "fill constructor : begin " <<  *second.begin() << std::endl;
	// std::cout << "fill constructor : end " <<  *(second.end() - 1) << std::endl;
	// for (size_t i = 0; i < second.size(); i++)
	// 	std::cout << *(second.begin() + i) << std::endl;
	// std::cout << "fill constructor : size " << second.size() << std::endl;
	// vector<int> third (second.begin(), second.end());
	// std::cout << "range constructor : size " << third.size() << std::endl;
	// for (size_t i = 0; i < third.size(); i++)
	// 	std::cout << *(third.begin() + i) << std::endl;

/*=============================================================================*/
//							test operator=
/*=============================================================================*/
	
	// std::cout << "operator equal overload test: " << std::endl;
	// std::vector<int> forth = second;
	// vector<int> forth = second;
	// for (size_t i = 0; i < forth.size(); i++)
	// 	std::cout << *(forth.begin() + i) << std::endl;

/*=============================================================================*/
//							test iterators et elements acces
/*=============================================================================*/
	
	vector<std::string> test_str;
	test_str.push_back("pouet");
	test_str.push_back("coucou");
	test_str.push_back("youpi");
	test_str.push_back("oley");
	std::cout << "test iterators: " << *(test_str.rbegin()) << std::endl;
	

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

// ___________________________________-pop_back:

// 	std::cout << "test pop back:" << std::endl;
// 	std::cout << "size before pop: " << second.size() << std::endl;
// 	second.pop_back();
// 	for (size_t i = 0; i < second.size(); i++)
// 		std::cout << *(second.begin() + i) << std::endl;
// 	std::cout << "size after pop: " << second.size() << std::endl;

// ___________________________________-push_back:

// 	std::cout << "test push back:" << std::endl;
// 	std::cout << "size before push: " << second.size() << std::endl;
// 	second.push_back(56);
// 	for (size_t i = 0; i < second.size(); i++)
// 		std::cout << *(second.begin() + i) << std::endl;
// 	std::cout << "size after push: " << second.size() << std::endl;

// ___________________________________-clear:

// 	std::cout << "test clear: print vector before clearing: " << std::endl;
// 	for (size_t i = 0; i < forth.size(); i++)
// 		std::cout << *(forth.begin() + i) << std::endl;
// 	forth.clear();
// 	std::cout << "clear done: can't print tab" << std::endl;
// 	for (size_t i = 0; i < forth.size(); i++)
// 		std::cout << *(forth.begin() + i) << std::endl;
// 	std::cout << "size: " << forth.size() << std::endl;
// 	std::cout << "begin is end : " <<  (forth.begin() == forth.end()) << std::endl;
	
// ___________________________________-reserve:

// 	std::cout << "test reserve:" << std::endl;
// 	std::cout << "capacity: " << forth.capacity() << std::endl;
// 	forth.reserve(100);
// 	std::cout << "capacity: " << forth.capacity() << std::endl;
// 	try
// 	{
// 		size_t msz = forth.max_size() + 100;
// 		forth.reserve(msz);
// 	}cytus  ost) << '\n';
// 	}
// 	vector<int>::size_type sz;
// 	vector<int> bar;
//  	sz = bar.capacity();
// 	bar.reserve(10);
// 	std::cout << "making bar grow:\n";
// 	for (int i=0; i<10; ++i)
// 	{
// 		bar.push_back(i);
// 		if (sz!=bar.capacity()) 
// 		{
// 	    	sz = bar.capacity();
// 	    	std::cout << "capacity changed: " << sz << '\n';
// 		}
// 	}

//_____________________________________-resize:

// std::cout << "=============================================================================" << std::endl;
// std::cout << "		test stack                                         " << std::endl;
// std::cout << "=============================================================================" << std::endl;

// // PROBLEME WITH COPY WITH ANOTHER CONTAINER !!!!!
// // ADD  FRIEND POUR LES OPERATORS STACK !!!!!

// 	stack<int> mystack;

// 	for (int i=0; i<5; ++i) mystack.push(i);
// 	std::cout << "Popping out elements...";
// 	while (!mystack.empty())
// 	{
// 	   std::cout << ' ' << mystack.top();
// 	   mystack.pop();
// 	}
// 	std::cout << '\n';

// 	mystack.push(10);
// 	mystack.push(20);
// 	mystack.top() -= 5;
// 	std::cout << "mystack.top() is after push: " << mystack.top() << '\n';

// 	stack<int> myints;
// 	std::cout << "0. empty stack size: " << myints.size() << '\n';

// 	for (int i=0; i<5; i++) myints.push(i);
// 	std::cout << "1. size after push: " << myints.size() << '\n';

// 	myints.pop();
// 	std::cout << "2. size after pop: " << myints.size() << '\n';
// 	vector<int> myvector (2,200);        // vector with 2 elements
// 	std::cout << "size of myvector: " << myvector.size() << '\n';
// 	stack<int,vector<int> > cpy (myvector);
// 	std::cout << "size of stack cpy: " << cpy.size() << '\n';
}





//__________________________________________________________________________________________________
//__________________________________________________________________________________________________


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