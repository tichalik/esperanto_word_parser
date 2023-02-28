#include "Parse_word.h"
#include <iostream>
Morpheme Parse_word::validate(const std::string & s){
	Morpheme m(s, "blah blah");
	return m;
}

Parse_word::Parse_word(): p_cache({}){

}
std::vector<Parsed_word> Parse_word::partition(const std::string & input){
	this->p_cache.clear();
	for (int i=0; i<input.size(); i++){
		this->p_cache.push_back({});
	}
	std::vector<Parsed_word> result;
	partition(input, result,0);
	return result;
}

void Parse_word::partition(const std::string  input, std::vector<Parsed_word> &result, int offset){
	std::string s;
	if (!input.size()){
		Parsed_word empty_p;
		p_cache[offset].push_back(empty_p);
		
	}
	for (int i=0; i<input.size(); i++){
		s += input[i];
		Morpheme val = validate(s);
		//if it is a valid morpheme
		if(val.content != "" ){
			//first morpheme of the input
		std::cout << s <<" offfset: " << offset <<  "\n";
					//adding following morphemes
			//already in the cache
			if (this->p_cache[offset+i].size()!=0){
				std::cout << "cache content no0: " << p_cache[offset+i][0].to_string() << "\n";
			}
			//has to be computed
			else{
				std::vector<Parsed_word> tmp;
				partition(input.substr(i+1), tmp, i);
				this->p_cache[offset+i] = tmp;
			//
			
				std::cout << tmp.size() << "\n";
			}
			for (Parsed_word tmp: p_cache[offset+i]){
				Parsed_word pw;
				pw.add(val);
				pw.append_back(tmp);
				result.push_back(pw);
			}
			
		}
	}
}
