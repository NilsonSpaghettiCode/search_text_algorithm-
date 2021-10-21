#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <typeinfo>
#include <fstream>
class IOSystemLocal
{

private:
	std::vector<std::filesystem::path> list_files;
public:
	static const std::string directory;
	void printAlgo(std::string frase);

	void create_directory_base();
	void load_list_files();

	void view_list_files();

	int select_file();
	std::string get_text_file(std::string file_path);
	
	std::vector<std::filesystem::path> get_list_files();

	void setWorkSpace() 
	{
		this->create_directory_base();
		std::cout << "Porfavor cargue sus archivos en ./source " << std::endl;
		system("PAUSE");
		this->load_list_files();
	}
};

