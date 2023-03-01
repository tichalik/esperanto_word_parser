#ifndef PARSE_WORD
#define PARSE_WORD

#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "parsed_word.h"

class Parse_word{
		std::unordered_map<std::string, std::string> dictionary;
		std::string error;
		std::vector<std::vector<Parsed_word>> cache;
		Morpheme validate(const std::string &s);
		std::vector<Parsed_word> _parse(const std::string & input, const int cache_offset);
	public: 
		std::vector<Parsed_word> parse(const std::string & input);
		static int count;
		Parse_word(const std::string & path_to_dictionary);
		std::string is_ok();
};

#endif
