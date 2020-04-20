#ifndef VIGINERE_H
#define VIGINERE_H
#include <string>
using namespace std;
class viginere
{
    public:
        viginere();
        virtual ~viginere();
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        string cifrado(string mensaje);
        string descifrado(string cifrado);
        string insertarAqui(string mensaje);
        string quitarAqui(string mensaje);
        string cifrado2(string mensaje);
    protected:

    private:
        string clave="Pablo Neruda";
};

#endif // VIGINERE_H
