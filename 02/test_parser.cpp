#include <iostream>
#include <cstdio>
#include <string>
#include "parcerh.h"

void onNumberFound(std::string& n)
{
	int res = 0;
	for (int i = 0; i < n.length(); i++)
	{
		res = res * 10 + (n[i] - '0');
	}
	std::cout << res << '\n';
	return;
}

void onStringFound(std::string& s)
{
	std::cout << s << '\n';
	return;
}

void ParceStart()
{
	std::cout << "start\n";
}

void ParceFinish()
{
	std::cout << "finish\n";
}
int main()
{
	parcing pr(onNumberFound, onStringFound, ParceStart, ParceFinish);
	pr.parce("sfsd 4253/nwefdw/t3245");
	return 0;
}