#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;
class StringSearch
{
#define NO_OF_CHARS 256

private:
    //tabla = [{'a',0},{'char',posicion}]
    map<char, int> table_bad_chars;
    list<int> shift; //Lista de cambios en base a las posiciones
    std::string text;
    std::string pattern_local;

public:

    void generate_table_bad_chars(std::string pattern);
    void show_table_bad_chars();
    void search_pattern(std::string text, std::string pattern);
    int get_size_char(char bad_char);
    void show_text_pattern();
    void badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS]);
    void search(std::string text, std::string pattern);
    void show_shift_positions();
};

