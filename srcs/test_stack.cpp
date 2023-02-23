/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/23 13:06:10 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "../utils/header_ns.hpp"


template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void test_stack()
{
	std::cout << "=============================================================================" << std::endl;
	std::cout << "		test stack                                         " << std::endl;
	std::cout << "=============================================================================" << std::endl;

	NS::stack<int> mystack;

	std::cout << "elements in stack: " << std::endl;
	for (int i = 0; i < 5; ++i)
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

	NS::stack<int> myints;
	std::cout << "0. empty stack size: " << myints.size() << '\n';

	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << "1. size after push: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size after pop: " << myints.size() << '\n';
	NS::vector<int> myvector(2, 200); // vector with 2 elements
	std::cout << "size of myvector: " << myvector.size() << '\n';
	NS::stack<int, NS::vector<int> > cpy(myvector);
	std::cout << "size of stack cpy: " << cpy.size() << '\n';
	std::cout << "testing non member operator overload: " << std::endl;
	if (mystack == myints)
		std::cout << "stacks are equal" << std::endl;
	else
		std::cout << "stacks not equal" << std::endl;
	if (mystack != myints)
		std::cout << "stacks are not equal" << std::endl;
	if (mystack < myints)
		std::cout << "mystack less than myints" << std::endl;
	else
		std::cout << "not less than myints" << std::endl;
	if (mystack > myints)
		std::cout << "mystack biggest than myints" << std::endl;
	else
		std::cout << "not biggest" << std::endl;
	if (mystack <= myints)
		std::cout << "mystack are less or equal than myints" << std::endl;
	else
		std::cout << "mystacks not less or equal than myints" << std::endl;
	if (mystack >= myints)
		std::cout << "mystack are biggest or equal than myints" << std::endl;
	else
		std::cout << "mystack not biggest or equal than myints" << std::endl;


	NS::vector<int>	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	NS::stack<int, NS::vector<int> >	stck(ctnr);
	NS::stack<int, NS::vector<int> >	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7

}
