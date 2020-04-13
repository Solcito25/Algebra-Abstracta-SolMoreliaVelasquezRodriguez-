#include "cesar.h"
#include <string>
using namespace std;
cesar::cesar()
{
    clave=3;
    alfabeto="abcdefghijklmnopqrstuvwxyz";
}

cesar::~cesar()
{
    //dtor
}

string cesar:: cifrado(string mensaje){
    string mensajecifrado;
    for(int i=0; i<mensaje.size();i++){
        int a=alfabeto.find(mensaje.at(i))+clave;
        if(a!=string::npos){
        if(a>alfabeto.size())
            a-=alfabeto.size();
        mensajecifrado+=alfabeto.at(a);

    }
    }
    return mensajecifrado;
}


string cesar::descifrado(string mensajeCifrado){
    string mensajeDescifrado;
    for(int i=0; i<mensajeCifrado.size();i++){
        int a=alfabeto.find(mensajeCifrado.at(i))-clave;
        if(a!=string::npos){
        if(a<0)
            a+=alfabeto.size();
        mensajeDescifrado+=alfabeto.at(a);

    }
    }
    return mensajeDescifrado;
}
