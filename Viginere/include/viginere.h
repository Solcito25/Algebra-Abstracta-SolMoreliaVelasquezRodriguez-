#ifndef VIGINERE_H
#define VIGINERE_H
#include <string>
using namespace std;
class viginere
{
    public:
        viginere();
        viginere(string alfabeto);
        virtual ~viginere();
        string alfabeto="abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
        string cifrado(string mensaje);
        string descifrado(string cifrado);
        string insertarAqui(string mensaje);
        string quitarAqui(string mensaje);
        string cifrado2(string mensaje);
    protected:

    private:
        string clave="Rony Rodrigo Sicos Barrera 191-10-46034";
};

#endif // VIGINERE_H