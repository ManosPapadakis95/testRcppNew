
#pragma once

#include <Rcpp.h>
using namespace Rcpp;

namespace Str {
    bool containsSubstring(std::string str, std::string substr);
    std::string toUpperCase(std::string s);
    std::string trim(std::string s);
    bool startsWith(std::string str, std::string substr);
    bool endsWith(std::string str, std::string substr);
    std::string replaceSubstring(std::string s, std::string oldSubstr, std::string newSubstr);
    std::map<std::string, double> toTable(std::string x);
}