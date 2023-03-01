#include "parsed_word.h"
#include <iostream>
void Parsed_word::add(const Morpheme &m){
	morphemes.push_back(m);
}


void Parsed_word::append_back(const Parsed_word & pw){
	for (Morpheme m: pw.morphemes){
		morphemes.push_back(m);
	}
}

std::string Parsed_word::to_string(){
	std::string result;
	for (Morpheme m: morphemes){
		std::string s =  m.content + " " + m.description; 
		std::cout << s << "\n";
		s +=std::string(" ");

		std::cout << s << "\n";
		s += std::string("a");

		std::cout << s << "\n";
		s += std::string(" ");

		result +="-"+ m.content;
	}
	if(result.size())
		result = result.substr(1);
	return result;
}
int Parsed_word::get_count(){
	return morphemes.size();
}
