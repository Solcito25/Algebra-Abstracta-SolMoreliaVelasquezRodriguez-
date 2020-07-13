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
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
        string cifrado(string mensaje,ZZ nr, ZZ er);
        string descifrado(string mensaje);
        string descifroConE(string mensaje, ZZ nr,ZZ er);
        string completarCeros(string mensaje, ZZ nr);
        string cifroConD(string msg);
        string firmarCifrar(string msgl,ZZ nr,ZZ er);
        string bloques(string mensaje);
        string DescifrarFirma(string msgn,ZZ nr, ZZ er);
        void NumALetras();

    private:
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ e;
        ZZ d;
        ZZ aleatorio(ZZ pin);
        string ZZtoStr(ZZ a);
        ZZ TRC(ZZ num);


};

#endif // RSA_H
