#include <iostream>
#include <cstdio>

using namespace std;

char* u = NULL;
size_t varSize;
size_t cur;

void makeAllocator(size_t _maximum)
{
	if (!_maximum)
		return;
	cur = 0;
	varSize = _maximum;
	u = (char*)malloc(sizeof(char) * _maximum);
	return;
}

char* alloc(size_t size)
{
	if (!u)
		return NULL;
	size_t newcur = cur + size;
	if (newcur <= varSize)
	{
		char* per = u + cur;
		cur = newcur;
		return per;
	}
	else
		return NULL;
}

void reset()
{
	cur = 0;
	varSize = 0;
	free(u);
	u = NULL;
	return;
}

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

