#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector power_vector(Rcpp::NumericVector x, double power) {
    return Rcpp::pow(x, power);
}

// [[Rcpp::export]]
Rcpp::NumericVector sqrt_vector(Rcpp::NumericVector x) {
    return Rcpp::sqrt(x);
}

// [[Rcpp::export]]
double sum_vector(Rcpp::NumericVector x) {
    return Rcpp::sum(x);
}

// [[Rcpp::export]]
Rcpp::NumericVector divide_vector(Rcpp::NumericVector x, double divisor) {
    return x / divisor;
}

// [[Rcpp::export]]
Rcpp::NumericVector multiply_vector(Rcpp::NumericVector x, double multiplier) {
    return x * multiplier;
}

// [[Rcpp::export]]
std::map<std::string, double> toTable(Rcpp::NumericVector x){
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