#ifndef MONOMIO_H
#define MONOMIO_H
#include<string>
using namespace std;
class monomio
{
    public:
        monomio();
        virtual ~monomio();
        string cifrado(string mensaje);
        string descifrado(string mensajeCifrado);
        string alfabeto="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    protected:

    private:
        string columnas;
        string clave;
        int mod(int a,int b);
};

#endif // MONOMIO_H
