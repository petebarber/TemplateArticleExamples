#include <iostream>

bool foo();
int bar(const int n);
void baz();

int main()
{
	std::cout << "sizeof(foo()):" << sizeof(foo()) << std::endl;
	//std::cout << "sizeof(foo):" << sizeof(foo) << std::endl; // illegal
	std::cout << "sizeof(bar(16384):" << sizeof(bar(16384)) << std::endl;
	std::cout << "sizeof(bar(1):" << sizeof(bar(1)) << std::endl;
	//std::cout << "sizeof(baz()):" << sizeof(baz()) << std::endl;
}