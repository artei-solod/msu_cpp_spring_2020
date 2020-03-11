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

