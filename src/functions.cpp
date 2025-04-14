#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector power_vector(Rcpp::NumericVector x, double power) {
    return Rcpp::pow(x, power);
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