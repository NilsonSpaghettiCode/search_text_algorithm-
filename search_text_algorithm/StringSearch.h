#pragma once
#include <iostream>
#include <list>
class StringSearch
{
public:
	std::string generar_tabla_caracter_incorrecto(std::string patron);
	int calcular_saltos(char caracter_incorrecto, std::string tabla_caracter_incorrecto);
	std::list<int> encontrarPatron(std::string texto, std::string patron);
	bool buscarCoincidencia(int posicion, std::list<int> coincidencias);
	void mostrarCoindidencias(std::list<int> coincidencias, std::string texto, std::string patron);
};

