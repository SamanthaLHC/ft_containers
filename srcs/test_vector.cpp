/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/23 11:38:45 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <list>
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

	NS::vector<int> vct;
	NS::vector<int>::iterator it = vct.begin();
	NS::vector<int>::const_iterator cit = vct.begin();
	NS::vector<int>::reverse_iterator rit(it);
	NS::vector<int>::const_reverse_iterator crit(rit);
	NS::vector<int>::const_reverse_iterator crit_(it);
	NS::vector<int>::const_reverse_iterator crit_2(cit);
	std::cout << "OK" << std::endl;

	std::list<int> lst;
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	NS::vector<int> v(lst.begin(), lst.end());
	std::cout << v.size() << std::endl;

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	v.assign(lst.begin(), lst.end());
	std::cout << v.size() << std::endl;

	v.insert(v.end(), lst.rbegin(), lst.rend());
	std::cout << v.size() << std::endl;

	const int size = 5;
	NS::vector<int> vect(size);
	NS::vector<int>::reverse_iterator iit = vect.rbegin();
	NS::vector<int>::const_reverse_iterator ite = vect.rbegin();

	for (int i = 0; i < size; ++i)
		iit[i] = (size - i) * 5;

	iit = iit + 5;
	iit = 1 + iit;
	iit = iit - 4;
	std::cout << *(iit += 2) << std::endl;
	std::cout << *(iit -= 1) << std::endl;

	*(iit -= 2) = 42;
	*(iit += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;
	std::cout << "(iit == const_it): " << (ite == iit) << std::endl;
	std::cout << "(const_ite - iit): " << (ite - iit) << std::endl;
	std::cout << "(ite + 3 == iit): " << (ite + 3 == iit) << std::endl;
	
	std::cout << vect.size() << std::endl;


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

	// // ___________________________________-push_back:

	std::cout << "test push back:" << std::endl;
	std::cout << "size before push: " << second.size() << std::endl;
	second.push_back(56);
	for (size_t i = 0; i < second.size(); i++)
		std::cout << *(second.begin() + i) << std::endl;
	std::cout << "size after push: " << second.size() << std::endl;

	NS::vector<std::string> vt(8);
	NS::vector<std::string> vt2;
	NS::vector<std::string>::iterator iter = vt.begin();

	for (unsigned long int i = 0; i < vt.size(); ++i)
		iter[i] = std::string((vt.size() - i), i + 65);
	std::cout << vt.size() << std::endl;

	std::cout << "push_back():\n" << std::endl;

	vt.push_back("One long string");
	vt2.push_back("Another long string");

	std::cout << vt.size() << std::endl;

	std::cout << vt2.size() << std::endl;

	vt.pop_back();
	vt2.pop_back();

	std::cout << vt.size() << std::endl;
	std::cout << vt2.size() << std::endl;

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
	NS::vector<int>::iterator i;

	i = insert_test.begin();
	i = insert_test.insert(i, 200);

	insert_test.insert(i, 2, 300);

	// "it" no longer valid, get a new one:
	i = insert_test.begin();

	NS::vector<int> anothervector(2, 400);
	insert_test.insert(i + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	insert_test.insert(insert_test.begin(), myarray, myarray + 3);

	std::cout << "test insert vector after insert , insertfill and insert range, contains:";
	for (i = insert_test.begin(); i < insert_test.end(); i++)
		std::cout << ' ' << *i;
	std::cout << '\n';


	NS::vector<int> vec(10);
	NS::vector<int> vec2;
	NS::vector<int>	vec3;
	
	for (unsigned long int i = 0; i < vec.size(); ++i)
		vec[i] = (vec.size() - i) * 3;
	std::cout << vec.size() << std::endl;

	vec2.insert(vec2.end(), 42);
	vec2.insert(vec2.begin(), 2, 21);
	std::cout << vec2.size() << std::endl;

	vec2.insert(vec2.end() - 2, 42);
	std::cout << vec2.size() << std::endl;

	vec2.insert(vec2.end(), 2, 84);
	std::cout << vec2.size() << std::endl;

	vec2.resize(4);
	std::cout << vec2.size() << std::endl;

	vec2.insert(vec2.begin() + 2, vec.begin(), vec.end());
	vec.clear();
	std::cout << vec2.size() << std::endl;

	std::cout << vec.size() << std::endl;

	for (int i = 0; i < 5; ++i)
		vec3.insert(vec3.end(), i);
	vec3.insert(vec3.begin() + 1, 2, 111);
	std::cout << vec3.size() << std::endl;


	

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

	// //_____________________________________-assign

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


	NS::vector<int> vct_one(7);
	NS::vector<int> vct_two(4);
	NS::vector<int> vct_three;
	NS::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct_one.size(); ++i)
		vct_one[i] = (vct_one.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	std::cout << vct_one.size() << std::endl;
	std::cout << vct_two.size() << std::endl;

	vct_three.assign(vct_one.begin(), vct_one.end());
	vct_one.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	// std::cout << "\t### After assign(): ###" << std::endl;

	std::cout << vct_one.size() << std::endl;
	std::cout << vct_two.size() << std::endl;
	std::cout << vct_three.size() << std::endl;
	std::cout << vct_four.size() << std::endl;


	vct_four.assign(6, 84);
	std::cout << vct_four.size() << std::endl;

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct_one.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	std::cout << vt.size() << std::endl;
	std::cout << vct_two.size() << std::endl;

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
