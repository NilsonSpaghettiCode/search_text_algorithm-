// Boyer Moore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StringSearch.h"
#include <windows.h>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"

std::string StringSearch::generar_tabla_caracter_incorrecto(std::string patron)
{
    std::string tabla_caracter = "";

    tabla_caracter = patron;

    std::reverse(tabla_caracter.begin(), tabla_caracter.end());

    return tabla_caracter;
}

int StringSearch::calcular_saltos(char caracter_incorrecto, std::string tabla_caracter_incorrecto)
{
    int salto = tabla_caracter_incorrecto.size();
    for (size_t i = 0; i < tabla_caracter_incorrecto.size(); i++)
    {
        if (tabla_caracter_incorrecto[i] == caracter_incorrecto)
        {
            salto = i;
            return salto;
        }
    }
    return salto;
}



std::list<int> StringSearch::encontrarPatron(std::string texto, std::string patron)
{
    //Lista de coincidencias encontradas en la cadena de caracteres apartir del texto
    std::list<int> coincidencias;

    //Tabla de caracteres incorrectos

    std::string tabla_caracteres_incorrectos = generar_tabla_caracter_incorrecto(patron);
    //std::cout << "Tabla generada: " << texto << std::endl;
    int p = 0;
    p = patron.size() - 1;


    while (!(p > (texto.size() - 1)))
    {
        std::cout << "Buscando...." << std::endl;
        int y = 0;

        y = p;//Apuntado del texto


        for (int x = patron.size() - 1; x >= 0; x--)
        {
            //std::cout << x << std::endl;
            //std::cout << patron[x] << std::endl;

            if (texto[y] != patron[x])
            {
                char caracter_incorrecto = 'z';

                caracter_incorrecto = texto[y];

                int saltos = 0;

                saltos = calcular_saltos(caracter_incorrecto, tabla_caracteres_incorrectos);

                p += saltos;
                break;
            }
            else if (texto[y] == patron[x])
            {
                //std::cout << "Y" << texto[y] << ", X" << patron[x] << std::endl;
                if (x == 0)
                {
                    coincidencias.push_back(y);
                    p += patron.size();
                }
                y--;
            }


        }

        //std::cout << "P:" << p << std::endl;
    }
    std::cout << "Terminado" << std::endl;


    return coincidencias;
}

bool StringSearch::buscarCoincidencia(int posicion, std::list<int> coincidencias)
{
    bool coincidencia = false;
    for (std::list<int>::iterator i = coincidencias.begin(); i != coincidencias.end(); i++)
    {
        if (*i == posicion)
        {
            coincidencia = true;
            return coincidencia;
        }

    }
    return false;
}

void StringSearch::mostrarCoindidencias(std::list<int> coincidencias, std::string texto, std::string patron)
{
    std::cout << "Cantidad de coincidencias: " << coincidencias.size() << std::endl;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!coincidencias.empty())
    {
        int c = 0;
        for (size_t i = 0; i < texto.size(); i++)
        {

            if (buscarCoincidencia(i, coincidencias))
            {
                c = 0;
                SetConsoleTextAttribute(handle, 
                    BACKGROUND_GREEN | 07);
                std::cout<<texto[i];
                c++;
            }
            else
            {
                std::cout << texto[i];
                c++;
                if (c == patron.size())
                {
                    SetConsoleTextAttribute(handle, 07);
                    c = 0;
                }
            }
        }

    }
    else
    {
        std::cout << texto << std::endl;
    }

}


