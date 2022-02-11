#pragma once

#include "utility/file_io.h"
#include "utility/string.h"
#include "tokens.h"
#include "word_family.h"

class TextVocabularySize
{
public:
    TextVocabularySize(std::string_view filename)
    {
        const auto text = tolower(read_text(filename));
	    const auto tokens = tokenize(text);
	    m_tokens_total = tokens.size();
	    
	    m_types  = tokens_frequency(tokens);
	    
	    for(int i{1};i <= k_wordfamily_list_max;i++)
	    {
            const auto wf = read_wordfamily(i);
            const auto wf_freq = wordfamily_frequency(wf,m_types);
	        m_wordfamily_freq.push_back(wf_freq);	        
            m_wordfamily_total.push_back(wf_freq.size());
	    }
	}
		
	size_t tokens_total() const
	{
	    return m_tokens_total;
	}
	size_t types_total() const
	{
	    return m_types.size();
	}
	size_t wordfamily_total()
	{
	    size_t total{};
	    for(int i{1};i <= k_wordfamily_list_max;i++)
	    {
	        total += m_wordfamily_total[i-1];
        }
        return total;
	}
	size_t wordfamily_total(size_t wf) const
	{
	    if(wf > 0 && wf <= k_wordfamily_list_max)
	        return m_wordfamily_total[wf-1];
	    else
	        throw std::invalid_argument{"wordfamily invalid"};
	}
	
	size_t wordfamily_tokens(size_t wf)
	{
	    if(wf > 0 && wf <= k_wordfamily_list_max)
	    {
	        size_t freq_total{};
	        
	        for(const auto &[keyword,freq] : m_wordfamily_freq[wf-1])
	        {
	            freq_total += freq; 
	        }
	        return freq_total;
	    }
	    else
	        throw std::invalid_argument{"wordfamily invalid"};
	}
	double wordfamily_tokens_porcent(size_t wf)
	{
	    if(wf > 0 && wf <= k_wordfamily_list_max)
	    {
	        size_t freq_total{};
	        
	        for(const auto &[keyword,freq] : m_wordfamily_freq[wf-1])
	        {
	            freq_total += freq; 
	        }
	        return freq_total * 100.0 / m_tokens_total;
	    }
	    else
	        throw std::invalid_argument{"wordfamily invalid"};
	}
	
	std::vector<WordFamilyFrequency> get_wordfamily_frequency()
	{
	    return m_wordfamily_freq;
	}
	WordFamilyFrequency get_wordfamily_frequency(size_t wf) const
	{
	    if(wf > 0 && wf <= k_wordfamily_list_max)
	        return m_wordfamily_freq[wf-1];
	    else
	        throw std::invalid_argument{"wordfamily invalid"};
	}
private:
    Types  m_types;
    std::vector<WordFamilyFrequency> m_wordfamily_freq;
    std::vector<size_t>              m_wordfamily_total;    
    size_t                           m_tokens_total{};
        
    const size_t k_wordfamily_list_max{20};
};
