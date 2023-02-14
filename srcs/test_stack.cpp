/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:14 by sam              ###   ########.fr       */
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
std::cout << "=============================================================================" << std::endl;
std::cout << "		test stack                                         " << std::endl;
std::cout << "=============================================================================" << std::endl;

// // PROBLEME WITH COPY WITH ANOTHER CONTAINER !!!!!
// // ADD  FRIEND POUR LES OPERATORS STACK !!!!!

	stack<int> mystack;

	std::cout << "elements in stack: " << std::endl;
	for (int i=0; i<5; ++i)
	{
		mystack.push(i);
		std::cout << mystack.top();
	} 
	std::cout << std::endl;
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
	   std::cout << ' ' << mystack.top();
	   mystack.pop();
	}
	std::cout << '\n';

	mystack.push(10);
	mystack.push(20);
	mystack.top() -= 5;
	std::cout << "mystack.top() after push: " << mystack.top() << '\n';

	stack<int> myints;
	std::cout << "0. empty stack size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size after push: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size after pop: " << myints.size() << '\n';
	vector<int> myvector (2,200);        // vector with 2 elements
	std::cout << "size of myvector: " << myvector.size() << '\n';
	stack<int,vector<int> > cpy (myvector);
	std::cout << "size of stack cpy: " << cpy.size() << '\n';
	std::cout << "testing non member operator overload: " << std::endl;
	if ( mystack == myints)
		std::cout << "stacks are equal" << std::endl;
	else
		std::cout << "stacks not equal" << std::endl;
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