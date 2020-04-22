#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "TextQuery.hpp"


TextQuery::TextQuery( std::ifstream& inputFile ): file(new std::vector<std::string>){
	std::string text;
	while(getline(inputFile, text)){
		file->push_back(text);
		int lineNumber = file->size() - 1; 
		std::istringstream inputLine(text);
		std::string word;
		while(inputLine >> word){
			auto& inputLines = wm[word];
			if(!inputLines){
				inputLines.reset(new std::set<line_no>);
			}
			inputLines->insert(lineNumber);
			/* for(auto iter = inputLines->cbegin(); iter != inputLines->cend(); ++iter){ */
			/* 	std::cout << *iter; */
			/* } */
			/* std::cout << std::endl; */
		}
	}
}

