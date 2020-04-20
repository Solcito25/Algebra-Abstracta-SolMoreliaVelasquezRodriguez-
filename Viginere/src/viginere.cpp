#include "viginere.h"
#include <string>
#include <iostream>
using namespace std;
viginere::viginere()
{

    //string clave="Pablo Neruda";
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
    int i=10;
    int b=mensaje.size()+((mensaje.size()/10))*4;
    while(i<b){
        mensaje.insert(i,"AQUI");
        int a=mensaje.find("AQUI")+4;
        i=i+a;
            }
            cout<<mensaje.size()<<endl;
    while(mensaje.size()%4!=0){
        mensaje.append("W");
    }
    return mensaje;
}


string viginere:: cifrado2(string mensaje){
string cifrado;
    if (clave.size()< mensaje.size()){
        for(int i=0;clave.size()<=mensaje.size();i++){
            clave+=mensaje.at(i);
        }

    }
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

string viginere::quitarAqui(string mensaje){
    int a=mensaje.find("AQUI");

    while(a!=string::npos){
        mensaje.erase(a,4);
        a=mensaje.find("AQUI",a+1);}
    int b=mensaje.rfind('W');
    while(b!=string::npos){
        mensaje.erase(b,1);
        b=mensaje.rfind('W',b);}

return mensaje;
}
