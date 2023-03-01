#include <iostream>
#include <string>
#include <vector>

#include "parse_word.h"

int main(int argn, char** args ){

	Parse_word pw("dictionary.txt");
	if (pw.is_ok()!=""){
		std::cout << pw.is_ok() << "\n";
		return 1;
	}

	std::string s = (argn>1 ? args[1] : "hello!");
			
	std::vector<Parsed_word> result = pw.parse(s);
	for (Parsed_word pw: result){
		std::cout << pw.to_string() << ",";
	}
	std::cout <<"\nsize: " << result.size() << "\n";
	std::cout <<"number of calls " << pw.count << "\n";
	return 0;
}
