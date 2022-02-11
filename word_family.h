#pragma once

#include "utility/file_io.h"
#include "utility/string.h"

#include <fmt/core.h>
#include <fmt/format.h>

#include <vector>
#include <map>

#include <exception>

using WordFamily = std::map<std::string, std::vector<std::string>>;
using WordFamilyFrequency = std::map<std::string, size_t>;

WordFamily read_wordfamily(size_t number)
{
	auto lines = read_lines(fmt::format("data/{}.wordfamily",number));
	
	std::map<std::string, std::vector<std::string>> wordfamily;
	
	for(const auto & line : lines)
	{
		auto tmp = split(line,' ');
		wordfamily.emplace(tmp[0],tmp);
	}	
	
	return wordfamily;
}

WordFamilyFrequency wordfamily_frequency(const WordFamily & wf,Types & types)
{
	WordFamilyFrequency wf_freq;
	for(const auto &[keyword, members] : wf)
	{
		int freq{0};
		for(const auto & member : members)
		{
			if(types.contains(member))
				freq += types[member];
		}
		
		if(freq != 0)
			wf_freq.emplace(keyword,freq);
	}
	
	return wf_freq;
}
