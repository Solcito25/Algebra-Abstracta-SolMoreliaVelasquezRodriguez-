#ifndef PRACTICA1_H
#define PRACTICA1_H
#include<string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;


class practica1
{
    public:
        practica1();
        virtual ~practica1();
        void ToArrayChar(string palabra);
        string ToString(char arrays[]);
        string changeMayMin(string);
        void IntToString(int a,int b);
        string CantCarac(char y,int x);
        void Desapruebo();
        int CantPalabras(string frase,string palabra);
        void PrintLetra(string palabra);
        string UnirMitad(string palabra, string adjuntar);
        string Reemplazar(string frase,string tochange,string change);
        string LexiMayor(string a, string b);
        void Escribirfiles(int n);
        int Sumatoria();
        string rot13(string);
        string drot13(string palabra);
        string ApellidosNombres(string apellidos,string nombre);
        void ahorcado(string continuar);
        string reempAhorcado(string palabra,string cifrado,string intento);
        string InserCarcte(string palabra);
        void Tokens(string frase);
        void Reverse(string frase);
        void Ordenar(string palabra[], int orden, int tam);
        void OrdenarSeleccion(string palabra[],const int tam,bool(*compara)(string, string));
        static bool ascendente(string a,string b);
        static bool descendente(string a,string b);
    protected:

    private:
};

#endif // PRACTICA1_H
