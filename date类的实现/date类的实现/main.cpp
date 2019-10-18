#include"date.h"
#include<stdlib.h>
int main()
{
	Date a(1988,7,29);
	Date b,c;
	b = a + 67;
	b.print();
	cout << b - a << endl;
	b=b- 67;
	b.print();
	++b;
	b.print();
	b++;
	b.print();
	cout << (b > a)<<endl;
	cout << (b ==a) << endl;
	system("pause");
	return 0;
}