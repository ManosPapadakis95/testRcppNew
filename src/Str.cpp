
#include "testRcppNew_types.h"

namespace Str {

    bool startsWith(std::string str, std::string substr) {
        return str.rfind(substr, 0) == 0; 
    }

    bool endsWith(std::string str, std::string substr) {
        if (str.length() >= substr.length()) {
            return str.compare(str.length() - substr.length(), substr.length(), substr) == 0;
        }
        return false;
    }

    std::string replaceSubstring(std::string s, std::string oldSubstr, std::string newSubstr) {
        std::string str = s;
        size_t pos = 0;
        while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
            str.replace(pos, oldSubstr.length(), newSubstr);
            pos += newSubstr.length();
        }
        return str;
    }
        
    std::map<std::string, double> toTable(std::string x){
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

}