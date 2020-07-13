#ifndef RSA_H
#define RSA_H
#include "funciones.h"
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
    private:
        ZZ n;
        ZZ e;
        ZZ d;
        ZZ p;
        ZZ q;
        ZZ aleatorio(ZZ pin);
        string ZZtoStr(ZZ a);
        ZZ TRC(ZZ num);
};

#endif // RSA_H
