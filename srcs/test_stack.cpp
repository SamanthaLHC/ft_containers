/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:31 by sle-huec          #+#    #+#             */
/*   Updated: 2023/02/15 14:52:58 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../utils/header_ns.hpp"
#include <vector>

void test_stack()
{
	std::cout << "=============================================================================" << std::endl;
	std::cout << "		test stack                                         " << std::endl;
	std::cout << "=============================================================================" << std::endl;

	NS::stack<int, std::vector<int> > mystack;

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

	NS::stack<int, std::vector<int> > myints;
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
}
