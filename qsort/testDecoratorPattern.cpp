#include <iostream>
#include <string>
using namespace std;
#include "Decorator.h"

void outResult(int cost, string description)
{
	cout << "Coffe: " << description << ", cost: " << cost << endl;
}

int main()
{
	// oreilly book implementation
	{
		// only espresso
		oreilly::Beverage *esp = new oreilly::coffe::Espresso();
		outResult(esp->cost(), esp->getDescription());

		// esspresso with double milk
		oreilly::Beverage *esp2Milk = new oreilly::coffe::Espresso();
		esp2Milk = new oreilly::added::Milk(esp2Milk);
		esp2Milk = new oreilly::added::Milk(esp2Milk);
		outResult(esp2Milk->cost(), esp2Milk->getDescription());

		// HouseBiend
		oreilly::Beverage *hbMocha = new oreilly::coffe::HouseBiend();
		hbMocha = new oreilly::added::Mocha(hbMocha);
		outResult(hbMocha->cost(), hbMocha->getDescription());
	}

	return 0;
}