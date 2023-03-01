#include "Parse_word.h"
#include <iostream>
Morpheme Parse_word::validate(const std::string & s){
	Morpheme m;
	if (dic.contains(s)){
		m.content = s;
		m.description = dic[s];
	}
	return m;
}

Parse_word::Parse_word(const std::string & ptd): cache({}){
	std::ifstream file(ptd);
	if(file){
		std::string line;
		std::string head;
		int pos =0;
		int linecount = 0;
		while( std::getline(file, line)){
			linecount++;
			pos = line.find(" ");
			if (pos == std::string::npos){
				error = "invalid file format at line " + linecount;
				return;
			}
			dic[line.substr(0, pos)] = line.substr(pos+1);
		}
	}
	else{
		error = "cannot open file " + ptd;
		return;
	}

}
std::string Parse_word::is_ok(){
	return error;
}

std::vector<Parsed_word> Parse_word::parse(const std::string & input){
	cache.clear();
	for (int i=0; i<input.size(); i++)
		cache.push_back({});

	auto result = _parse(input,0);

	return result;
}

int Parse_word::count = 0;

std::vector<Parsed_word> Parse_word::_parse(const std::string & input, const int cache_offset){
	count ++;
	std::vector<Parsed_word> result;
	for (int i=0; i<input.size()-1; i++){
		Morpheme validated_morpheme = validate(input.substr(0,i+1));
		//skipping faulty morphemes
		if (validated_morpheme.content == "") continue;


		std::vector<Parsed_word> tail_m ;
	        if (cache[cache_offset].size()==0){
	       	        tail_m = _parse(input.substr(i+1),cache_offset+i+1);
		}
		else{
			tail_m = cache[cache_offset+i+1];
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
		cache[cache_offset] = result;
	}

	return result;

}



