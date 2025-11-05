#include <Rcpp.h>
#include "../../include/testRcppNew_types.h"
#include "../../include/temp.h"

// 1. Simple function
// [[Rcpp::export(name="add", cpp_name="add")]]
int add(int a, int b){
    return 0;
}

// 2. Function with extra spaces and newlines
// [[Rcpp::export(name="multiply", cpp_name="multiply")]]
double   
   multiply  
   (double x, 
    double y){
    return 0.0;
}

// 4. Template function

// [[Rcpp::export(name="identity.numeric", cpp_name="identity_numeric")]]
template Rcpp::NumericVector identity<Rcpp::NumericVector>(Rcpp::NumericVector x);

// [[Rcpp::export(name="identity.integer", cpp_name="identity_integer")]]
template Rcpp::IntegerVector     identity
<
Rcpp::IntegerVector   >
(Rcpp::IntegerVector x);

// [[Rcpp::export(name="identity.character", cpp_name="identity_character")]]
template Rcpp::CharacterVector 
identity<
Rcpp::CharacterVector
>
(Rcpp::CharacterVector x);

// 5. Template with multiple types

// instantiate with Rcpp types
// [[Rcpp::export(name="combine.a", cpp_name="combine_a")]]
template Rcpp::List
             combine
             <
             Rcpp   ::
     NumericVector, 
     Rcpp::IntegerVector
     >     (const Rcpp::NumericVector& y, 
        const Rcpp::IntegerVector& x);

// [[Rcpp::export(name="combine.b", cpp_name="combine_b")]]
template Rcpp
::    List
 combine
 <Rcpp
 ::
 IntegerVector     , 
 Rcpp::
 NumericVector
 >
 (const Rcpp::IntegerVector& y, const Rcpp::NumericVector& x);

// 6. Template with spaces before args

// instantiate with Rcpp vectors
// [[Rcpp::export(name="computeSum_a", cpp_name="computeSum_a")]]
template double computeSum<Rcpp
::
NumericVector>(const 
    Rcpp::NumericVector& x);

// [[Rcpp::export(name="computeSum_b", cpp_name="computeSum_b")]]
template double    
computeSum
<Rcpp::
IntegerVector>(const Rcpp::
    IntegerVector& x);

// 7. Namespaced template

// instantiations
// [[Rcpp::export(name="math_square_a", cpp_name="math_square_a")]]
template 
double 
math::square
<
double
>    (
    double x);

// [[Rcpp::export(name="math_square_b", cpp_name="math_square_b")]]
template int    math::square
<int>(int x);

// 8. Nested namespace

// [[Rcpp::export(name="app_core_version1", cpp_name="app_core_version1")]]
std::string app::core::version1();

// 9. Template specialization (declaration)
// [[Rcpp::export(name="identity_string", cpp_name="identity_string")]]
template <>
std::string 
identity<std::string>(std::string value){
    return "";
}

// 10. Template inside namespace with weird spacing

// instantiations
// [[Rcpp::export(name="test_addValues_a", cpp_name="test_addValues_a")]]
template 
void 
test::addValues
<double
, double>(const
    double
    & y, 
    const double& x);
    
// [[Rcpp::export(name="test_addValues_b", cpp_name="test_addValues_b")]]
template void 
test::addValues
<Rcpp
::NumericVector, 
Rcpp::NumericVector>(const 
    Rcpp::NumericVector& y, 
    const
     Rcpp::NumericVector& x);

// 12. noexcept
// [[Rcpp::export(name="pi_func", cpp_name="pi_func")]]
double piii() noexcept{
    return 0.0;
}

// 16. Static function inside namespace

// [[Rcpp::export(name="util_hashCode", cpp_name="util_hashCode")]]
inline int 
util::hashCode(const std::string& key);

// 17. Template with default type parameter

// explicit instantiations
// [[Rcpp::export(name="mean", cpp_name="mean1")]]
template 
Rcpp::NumericVector 
mean<Rcpp::NumericVector>(const Rcpp::NumericVector& x);

// [[Rcpp::export(name="mean", cpp_name="mean")]]
template Rcpp::
IntegerVector mean
<Rcpp::
IntegerVector>(const Rcpp::IntegerVector& x);

// 21. Template function with constraints (C++20; may be skipped if not using concepts)

// explicit instantiations
// [[Rcpp::export(name="gcd_a", cpp_name="gcd_a")]]
template int gcd<int>(
    int x
    , int y);

// [[Rcpp::export(name="gcd_b", cpp_name="gcd_b")]]
template long gcd<long>(long x, long y);

// 22. Template with nested template arguments

// instantiate with Rcpp types (data as Rcpp::List of maps would be represented as List)
// [[Rcpp::export(name="process", cpp_name="process")]]
template void process<Rcpp::List>(const Rcpp::List& x);

// 23. Inline function
// [[Rcpp::export(name="equal_func", cpp_name="equal_func")]]
inline bool equal(int a, int b);

// 29. Template function with multiple qualifiers

// instantiate for double/int
// [[Rcpp::export(name="average_a", cpp_name="average_a")]]
template double 
average
<double>(double x, double y);

// [[Rcpp::export(name="average_b", cpp_name="average_b")]]
template int    average<int>(int x
    , 
    int y);