#ifndef HEADER_NS_HPP
#define HEADER_NS_HPP

#ifndef FT

#include <stack>
#include <vector>
#include <iterator>
namespace NS = std;

#else

#include "stack.hpp"
#include "vector.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/integral_constant.hpp"
namespace NS = ft;

#endif

void test_vector();
void test_stack();

#endif