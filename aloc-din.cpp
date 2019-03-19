#include <iostream>
#include <stdio.h>

using namespace std;

int main ()
{
	int *n;

	n = new int;

	printf("%p\n", n);
		
	*n = 30;
	
	cout << *n << endl;
	
	delete n;
	
	return 0;
}
