#ifndef	_PARCE_H_
#define	_PARCE_H_

using ontoken = void (*)(std::string&);
using edge = void (*)();

class parcing
{
	ontoken callbacknum;
	ontoken callbackstr;
	edge start;
	edge finish;
public:
	parcing(ontoken, ontoken, edge, edge);
	void identify_token(std::string&);
	void parce(const std::string& );
};
#endif