#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "TextQuery.hpp"
#include "QueryResult.hpp"

void find_text(std::ifstream& infile){
	TextQuery in(infile);
	while (true) {
		std::cout << "Enter word to look for, or q for quit" << std::endl;
		std::string input_command;
		if(!(std::cin >> input_command) || (input_command == "q")) break;
		print(std::cout, in.query(input_command)) << std::endl;
	}
}

int main(){
	std::ifstream inputFile("./input_file.txt");
	find_text(inputFile);
	
	return 0;
}
