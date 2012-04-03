#pragma once

#include <map>
#include <list>
#include <deque>
#include <vector>

// Forward declarations
class Foo;
template<typename> class Bar;

//
// Prevent use of simple contains for Foo and Bar<>
//
template<typename A> class std::vector<Foo, A>
{
private:
	vector();

public:
	typedef std::vector<Foo, A> self_t;
};

template<typename T, typename A> class std::vector<Bar<T>, A>
{
private:
	vector();

public:
	typedef std::vector<Bar<T>, A> self_t;
};

template<typename A> class std::deque<Foo, A>
{
private:
	deque();

public:
	typedef std::deque<Foo, A> self_t;
};

template<typename T, typename A> class std::deque<Bar<T>, A>
{
private:
	deque();

public:
	typedef std::deque<Bar<T>, A> self_t;
};

template<typename A> class std::list<Foo, A>
{
private:
	list();

public:
	typedef std::list<Foo, A> self_t;
};

template<typename T, typename A> class std::list<Bar<T>, A>
{
private:
	list();

public:
	typedef std::list<Bar<T>, A> self_t;
};

//
// Prevent the use of map with Foo
//
template<typename T1, typename T2, typename T3>
class std::map<Foo, T1, T2, T3>
{
private:
	map();

public:
	typedef std::map<Foo, T1, T2, T3> self_t;
};

template<typename T, typename T2, typename T3>
class std::map<T, Foo, T2, T3>
{
private:
	map();

public:
	typedef std::map<T, Foo, T2, T3> self_t;
};

template<typename T2, typename T3> 
class std::map<Foo, Foo, T2, T3>
{
private:
	map();

public:
	typedef std::map<Foo, Foo, T2, T3> self_t;
};

//
// Prevent the use of map with Bar<>
//
template<typename T, typename T1, typename T2, typename T3>
class std::map<Bar<T>, T1, T2, T3>
{
private:
	map();

public:
	typedef std::map<Bar<T>, T1, T2, T3> self_t;
};

template<typename T, typename T1, typename T2, typename T3>
class std::map<T, Bar<T1>, T2, T3>
{
private:
	map();

public:
	typedef std::map<T, Bar<T1>, T2, T3> self_t;
};

template<typename T, typename T1, typename T2, typename T3> 
class std::map<Bar<T>, Bar<T1>, T2, T3>
{
private:
	map();

public:
	typedef std::map<Bar<T>, Bar<T1>, T2, T3> self_t;
};