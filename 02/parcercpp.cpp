#include <iostream>
#include <cstdio>
#include <string>
#include "parcerh.h"


parcing::parcing(ontoken n, ontoken s, edge st, edge fi)
{
    callbacknum = n;
    callbackstr = s;
    start = st;
    finish = fi;
}

void parcing::identify_token(std::string& token)
{
	char c = token[0];
	if (c >= '0' && c <= '9') callbacknum(token);
	else callbackstr(token);
}

void parcing::parce(const std::string& text)
{
    size_t pos_1 = 0;
    size_t found;
    std::string token;
    start();

    while ((found = text.find_first_of(" \n\t", pos_1)) != std::string::npos) {
        token = text.substr(pos_1, found);
        identify_token(token);
        pos_1 = found + 1;
    }
    finish();
}