#include "viginere.h"
#include <string>
#include <iostream>
using namespace std;
viginere::viginere()
{

    string clave="Pablo Neruda";
}

viginere::~viginere()
{
    //dtor
}

string viginere::cifrado(string mensaje){
    string cifrado;
    for(int i=0;i<mensaje.size();i++){

        int a=alfabeto.find(mensaje.at(i));
        int b=alfabeto.find(clave.at(i%clave.size()));
        if(a!=string::npos && b!=string::npos){
        int pos=(a+b);
        if(pos>=alfabeto.size())
            pos%=alfabeto.size();
        cifrado+=alfabeto.at(pos);
        }
        else
            cifrado+=mensaje.at(i);
    }
return cifrado;
}



string viginere::descifrado(string cifrado){
    string descifrado;
    for(int i=0;i<cifrado.size();i++){

        int a=alfabeto.find(cifrado.at(i));
        int b=alfabeto.find(clave.at(i%clave.size()));
        if(a!=string::npos && b!=string::npos){
        int pos=(a-b);
        if(pos<0)
            pos+=alfabeto.size();
        else if(pos>=alfabeto.size())
             pos%=alfabeto.size();
        descifrado+=alfabeto.at(pos);
        }
        else
            descifrado+=cifrado.at(i);

}
return descifrado;
}


string viginere:: insertarAqui(string mensaje){
}
