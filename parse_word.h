#ifndef PARSE_WORD
#define PARSE_WORD

#include <vector>
#include <string>
#include "parsed_word.h"

class Parse_word
{
	std::vector<std::vector<Parsed_word>> p_cache;
	Morpheme validate(const std::string & s);
	void partition(const std::string  input, std::vector<Parsed_word> &result, int offset);
	public:
	std::vector<Parsed_word> partition(const std::string & input);
		Parse_word();
};

#endif
