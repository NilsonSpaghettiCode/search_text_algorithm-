// search_text_algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IOSystemLocal.h"
#include "StringSearch.h"

int main()
{
    /*
    IOSystemLocal file_control_local;
    //c.create_directory_base();

    //Get a list of files in ./source/
    file_control_local.load_list_files();

    int option = file_control_local.select_file();

    //std::cout<<"PATH SELECT:"<< c.get_list_files().at((option - 1));

    std::filesystem::path file_x = file_control_local.get_list_files().at((option - 1));

    //std::cout << "PATH String:" << file_x.filename() << std::endl;

    std::string text_on_file = file_control_local.get_text_file(file_x.string());

    std::cout << "Archivo:" << text_on_file << std::endl;
    
    std::string word_to_found = "";

    std::cout << "Digite la palabra a buscar en el texto" << std::endl;
    std::cout << ">";
    std::cin >> word_to_found;
    


    string txt = text_on_file;
    string pattern= word_to_found;
    StringSearch search_algoritm;

    search_algoritm.search(txt, pattern);

    */
    IOSystemLocal file_control_local;
    file_control_local.create_directory_base();
    std::string option_c = "";
    std::cout << "Una vez sus archivos esten en ./source " << std::endl;
    system("PAUSE");

    file_control_local.load_list_files();
    int option = file_control_local.select_file();

    std::filesystem::path file_x = file_control_local.get_list_files().at((option - 1));

    std::cout << "PATH String:" << file_x.filename() << std::endl;

    std::string text_on_file = file_control_local.get_text_file(file_x.string());
    std::cout << "TEXT: " << text_on_file << std::endl;

    std::string word_to_found = "";

    std::cout << "Digite la palabra a buscar en el texto" << std::endl;
    std::cout << ">";
    std::cin >> word_to_found;

    std::string txt = text_on_file;
    std::string pattern_test = word_to_found;
    StringSearch test;

    test.generate_table_bad_chars(pattern_test);
    test.search_pattern(txt, pattern_test);
    test.show_shift_positions();
    test.show_text_pattern();
    system("PAUSE");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
