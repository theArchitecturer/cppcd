#ifndef QUERYRESULT_HPP
#define QUERYRESULT_HPP 

#include <iostream>
#include <memory>
#include <new>
#include <set>
#include <string>
#include <vector>
#include "TextQuery.hpp"

class QueryResult{
	friend std::ostream& print( std::ostream& os, const QueryResult& );
	public:
		using line_no = TextQuery::line_no;
		QueryResult(std::string s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<std::vector<std::string>> f): sought(s), line(l), file(f) { }
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> line;
		std::shared_ptr<std::vector<std::string>> file;
}; 

#endif 
