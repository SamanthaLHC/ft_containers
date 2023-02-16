/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/16 16:32:52 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "../utils/header_ns.hpp"

void test_vector()
{

	std::cout << "=============================================================================" << std::endl;
	std::cout << "			test vector                                        " << std::endl;
	std::cout << "=============================================================================" << std::endl;
	/*=============================================================================*/
	//							test vector 's constructors
	/*=============================================================================*/

	NS::vector<int> first;
	std::cout << "default constructor: begin == end " << (first.begin() == first.end()) << std::endl;
	std::cout << "default constructor: size " << first.size() << std::endl;
	NS::vector<int> second(4, 100);
	std::cout << "fill constructor second : begin " << *second.begin() << std::endl;
	std::cout << "fill constructor second : end " << *(second.end() - 1) << std::endl;
	std::cout << "fill  construct vector content: " << std::endl;
	for (size_t i = 0; i < second.size(); i++)
		std::cout << *(second.begin() + i) << std::endl;
	std::cout << "fill constructor : size " << second.size() << std::endl;

	NS::vector<int> third(second.begin() + 1, second.end() - 1);
	std::cout << "range constructor filled with two iterators taken from second :"
			  << std::endl
			  << "size " << third.size() << std::endl;
	for (NS::vector<int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << *it << std::endl;

	NS::vector<std::string> test_str;
	test_str.push_back("pouet");
	test_str.push_back("coucou");
	test_str.push_back("youpi");
	test_str.push_back("oley");
	NS::vector<std::string> range_str(test_str.begin(), test_str.end());
	std::cout << "range constructor filled with differents values(strings) :" << std::endl;
	for (NS::vector<std::string>::iterator it = range_str.begin(); it != range_str.end(); it++)
		std::cout << *it << std::endl;

	/*=============================================================================*/
	//							test operator=
	/*=============================================================================*/

	std::cout << "operator equal overload: copy second in fourth: " << std::endl
			  << "fourth content: " << std::endl;
	NS::vector<int> forth = second;
	for (size_t i = 0; i < forth.size(); i++)
		std::cout << *(forth.begin() + i) << std::endl;

	/*=============================================================================*/
	//							test iterators
	/*=============================================================================*/
	
	std::cout << "new vector content: " << std::endl;
	for (NS::vector<std::string>::iterator it = test_str.begin(); it != test_str.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "test iterators begin(): " << *test_str.begin() << std::endl;
	std::cout << "test iterators begin() + 1: " << *(test_str.begin() + 1) << std::endl;
	std::cout << "test iterators end() - 1: " << *(test_str.end() - 1) << std::endl;
	std::cout << "test iterators rbegin: " << *(test_str.rbegin()) << std::endl;
	std::cout << "test iterators rbegin + 1: " << *(test_str.rbegin() + 1) << std::endl;
	std::cout << "test iterators rend - 1: " << *(test_str.rend() - 1) << std::endl;

	/*=============================================================================*/
	//							test element acces
	/*=============================================================================*/

	/*=============================================================================*/
	//							test capacity
	/*=============================================================================*/

	std::cout << "test size : " << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << "test max size : " << std::endl;
	std::cout << second.max_size() << std::endl;
	std::cout << "test capacity : " << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << "test empty default constructor empty bool : " << std::endl;
	std::cout << first.empty() << std::endl;
	std::cout << "test a not empty bool : " << std::endl;
	std::cout << second.empty() << std::endl;

	/*=============================================================================*/
	//							test modifier
	/*=============================================================================*/

	// ___________________________________-pop_back:

	std::cout << "test pop back:" << std::endl;
	std::cout << "size before pop: " << second.size() << std::endl;
	second.pop_back();
	for (size_t i = 0; i < second.size(); i++)
		std::cout << *(second.begin() + i) << std::endl;
	std::cout << "size after pop: " << second.size() << std::endl;

	// ___________________________________-push_back:

	std::cout << "test push back:" << std::endl;
	std::cout << "size before push: " << second.size() << std::endl;
	second.push_back(56);
	for (size_t i = 0; i < second.size(); i++)
		std::cout << *(second.begin() + i) << std::endl;
	std::cout << "size after push: " << second.size() << std::endl;

	// // ___________________________________-clear:

	std::cout << "test clear: print vector before clearing: " << std::endl;
	for (size_t i = 0; i < forth.size(); i++)
		std::cout << *(forth.begin() + i) << std::endl;
	forth.clear();
	std::cout << "clear done: can't print tab" << std::endl;
	for (size_t i = 0; i < forth.size(); i++)
		std::cout << *(forth.begin() + i) << std::endl;
	std::cout << "size: " << forth.size() << std::endl;
	std::cout << "begin is end : " << (forth.begin() == forth.end()) << std::endl;

	// // ___________________________________-reserve:

	std::cout << "test reserve:" << std::endl;
	std::cout << "capacity: " << forth.capacity() << std::endl;
	forth.reserve(100);
	std::cout << "capacity: " << forth.capacity() << std::endl;
	try
	{
		size_t msz = forth.max_size() + 100;
		forth.reserve(msz);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	NS::vector<int>::size_type sz;
	NS::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(10);
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 10; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	//_____________________________________-resize:

	NS::vector<int> resize_tst;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		resize_tst.push_back(i);

	resize_tst.resize(5);
	resize_tst.resize(8, 100);
	resize_tst.resize(12);

	std::cout << "resize_tst contains:";
	for (size_t i = 0; i < resize_tst.size(); i++)
		std::cout << ' ' << resize_tst[i];
	std::cout << '\n';
/*=============================================================================*/
	//				test relationnal operators
/*=============================================================================*/
	NS::vector<int> foo(3, 100); // three ints with a value of 100
	NS::vector<int> baar(2, 200); // two ints with a value of 200

	if (foo == baar)
		std::cout << "foo and bar are equal\n";
	// if (foo != baar)
	// 	std::cout << "foo and baar are not equal\n";
	// if (foo < baar)
	// 	std::cout << "foo is less than baar\n";
	// if (foo > baar)
	// 	std::cout << "foo is greater than baar\n";
	// if (foo <= baar)
	// 	std::cout << "foo is less than or equal to baar\n";
	// if (foo >= baar)
	// 	std::cout << "foo is greater than or equal to baar\n";
}
