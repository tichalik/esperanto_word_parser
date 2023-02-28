#include "Parse_word.h"
#include <iostream>
Morpheme Parse_word::validate(const std::string & s){
	Morpheme m(s, "blah blah");
	return m;
}
std::vector<Parsed_word> Parse_word::parse(const std::string & input){
	std::vector<Parsed_word> result;
	for (int i=0; i<input.size()-1; i++){
		Morpheme vm = validate(input.substr(0,i+1));
		std::cout << "morpheme: " << vm.content << "\n";
		std::cout << "remaining: " << input.substr(i+1) << "\n";
		//skipping faulty morphemes
		if (vm.content == "") continue;


		std::vector<Parsed_word> tail_m = parse(input.substr(i+1));
		for (Parsed_word pw: tail_m){
	
			Parsed_word wr;
			wr.add(vm);
			std::cout << wr.to_string() << " result before adding tail\n";
			wr.append_back(pw);
			result.push_back(wr);
			
			std::cout << wr.to_string() <<" result\n";
		}
	}
	//when the entire string is considered
	Morpheme vm = validate(input);
	Parsed_word pw;
	pw.add(vm);
	std::cout << "adding single morpheme" << pw.to_string() << "\n";
	if (vm.content != "" ) result.push_back(pw);

	return result;

}


