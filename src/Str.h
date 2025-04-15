
#pragma once

#include <Rcpp.h>
using namespace Rcpp;

namespace Str {
    std::string replaceSubstring(std::string s, std::string oldSubstr, std::string newSubstr);
    bool startsWith(std::string str, std::string substr);
    bool endsWith(std::string str, std::string substr);
    std::map<std::string, double> toTable(std::string x);
}