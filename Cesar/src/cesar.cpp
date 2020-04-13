#include "cesar.h"
#include <string>
#include <iostream>
using namespace std;
cesar::cesar()
{
    clave=15;
    alfabeto="abcdefghijklmnopqrstuvwxyz";
}

cesar::~cesar()
{
    //dtor
}

string cesar:: cifrado(string mensaje){
    string mensajecifrado;
    string substclave=alfabeto.substr(0,clave);
    alfabeto+=substclave;
    for(int i=0; i<mensaje.size();i++){
        size_t a=alfabeto.find(mensaje.at(i));
        if(a!=string::npos){
            a+=clave;
            mensajecifrado+=alfabeto.at(a);
        }
        else
            mensajecifrado+=" ";
    }
    return mensajecifrado;
}


string cesar::descifrado(string mensajeCifrado){
    string mensajeDescifrado;
    string substclave=alfabeto.substr(0,clave);
    alfabeto+=substclave;
    for(int i=0; i<mensajeCifrado.size();i++){
        size_t a=alfabeto.rfind(mensajeCifrado.at(i));
        if(a!=string::npos){
            a-=clave;
        mensajeDescifrado+=alfabeto.at(a);
        }
        else
            mensajeDescifrado+=" ";
    }
    return mensajeDescifrado;
}
