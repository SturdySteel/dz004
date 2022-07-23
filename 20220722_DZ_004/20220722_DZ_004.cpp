#include <iostream>
#include "Array.h"
#include <time.h>

int main()
{
	srand(time(0));
	rand();

	Array<int> a{10};
	a.set();
	a.print();

	Array<int> b = a;
	a.addElem(345, 3);
	a.print();
	a.delElem(5);
	a.findElem(9);
	a.print();
	a.sortArrInc();
	a.print();
	
	b.print();
	b.sortArrDec();
	b.print();
	cout << "\n";
	a.print();
	cout << a[2] << "\n";
	a.print();
	cout << "\n";
	(a + b).print();
	
	return 0;
}