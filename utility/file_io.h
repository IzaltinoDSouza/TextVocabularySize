#pragma once

#include <exception>
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>

std::string read_text(std::string_view filename)
{
	std::fstream file{filename.data()};
	if(!file.is_open())
	    throw std::invalid_argument{"file can't be opened"};
	    
	std::ostringstream out;
	out << file.rdbuf();
	
	file.close();	
	return out.str();
}

std::vector<std::string> read_lines(std::string_view filename)
{
	std::fstream file{filename.data()};
	if(!file.is_open())
        throw std::invalid_argument{"file can't be opened"};
		
    std::vector<std::string> lines;
    
    std::string line;
	while(getline(file,line))
	{
	    lines.push_back(line);
	}
	
	file.close();
	return lines;
}
