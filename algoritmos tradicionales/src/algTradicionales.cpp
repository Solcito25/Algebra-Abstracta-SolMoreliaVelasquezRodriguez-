#include "algTradicionales.h"
#include<string>
using namespace std;
algTradicionales::algTradicionales()
{
    //ctor
}

algTradicionales::~algTradicionales()
{
    //dtor
}

int algTradicionales::mod(int a,int b){
    int r=a-(b*(a/b));
    if(r<0)
        r=b+r;
    return r;
    }

string algTradicionales::cifradoPoly(string mensaje){
    string cifrado;
    for (int i=0;i<mensaje.size();i++){
        int pos=alfabeto.find(mensaje.at(i));///busca en la matriz la posicion de la letra
        if(pos>8) pos--;///Resta 1 porque I/J comparten posicion
        cifrado+=alfabeto.at(pos/5);///busca la columna
        cifrado+=alfabeto.at(mod(pos,5));///busca la fila
    }
    return cifrado;
}

string algTradicionales::descifradoPoly(string mensajeCifrado){
    string descifrado;
    for(int i=0;i<mensajeCifrado.size();i+=2){
        int pos=alfabeto.find(mensajeCifrado.at(i))*5+alfabeto.find(mensajeCifrado.at(i+1));
        if(pos>8) pos++;///evalua si es mayor a 8 por la posicion I/J
        descifrado+=alfabeto.at(pos);
    }
    return descifrado;
}
