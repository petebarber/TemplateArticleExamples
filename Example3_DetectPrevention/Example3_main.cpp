#include <iostream>
#include <vector>
#include "prevent.h"
#include "bar.h"
#include "DetectPrevention.h"

int main()
{
	//bool isPreventer = DetectPrevention<int>::Detect();
	bool isPreventer = DetectPrevention<std::vector<Bar<int>>>::Detect();

	std::cout << "isPreventer:" << isPreventer << std::endl;
}