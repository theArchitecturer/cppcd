#include "QueryResult.hpp"
#include <fstream>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>


std::string make_plural(std::size_t t, const std::string& begin, const std::string& end){
	return (t>1) ? begin+end : begin;
}

std::ostream& print(std::ostream& os, const QueryResult& qr){
	os << qr.sought << "occurs" << qr.line->size() << " " << make_plural(qr.line->size(), "time", "s") << std::endl;
	for(auto num : *qr.line){
		os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

QueryResult TextQuery::query(const std::string& sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end()){
		return QueryResult(sought, nodata, file);
	}else{
		return QueryResult(sought, loc->second, file);
	}
}
