
#include <iostream>
#include <fstream>
#include <cassert>
#include "mysort.h"
using namespace std;
int main()
{
	{
		Timer t;
		cout << simpleMergeSort("my_data.dat") << endl;
	}
	return 0;
}
