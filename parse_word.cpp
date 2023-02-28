#include "Parse_word.h"
Morpheme Parse_word::validate(const std::string & s){
	Morpheme m(s, "blah blah");
	return m;
}
std::vector<Parsed_word> Parse_word::parse(const std::string & input){
	std::vector<Parsed_word> result;
	for (int i=0; i<input.size()-1; i++){
		Morpheme validated_morpheme = validate(input.substr(0,i+1));
		//skipping faulty morphemes
		if (validated_morpheme.content == "") continue;


		std::vector<Parsed_word> tail_m = parse(input.substr(i+1));
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
	if (validated_morpheme.content != "" ) result.push_back(parsed_word);

	return result;

}


