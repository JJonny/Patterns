#include <iostream>
using namespace std;
#include "Decorator.h"

int main()
{
	
	int f1 = 3, f2 = 2, f3 = 6;
	//standart::Decorator2 d2(new standart::Decorator1(new standart::Component(f1), f2), f3);
	//d2.cost();

	
	{
		int borderSize = 30;
		int scrollToValue = 5;

		book::Window *w = new book::Window;
		book::TextView *tv = new book::TextView;		

		w->setContent(new book::BorderDecorator(new book::ScrollDecorator(tv, scrollToValue), borderSize));
		w->draw();
		int i = 0;

	}
	

	return 0;
}