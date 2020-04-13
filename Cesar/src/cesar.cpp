#include "cesar.h"
#include <string>
#include <iostream>
using namespace std;
cesar::cesar()
{
    clave=25;
    alfabeto="abcdefghijklmnopqrstuvwxyz";
}

cesar::~cesar()
{
    //dtor
}

string cesar:: cifrado(string mensaje){
    string mensajecifrado;
    for(int i=0; i<mensaje.size();i++){
        unsigned int a=alfabeto.find(mensaje.at(i));
        if(a!=string::npos){
            int comp=alfabeto.size()-clave;
            if(a>=comp)
               a=a-comp;
            else
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
    for(int i=0; i<mensajeCifrado.size();i++){
        unsigned int a=alfabeto.find(mensajeCifrado.at(i));
        if(a!=string::npos){
            if(a<clave) {
                a=a+alfabeto.size()-clave;
            }
            else
            a-=clave;
        mensajeDescifrado+=alfabeto.at(a);
        }
        else
            mensajeDescifrado+=" ";
    }
    return mensajeDescifrado;
}
