#pragma once

#include <cctype>
#include <algorithm>
#include <string>

std::string tolower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return str;
}

std::vector<std::string> split(const std::string & str, const char delim)
{
    size_t begin;
    size_t end = 0;
    
    std::vector<std::string> out;
 
    while ((begin = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, begin);
        out.push_back(str.substr(begin, end - begin));
    }
    
    return out;
}
