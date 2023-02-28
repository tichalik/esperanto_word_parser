#ifndef PARSED_WORD
#define PARSED_WORD

#include <string>
#include <vector>

struct Morpheme{
	std::string content;
	std::string description;
};


class Parsed_word{
	std::vector<Morpheme> morphemes;
	public:
	void add(const Morpheme &m);
	void append_back(const Parsed_word & pw);
	std::string to_string();
	int get_count();
};

#endif
