#ifndef	_PARCE_H_
#define	_PARCE_H_

using ontoken = void (*)(std::string&);
using edge = void (*)();

void number_callback(ontoken callback);

void word_callback(ontoken callback);

void start_callback(edge callback);

void finish_callback(edge callback);

void parse(const std::string& str);

void identify_token(std::string& str);
#endif