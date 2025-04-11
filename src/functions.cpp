#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector power_vector(NumericVector x, double power) {
    return Rcpp::pow(x, power);
}

// [[Rcpp::export]]
NumericVector sqrt_vector(NumericVector x) {
    return Rcpp::sqrt(x);
}

// [[Rcpp::export]]
double sum_vector(NumericVector x) {
    return Rcpp::sum(x);
}

// [[Rcpp::export]]
NumericVector divide_vector(NumericVector x, double divisor) {
    return x / divisor;
}

// [[Rcpp::export]]
NumericVector multiply_vector(NumericVector x, double multiplier) {
    return x * multiplier;
}

// [[Rcpp::export]]
std::map<std::string, double> toTable(NumericVector x){
    std::map<std::string, double> res;
    for(double y : x){
        std::string sxi = std::to_string(y);
        if(res.find(sxi) != res.end())
            ++res[std::to_string(y)];
        else
            res[std::to_string(y)] = 1;
    }
    return res;
}