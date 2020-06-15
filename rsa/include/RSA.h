#ifndef RSA_H
#define RSA_H
#include "mat.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
class RSA
{
    public:
        RSA();
        RSA(ZZ E,ZZ N);
        virtual ~RSA();
         string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
         void cifrado(string mensaje);
         void descifrado();
         void NumALetras();
    protected:

    private:
        ZZ n;
        ZZ e;
        ZZ d;
        ZZ aleatorio(ZZ pin);
};

#endif // RSA_H
