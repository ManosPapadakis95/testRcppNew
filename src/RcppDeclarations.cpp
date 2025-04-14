
#include <Rcpp.h>
#include "testRcppNew_types.h"

/* 
 * The following declarations do not require definitions, such as explicit template instantiations, 
 * so including a header file in RcppExports.cpp is not strictly necessary. 
 * However, the compiler requires the namespace to be visible, which makes including the header unavoidable. 
 * Placing them here helps keep the original implementation file clean and ensures they remain within their namespace.
 */

//[[Rcpp::export(name="startsWith", cpp_name="startsWith")]]
bool Str::startsWith(std::string str, std::string substr);

//[[Rcpp::export(name="endsWith", cpp_name="endsWith")]]
bool Str::endsWith(std::string str, std::string substr);

//[[Rcpp::export(name="replaceSubstring", cpp_name="replaceSubstring")]]
std::string Str::replaceSubstring(std::string s, std::string oldSubstr, std::string newSubstr);

//[[Rcpp::export(name="toTable.char", cpp_name="toTable_char")]]
std::map<std::string, double> Str::toTable(std::string x);