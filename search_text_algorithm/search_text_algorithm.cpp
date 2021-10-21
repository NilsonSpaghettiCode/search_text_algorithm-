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
    
    /*
    * Permite crear una carpeta para almacenar archivos locales
    * 
    */
    file_control_local.setWorkSpace();

    
    /*
    * Obtiene algun archivo de la carpeta en source
    */
    int option = file_control_local.select_file();

    
    /*
    * Traduce la opcion al sistema de archivos y el path
    */
    std::filesystem::path file_x = file_control_local.get_list_files().at((option - 1));

    
    
    //Muestra el arhivo selecionado
    std::cout << "PATH String:" << file_x.filename() << std::endl;

    //Cambia el tipo de arhivo
    std::string text_on_file = file_control_local.get_text_file(file_x.string());
    
    //Muestra el texto selecionado 
    std::cout << "TEXT: " << text_on_file << std::endl;

    std::string word_to_found = "";

    //Obtiene la el patron a buscar
    std::cout << "Digite la palabra a buscar en el texto" << std::endl;
    std::cout << ">";
    std::cin >> word_to_found;



    std::string text = text_on_file;

    std::string pattern = word_to_found;
    
    StringSearch string_search;


    //Busca el patron en el texto
    std::list<int> match_list = string_search.encontrarPatron(text,pattern);

    string_search.mostrarCoindidencias(match_list, text, pattern);

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
