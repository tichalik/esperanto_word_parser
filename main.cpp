#include <iostream>
#include <string>
#include <vector>

#include "parse_word.h"

int main(int argn, char** args ){

	Parse_word pw;

	std::string s = (argn>1 ? args[1] : "hello!");
	
	std::vector<Parsed_word> result = pw.parse(s);
	for (Parsed_word pw: result){
		std::cout << pw.to_string() << ",";
	}
	std::cout <<"\nsize: " << result.size() << "\n";
	return 0;
}
