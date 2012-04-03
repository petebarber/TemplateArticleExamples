#include <iostream>
#include <vector>
#include "prevent.h"
#include "bar.h"
#include "DetectPreventionWithSFINAE.h"

int main()
{
	typedef std::vector<Bar<int>> BarInt_t;

	//const bool detectVectorOfBarInt = DetectPreventionWithSFINAE::Detect<BarInt_t>(BarInt_t());
}