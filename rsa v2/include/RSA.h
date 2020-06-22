#ifndef RSA_H
#define RSA_H
#include "mat.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
class RSA
{
    public:
        RSA(int bits);
        RSA(ZZ E,ZZ N);
        virtual ~RSA();
         string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
         string cifrado(string mensaje);
         string descifrado(string mensaje);
         void NumALetras();
    protected:

    private:
        ZZ n;
        ZZ e;
        ZZ d;
        ZZ aleatorio(ZZ pin);
        int bits;
        string ZZtoStr(ZZ a);

};

#endif // RSA_H
