#ifndef KASISKI_H
#define KASISKI_H
#include <vector>
#include<string>
using namespace std;
class kasiski
{
    public:
        kasiski();
        virtual ~kasiski();
         string Ataque(string mensaje);
         vector<int> distanciaSecuenciasRepetidas(string mensaje);
         int mcd (vector<int>a);
         vector <string> divCadena(int noSubcadenas,string mensaje);
         vector <int> frecuencia(string mensaje);

         string analisisFrecuenciasClave(string mensaje);
         int contInString(string buscar, string mensaje);
         string alfabeto;
    protected:

    private:
        int findPosMayor(vector <int> arr);

};

#endif // KASISKI_H
