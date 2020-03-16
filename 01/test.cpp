#include<iostream>
#include "allocator.h"
int main() {
	char* a;
	char* b;
	makeAllocator(sizeof(char) * 8);
	a = alloc(sizeof(char) * 4);
	b = alloc(sizeof(char) * 4);
	*a = 'A';
	*b = 'B';
	cout << *a << '\n';
	cout << *b << '\n';
	reset();
	if (*a != 'A') {
		cout << "reset has been done";
	}
	return 0;

}