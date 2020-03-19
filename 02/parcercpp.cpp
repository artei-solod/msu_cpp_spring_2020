#include <iostream>
#include <cstdio>
#include <string>
#include "parcerh.h"

void number_callback(ontoken callback) {
    callbacknum = callback;
}

void word_callback(ontoken callback) {
    callbackstr = callback;
}

void start_callback(edge callback) {
    start = callback;
}

void finish_callback(edge callback) {
    finish = callback;
}

void identify_token(std::string& token)
{
	char c = token[0];
	if (c >= '0' && c <= '9') callbacknum(token);
	else callbackstr(token);
}

void parse(const std::string& text)
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