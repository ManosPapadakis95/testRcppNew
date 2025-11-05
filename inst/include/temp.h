#pragma once
#include <string>
#include <map>
#include <vector>


// 4. Template function
template <typename T>
T identity(T value){
    return {};
}

// 5. Template with multiple types
template <typename T, typename U> Rcpp::List combine(const T& a, const U& b){
    return {};
}

// 6. Template with spaces before args
template <typename T> double computeSum (const T& values){
    return {};
}

// 7. Namespaced template
namespace math {
    template <typename T>
    T square(T x){
        return 0;
    }
}

// 8. Nested namespace
namespace app { 
    namespace core {
        inline std::string version1(){
            return "";
        }
    }
}

// 10. Template inside namespace with weird spacing
namespace test { 
    template < typename T , typename U > 
    inline void   addValues   ( const T &a , const U &b ){}
}

// 16. Static function inside namespace
namespace util {
    inline int hashCode(const std::string& key){
        return 0;
    }
}

// 17. Template with default type parameter
template <typename T = Rcpp::NumericVector> T mean(const T& v){
    return {};
}

// 21. Template function with constraints (C++20; may be skipped if not using concepts)
template <typename T/*concept: std::integral*/> T gcd(T a, T b){
    return 0;
}

// 22. Template with nested template arguments
template <typename T>
void process(const T& data){}

// 23. Inline function
inline bool equal(int a, int b) { return a == b; }

// 29. Template function with multiple qualifiers
template <typename T>
inline T average(T a, T b) noexcept{
    return 0;
}