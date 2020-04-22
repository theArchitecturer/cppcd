#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP 

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <string>
/* #include "QueryResult.hpp" */

class QueryResult;
class TextQuery{
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery( std::ifstream& );
		QueryResult query( const std::string& ) const;
	private:
		std::shared_ptr<std::vector<std::string>> file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif 
