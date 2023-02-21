/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/21 17:12:25 by sle-huec         ###   ########.fr       */
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

	std::cout << "element access test: " << std::endl;
	std::cout << test_str[2] << std::endl;
	std::cout << test_str.at(1) << std::endl;
	std::cout << test_str.front() << std::endl;
	std::cout << test_str.back() << std::endl;

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

	// // ___________________________________-reserve:

	NS::vector<int>::size_type sz;

	NS::vector<int> fo;
	fo.reserve(5);
	sz = fo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		fo.push_back(i);
		if (sz != fo.capacity())
		{
			sz = fo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	NS::vector<int> baar;
	sz = baar.capacity();
	baar.reserve(100); // this is the only difference with foo above
	std::cout << "making baar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		baar.push_back(i);
		if (sz != baar.capacity())
		{
			sz = baar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

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

	// ___________________________________-clear:

	std::cout << "test clear: print vector before clearing: " << std::endl;
	for (size_t i = 0; i < forth.size(); i++)
		std::cout << *(forth.begin() + i) << std::endl;
	forth.clear();
	std::cout << "clear done: can't print tab" << std::endl;
	for (size_t i = 0; i < forth.size(); i++)
		std::cout << *(forth.begin() + i) << std::endl;
	std::cout << "size: " << forth.size() << std::endl;
	std::cout << "begin is end : " << (forth.begin() == forth.end()) << std::endl;

	//_____________________________________-insert:

	NS::vector<int> insert_test(3, 100);
	NS::vector<int>::iterator it;

	it = insert_test.begin();
	it = insert_test.insert(it, 200);

	insert_test.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = insert_test.begin();

	NS::vector<int> anothervector(2, 400);
	insert_test.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	insert_test.insert(insert_test.begin(), myarray, myarray + 3);

	std::cout << "test insert vector after insert , insertfill and insert range, contains:";
	for (it = insert_test.begin(); it < insert_test.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// ___________________________________-erase:

	std::cout << "creating a vector with ten ints: " << std::endl;
	NS::vector<int> erase_test;
	for (int i = 1; i <= 10; i++)
		erase_test.push_back(i);

	erase_test.erase(erase_test.begin() + 5);
	erase_test.erase(erase_test.begin(), erase_test.begin() + 3);
	std::cout << "this vector contains after erasing four elem:";
	for (unsigned i = 0; i < erase_test.size(); ++i)
		std::cout << ' ' << erase_test[i];
	std::cout << '\n';

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

	//_____________________________________-assign

	NS::vector<char> characters;
	NS::vector<int> two;
	  
	characters.assign(5, 'a');
	const std::string extra(6, 'b');
	characters.assign(extra.begin(), extra.end());
	for (NS::vector<std::string>::iterator it = range_str.begin(); it != range_str.end(); it++)
		std::cout << *it << std::endl;

	int mynts[] = {1776, 7, 4};
	two.assign(mynts, mynts + 3); // assigning from array.

	std::cout << "Size of first: " << int(characters.size()) << '\n';
	std::cout << "Size of second: " << int(two.size()) << '\n';

	/*=============================================================================*/
	//				test relationnal operators
	/*=============================================================================*/

	NS::vector<int> f(3, 100); // three ints with a value of 100
	NS::vector<int> b(2, 200); // two ints with a value of 200

	if (f == b)
		std::cout << "foo and bar are equal\n";
	if (f != b)
		std::cout << "foo and baar are not equal\n";
	if (f < b)
		std::cout << "foo is less than baar\n";
	if (f > b)
		std::cout << "foo is greater than baar\n";
	if (f <= b)
		std::cout << "foo is less than or equal to baar\n";
	if (f >= b)
		std::cout << "foo is greater than or equal to baar\n";
}
