#include <iostream>
#include <cstdio>
#include <string>
#include "parcerh.h"

void onNumberFound(std::string& n)
{
	std::cout << n << '\n';
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
	start_callback(ParceStart);
	number_callback(onNumberFound);
	word_callback(onStringFound);
	finish_callback(ParceFinish);
	
	parse("sfsd 4253/nwefdw/t3245");
	return 0;
}