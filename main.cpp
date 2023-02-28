#include <iostream>
#include <string>
#include <vector>

#include "parse_word.h"

int main(){

	Parse_word pw;

	std::string s = "tak";
	std::vector<Parsed_word> result = pw.partition(s);
	for (Parsed_word pw: result){
		std::cout << pw.to_string() << ",";
	}
	std::cout <<"\nsize: " << result.size() << "\n";
	return 0;
}
