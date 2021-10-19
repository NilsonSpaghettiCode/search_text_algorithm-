#include "IOSystemLocal.h"
#include <filesystem>


const std::string IOSystemLocal::directory = "source";
void IOSystemLocal::printAlgo(std::string frase) 
{
}

void IOSystemLocal::create_directory_base() 
{
	std::cout << std::filesystem::create_directory("./" + IOSystemLocal::directory) << std::endl;
}

void IOSystemLocal::load_list_files()
{
	for (const auto& entry : std::filesystem::directory_iterator(IOSystemLocal::directory)){
		IOSystemLocal::list_files.push_back(entry.path());
		//std::cout << entry.path();
	}
}

void IOSystemLocal::view_list_files() 
{
	std::cout << "Numero de archivos en source: " << IOSystemLocal::list_files.size() << std::endl;
	int x = 1;
	for (std::filesystem::path var : IOSystemLocal::list_files)
	{
		std::cout << x << ". " << var << std::endl;
		x++;
	}
	std::cout << ">";
}
int IOSystemLocal::select_file() 
{
	int selection = 0;
	if (IOSystemLocal::list_files.size() == 0) 
	{
		std::cout << "No hay archivos en source" << std::endl;
	}
	else 
	{
		IOSystemLocal::view_list_files();
		std::cin >> selection;
	}
	
	return selection;
}

std::string IOSystemLocal::get_text_file(std::string file_path)
{
	std::string data = "";
	std::string text = "";
	std::ifstream reader;
	reader.open(file_path,std::ios_base::in);
	while (reader >> data)
	{
		text += data+" ";
	}
	reader.close();

	return text;
}
std::vector<std::filesystem::path> IOSystemLocal::get_list_files()
{
	return this->list_files;
}
