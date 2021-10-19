#include "StringSearch.h"
#include <algorithm>
#include <iterator>


void StringSearch::generate_table_bad_chars(std::string pattern)
{
	std::reverse(pattern.begin(), pattern.end());
	for (int x = 0; x < pattern.size(); x++) 
	{
		this->table_bad_chars.insert({ pattern.at(x) , x });
	}
	this->table_bad_chars.insert({'-',pattern.size()});
}


void StringSearch::show_table_bad_chars() 
{
	std::cout << "C:" << this->table_bad_chars.size() << std::endl;
	for (const auto& [key, value] : this->table_bad_chars) {
		std::cout << key << " = " << value << "; ";
	}
}

void StringSearch::search_pattern(std::string text, std::string pattern)
{
	this->text = text;
	this->pattern_local = pattern;
	this->generate_table_bad_chars(pattern);
	this->show_table_bad_chars();

	int scoop_text = pattern.size() - 1;
	while ((scoop_text <= (text.size() - pattern.size())) || scoop_text > text.size())
	{
		int scoop_pattern = pattern.size() - 1;
		
		std::cout << "" << std::endl;
		std::cout << "Scoo Text R: " << scoop_text << std::endl;
		std::cout << "Scoo Patter P: " << scoop_pattern << std::endl;
		std::cout << "SIZE TEXT:" << text.size()<<endl;
		while (scoop_pattern != 0)
		{

			if (pattern.at(scoop_pattern) != text.at(scoop_text))
			{
				//std::cout << "Comparacion: " << pattern.at(scoop_pattern) << " != " << text.at(scoop_text) << std::endl;
			
				//Encuentra el valor del salto en base a la tabla preprocesada del caracter incorrecto

				int number_skips = this->get_size_char(text.at(scoop_text));

				//std::cout << "Saltos:" << number_skips << std::endl;

				scoop_text += number_skips;

				//std::cout << "Scoop  Text:" << scoop_text << std::endl;
				//std::cout << "SCOOP char" << table_bad_chars[text.at(scoop_text)] << std::endl;

				//Restaura el valor para apuntar al inicio de la comparacion
				scoop_pattern = pattern.size()-1;  
				
			}
			else
			{
				//std::cout << "Comparacion: " << pattern.at(scoop_pattern) << " != " << text.at(scoop_text) << std::endl;


				scoop_pattern--;
				scoop_text--;
			}


		}
		
		
		std::cout << "Scoop Push: " << scoop_text << std::endl;
		this->shift.push_front(scoop_text);
		scoop_text += pattern.size();
		}
}

int StringSearch::get_size_char(char bad_char)
{
	if (this->table_bad_chars.find(bad_char) == this->table_bad_chars.end()) 
	{
		return this->table_bad_chars['-'];
	}
	else 
	{
		return this->table_bad_chars[bad_char];
	}
}

void StringSearch::show_text_pattern()
{
	
	for (int i = 0; i < this->text.size(); i++)
	{
		if (std::find(this->shift.begin(),this->shift.end(),i) == this->shift.end())
		{
			std::cout << this->text.at(i);

		}else{
		for (int j = 0; j < this->pattern_local.size(); j++)
		{
			if (j == 0)
			{
				std::cout << "@" << this->text.at(i);
			}
		}
		
		}
	}

}

void StringSearch::badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence
	// of a character
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
	
}


void StringSearch::search(std::string text, std::string patttern)
{
	int m = patttern.size();
	int n = text.size();

	this->text = text;
	this->pattern_local = patttern;
	int badchar[NO_OF_CHARS];

	/* Fill the bad character array by calling
	the preprocessing function badCharHeuristic()
	for given pattern */
	badCharHeuristic(patttern, m, badchar);

	int s = 0; // s is shift of the pattern with
				// respect to text
	while (s <= (n - m))
	{
		int j = m - 1;

		/* Keep reducing index j of pattern while
		characters of pattern and text are
		matching at this shift s */
		while (j >= 0 && patttern[j] == text[s + j])
			j--;

		/* If the pattern is present at current
		shift, then index j will become -1 after
		the above loop */
		if (j < 0)
		{
			this->shift.push_front(s);
			cout << "Patron encontrado en: " << s << endl;
			/* Shift the pattern so that the next
			character in text aligns with the last
			occurrence of it in pattern.
			The condition s+m < n is necessary for
			the case when pattern occurs at the end
			of text */
			s += (s + m < n) ? m - badchar[text[s + m]] : 1;
		}

		else
			/* Shift the pattern so that the bad character
			in text aligns with the last occurrence of
			it in pattern. The max function is used to
			make sure that we get a positive shift.
			We may get a negative shift if the last
			occurrence of bad character in pattern
			is on the right side of the current
			character. */
			s += max(1, j - badchar[text[s + j]]);
	}

	if (this->shift.size() == 0)
	{
		cout << "No hay coincidencias" << endl;
	}
	else 
	{
		cout << "Numero de coincidencias:"<<shift.size() << endl;
	}

	this->show_text_pattern();
}


void StringSearch::show_shift_positions() 
{
	std::cout << "Cantidad de patrones encontrados: "<<this->shift.size() << endl;;
	for (std::list<int>::iterator i = this->shift.begin(); i != this->shift.end() ; i++)
	{
		std::cout << "Posicion en texto: " << *i <<endl;
	}
}
