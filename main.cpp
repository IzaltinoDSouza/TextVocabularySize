#include <iostream>

#include <fmt/core.h>
#include <fmt/format.h>

#include "text_vocabulary_size.h"

void save_csv_statistics(std::string_view filename,
                         TextVocabularySize & textVocSize)
{
    std::string buf = fmt::format("WordFamily,Tokens,(%),Families\n");
    
    size_t tokens_total{};
    double porcent_total{};
    size_t family_total{};
    
    for(size_t wf{1};wf <= 20;wf++)
    {
        const auto total   = textVocSize.wordfamily_total(wf);
        const auto tokens  = textVocSize.wordfamily_tokens(wf);
        const auto porcent = textVocSize.wordfamily_tokens_porcent(wf);
                
        if(wf < 10)
            buf += fmt::format(" {:0<4d},{},{:.2f},{}\n",
                               wf,tokens,porcent,total);
        else
            buf += fmt::format("{:0<5d},{},{:.2f},{}\n",
                               wf,tokens,porcent,total);
                               
       tokens_total  += tokens;
       porcent_total += porcent;
       family_total  += total;
    }
        
    size_t not_in_list_tokens = textVocSize.tokens_total()-tokens_total;
    double not_in_list_porcent = not_in_list_tokens * 100.0 / tokens_total;
    buf += fmt::format("Not in the Lists,{},{:.2f},????\n",
                        not_in_list_tokens,
                        not_in_list_porcent);                        

    buf += 
    fmt::format("\nTokens,Types,Families\n{},{},{}\n",textVocSize.tokens_total(),
                                        textVocSize.types_total(),
                                        textVocSize.wordfamily_total());
    std::cout << buf << '\n';
    
    std::ofstream file{fmt::format("{}_statistics.csv",filename)};
    
    file.write(buf.c_str(),buf.size());
}
void save_csv_wordfamily(std::string_view filename,
                         std::vector<WordFamilyFrequency> wf_freq)
{
    for(size_t wf{1};wf <= 20;wf++)
    {
        std::ofstream file{fmt::format("{}_wordfamily{:d}.csv",filename,wf)};
        std::string buf;
  
        for(const auto &[keyword,freq] : wf_freq[wf-1])
        {
          buf += fmt::format("{},{}\n",keyword,freq);
        }
        
        file.write(buf.c_str(),buf.size());
    }
}
std::string remove_extension(std::string str,
                             std::string_view ext)
{
    size_t length{str.size() - ext.size()};
    return str.substr(0,length);
}
bool is_extension(std::string str,
                  std::string_view ext)
{
    size_t length{str.size() - ext.size()};
    
    return str.substr(length,ext.size()) == ext;
}
int main(int argc,char ** argv)
{
    std::string filename;
    
    if(argc <= 1)
    {
        std::cout << "TextVocabularySize text\n"; 
        return -1;
    }
    else
    {
        if(is_extension(argv[1],".txt"))
        {
            filename = remove_extension(argv[1],".txt");
            
            TextVocabularySize textVocSize{argv[1]};
            
            save_csv_statistics(filename,textVocSize);
            save_csv_wordfamily(filename,textVocSize.get_wordfamily_frequency());
        }
        else{
            std::cout << "extension not suported\n";
        }
    }
}
