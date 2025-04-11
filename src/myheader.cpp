
#include <Rcpp.h>
#include "helpers.h"
#include "Str.h"
using namespace Rcpp;

//The following header is required in RcppExports.cpp so that the compiler has access to the definitions needed for template instantiations.

//[[Rcpp::includes("helpers.h")]]

//[[Rcpp::export(name="minstd_rand0", cpp_name="minstd_rand0")]]
template NumericVector Random::Rminstd_rand0<NumericVector>(std::size_t length); // 1. minstd_rand0

//[[Rcpp::export(name="minstd_rand", cpp_name="minstd_rand")]]
template NumericVector Random::Rminstd_rand<NumericVector>(std::size_t length); // 2. minstd_rand

//[[Rcpp::export(name="mt19937", cpp_name="mt19937")]]
template NumericVector Random::Rmt19937<NumericVector>(std::size_t length); // 3. mt19937

//[[Rcpp::export(name="mt19937_64", cpp_name="mt19937_64")]]
template NumericVector Random::Rmt19937_64<NumericVector>(std::size_t length); // 4. mt19937_64

//[[Rcpp::export(name="ranlux24_base", cpp_name="ranlux24_base")]]
template NumericVector Random::Rranlux24_base<NumericVector>(std::size_t length); // 5. ranlux24_base

//[[Rcpp::export(name="ranlux48_base", cpp_name="ranlux48_base")]]
template NumericVector Random::Rranlux48_base<NumericVector>(std::size_t length); // 6. ranlux48_base

//[[Rcpp::export(name="ranlux24", cpp_name="ranlux24")]]
template NumericVector Random::Rranlux24<NumericVector>(std::size_t length); // 7. ranlux24

//[[Rcpp::export(name="ranlux48", cpp_name="ranlux48")]]
template NumericVector Random::Rranlux48<NumericVector>(std::size_t length); // 8. ranlux48

//[[Rcpp::export(name="knuth_b", cpp_name="knuth_b")]]
template NumericVector Random::Rknuth_b<NumericVector>(std::size_t length); // 9. knuth_b

//[[Rcpp::export(name="default_random_engine", cpp_name="default_random_engine")]]
template NumericVector Random::Rdefault_random_engine<NumericVector>(std::size_t length); // 10. default_random_engine

//[[Rcpp::export(name="subtract_with_carry_engine", cpp_name="subtract_with_carry_engine")]]
template NumericVector Random::Rsubtract_with_carry_engine<NumericVector>(std::size_t length); // 14. subtract_with_carry_engine

//[[Rcpp::export(name="subtract_with_carry_engine_64", cpp_name="subtract_with_carry_engine_64")]]
template NumericVector Random::Rsubtract_with_carry_engine_64<NumericVector>(std::size_t length); // 15. subtract_with_carry_engine 64-bit

// Since default arguments are not allowed in explicit template instantiations, 
// we must use the `signature` field in Rcpp::export to specify the full argument list.

//[[Rcpp::export(name="sample", cpp_name="sample", signature = { x, size, replace = FALSE })]]
template NumericVector Random::sample<NumericVector>(NumericVector x, std::size_t size, bool replace); 

//[[Rcpp::export(name="sample.int", cpp_name="sample_int", signature = { x, size, replace = FALSE })]]
template IntegerVector Random::sample<IntegerVector>(IntegerVector x, std::size_t size, bool replace);


/* 
 * The following declarations do not require definitions, such as explicit template instantiations, 
 * so including a header file in RcppExports.cpp is not strictly necessary. 
 * However, the compiler requires the namespace to be visible, which makes including the header unavoidable. 
 * Placing them here helps keep the original implementation file clean and ensures they remain within their namespace.
 */


//[[Rcpp::includes("Str.h")]]

//[[Rcpp::export(name="containsSubstring", cpp_name="containsSubstring")]]
bool Str::containsSubstring(std::string str, std::string substr);

//[[Rcpp::export(name="toUpperCase", cpp_name="toUpperCase")]]
std::string Str::toUpperCase(std::string s);

//[[Rcpp::export(name="trim", cpp_name="trim")]]
std::string Str::trim(std::string s);

//[[Rcpp::export(name="startsWith", cpp_name="startsWith")]]
bool Str::startsWith(std::string str, std::string substr);

//[[Rcpp::export(name="endsWith", cpp_name="endsWith")]]
bool Str::endsWith(std::string str, std::string substr);

//[[Rcpp::export(name="replaceSubstring", cpp_name="replaceSubstring")]]
std::string Str::replaceSubstring(std::string s, std::string oldSubstr, std::string newSubstr);

//[[Rcpp::export(name="toTable.char", cpp_name="toTable_char")]]
std::map<std::string, double> Str::toTable(std::string x);