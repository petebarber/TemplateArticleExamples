#include <vector>
#include "foo.h"
#include "bar.h"

class Dummy {};

/*
void OtherUsesOfBar()
{
	std::vector<Bar<int*>> vecOfBarIntPtr;
	std::vector<Bar<Dummy>> vecOfBarDummy;
	std::vector<Bar<const Dummy*>> vecOfBarDummyConstPtr;
}
*/

int main()
{
	//std::vector<Foo> vecOfFoo;
	//std::vector<Bar<int>> vecOfBar;
	//std::vector<Bar<int>, std::allocator<Bar<char>>> vecOfBar;
}