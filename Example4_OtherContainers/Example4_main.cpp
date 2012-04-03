#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include "prevent.h"
#include "foo.h"
#include "bar.h"
#include "DetectPrevention.h"

using namespace std;

template<template<typename, typename> class CONT>
bool TestSimpleContainer()
{
  const bool detectFoo	=
    DetectPrevention<CONT<Foo, allocator<Foo>>>::Detect();

  const bool detectBarT	= 
    DetectPrevention<CONT<Bar<int>, allocator<Bar<int>>>>::Detect();

  return detectFoo && detectBarT;
}

template<template<typename, typename, typename, typename> class MAP>
bool TestMap()
{
  typedef int Placeholder_t;

  typedef MAP<Foo, Placeholder_t, less<Foo>, 
	          allocator<pair<Foo, Placeholder_t>>> FooAsKey_t;

  typedef MAP<Placeholder_t, Foo, less<Placeholder_t>,
              allocator<pair<Placeholder_t, Foo>>> FooAsValue_t;

  typedef MAP<Foo, Foo, less<Foo>, 
              allocator<pair<Foo, Foo>>> FooAsKeyAndValue_t;

  const bool detectFooAsKey =
    DetectPrevention<FooAsKey_t>::Detect();

  const bool detectFooAsValue =
    DetectPrevention<FooAsValue_t>::Detect();

  const bool detectFooAsKeyAndValue =
    DetectPrevention<FooAsKeyAndValue_t>::Detect();

  // Bar<int>

  typedef MAP<Bar<int>, Placeholder_t, less<Bar<int>>,
              allocator<pair<Bar<int>, Placeholder_t>>> BarAsKey_t;

  typedef MAP<Placeholder_t, Bar<int>, less<Placeholder_t>, 
              allocator<pair<Placeholder_t, Bar<int>>>> BarAsValue_t;

  typedef MAP<Bar<int>, Bar<int>, less<Bar<int>>, 
              allocator<pair<Bar<int>, Bar<int>>>> BarAsKeyAndValue_t;

  const bool detectBarAsKey =
    DetectPrevention<BarAsKey_t>::Detect();

  const bool detectBarAsValue =
    DetectPrevention<BarAsValue_t>::Detect();

  const bool detectBarAsKeyAndValue =
    DetectPrevention<BarAsKeyAndValue_t>::Detect();

  return detectFooAsKey			&&
         detectFooAsValue		&&
         detectFooAsKeyAndValue	&&
         detectBarAsKey			&& 
         detectBarAsValue		&& 
        detectBarAsKeyAndValue;
}

int main()
{
  cout << "vector:" << TestSimpleContainer<vector>() << endl;
  cout << "deque:" << TestSimpleContainer<deque>() << endl;
  cout << "list:" << TestSimpleContainer<list>() << endl;

  cout << "map:" << TestMap<map>() << endl;
  cout << "multimap:" << TestMap<multimap>() << endl;
}