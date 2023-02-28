#ifndef PARSE_WORD
#define PARSE_WORD

#include <vector>
#include <string>
#include "parsed_word.h"

class Parse_word{
		Morpheme validate(const std::string &s);
	public: 
		std::vector<Parsed_word> parse(const std::string & input);
};

#endif
