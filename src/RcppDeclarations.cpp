
#include <Rcpp.h>
#include "testRcppNew_types.h"

//[[Rcpp::export(name="minstd_rand", cpp_name="minstd_rand")]]
template Rcpp::NumericVector Random::Rminstd_rand<Rcpp::NumericVector>(std::size_t length); // 2. minstd_rand

//[[Rcpp::export(name="mt19937", cpp_name="mt19937")]]
template Rcpp::NumericVector Random::Rmt19937<Rcpp::NumericVector>(std::size_t length); // 3. mt19937

//[[Rcpp::export(name="knuth_b", cpp_name="knuth_b")]]
template Rcpp::NumericVector Random::Rknuth_b<Rcpp::NumericVector>(std::size_t length); // 9. knuth_b

//Declarations for integers

//[[Rcpp::export(name="minstd_rand.int", cpp_name="minstd_rand_int")]]
template Rcpp::IntegerVector Random::Rminstd_rand<Rcpp::IntegerVector>(std::size_t length); // 2. minstd_rand

//[[Rcpp::export(name="mt19937.int", cpp_name="mt19937_int")]]
template Rcpp::IntegerVector Random::Rmt19937<Rcpp::IntegerVector>(std::size_t length); // 3. mt19937

//[[Rcpp::export(name="knuth_b.int", cpp_name="knuth_b_int")]]
template Rcpp::IntegerVector Random::Rknuth_b<Rcpp::IntegerVector>(std::size_t length); // 9. knuth_b

// Since default arguments are not allowed in explicit template instantiations, 
// we must use the `signature` field in Rcpp::export to specify the full argument list.

//[[Rcpp::export(name="sample", cpp_name="sample", signature = { x, size, replace = FALSE })]]
template Rcpp::NumericVector Random::sample<Rcpp::NumericVector>(Rcpp::NumericVector x, std::size_t size, bool replace); 

//[[Rcpp::export(name="sample.int", cpp_name="sample_int", signature = { x, size, replace = FALSE })]]
template Rcpp::IntegerVector Random::sample<Rcpp::IntegerVector>(Rcpp::IntegerVector x, std::size_t size, bool replace);


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