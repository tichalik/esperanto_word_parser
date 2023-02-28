#ifndef PARSE_WORD
#define PARSE_WORD

#include <vector>
#include <string>
#include "parsed_word.h"

class Parse_word{
		std::vector<std::vector<Parsed_word>> cache;
		Morpheme validate(const std::string &s);
		std::vector<Parsed_word> _parse(const std::string & input, const int cache_offset);
	public: 
		std::vector<Parsed_word> parse(const std::string & input);
		static int count;
//	Parse_word();
};

#endif
