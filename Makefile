all:
    g++ main.cpp -o TextVocabularySize --std=c++20 -lfmt

clean:
    $(RM) hello
