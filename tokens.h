#pragma once

#include <string>
#include <vector>
#include <map>

using Tokens = std::vector<std::string>;
using Types = std::map<std::string,size_t>;

Tokens tokenize(std::string_view text)
{
	Tokens tokens;
	
	std::string token;
	for(const char c : text)
	{
		if(isalpha(c))
		{
			token += c;
		}
		else
		{
			if(!token.empty())
				tokens.push_back(token);
			token.clear();
		}
	}
	
	return tokens;
}

Types tokens_frequency(const Tokens & tokens)
{
    std::map<std::string,size_t> types;
    
    for(const auto & token : tokens)
	{
		if(!types.contains(token))
		    types.emplace(token,1);
		else
		    types[token] += 1;
	}
    
    return types;
}
