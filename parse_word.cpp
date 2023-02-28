#include "Parse_word.h"
#include <iostream>
Morpheme Parse_word::validate(const std::string & s){
	Morpheme m(s, "blah blah");
	return m;
}

//Parse_word::Parse_word(): cache({}){

//}

std::vector<Parsed_word> Parse_word::parse(const std::string & input){
	cache.clear();
	for (int i=0; i<input.size(); i++)
		cache.push_back({});

	std::cout << cache.size() << "\n";
	auto result = _parse(input,0);

	std::cout << "cache content: \n";
	for( int i=0; i<cache.size(); i++){
		std::cout << i << ". ";
		for (int j=0; j<cache[i].size(); j++){
			std::cout << cache[i][j].to_string() << "  ";
		}
		std::cout << "\n";
	}

	return result;
}

std::vector<Parsed_word> Parse_word::_parse(const std::string & input, const int cache_offset){
	std::vector<Parsed_word> result;
	for (int i=0; i<input.size()-1; i++){
		Morpheme validated_morpheme = validate(input.substr(0,i+1));
		//skipping faulty morphemes
		if (validated_morpheme.content == "") continue;


		std::vector<Parsed_word> tail_m;
		if (cache[cache_offset].size()==0){
			tail_m = _parse(input.substr(i+1),cache_offset+i+1);
		} 
		else {
			tail_m = cache[cache_offset];
		}
		for (Parsed_word parsed_word: tail_m){
	
			Parsed_word single_result;
			single_result.add(validated_morpheme);
			single_result.append_back(parsed_word);
			result.push_back(single_result);
			
		}
	}
	//when the entire string is considered
	Morpheme validated_morpheme = validate(input);
	Parsed_word parsed_word;
	parsed_word.add(validated_morpheme);
	if (validated_morpheme.content != "" ){
	       	result.push_back(parsed_word);
	}

	if (cache[cache_offset].size()==0){
		std::cout << "adding offset " << cache_offset << "\n"; 
		cache[cache_offset] = result;
	}

	return result;

}



