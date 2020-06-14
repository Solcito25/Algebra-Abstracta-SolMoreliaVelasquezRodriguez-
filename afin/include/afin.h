#ifndef AFIN_H
#define AFIN_H
#include "mate.h"
#include<string>

using namespace std;
class afin
{
    public:
        afin();
        afin(int x,int y);
        virtual ~afin();
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
        string cifrado(string mensaje);
        string descifrado(string cif);
    protected:

    private:
        int a;
        int b;
        void GenerarClaves();
        int aleatorio();
};

#endif // AFIN_H
