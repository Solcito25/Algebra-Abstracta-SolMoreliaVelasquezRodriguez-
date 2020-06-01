#include "railfence.h"
#include<string>
#include <iostream>
using namespace std;
railfence::railfence()
{
   clave=7;
}

railfence::~railfence()
{
    //dtor
}

string railfence::cifrado(string mensaje){
    string cifrados(mensaje.size(),' ');
    int ind=0,q2=0,q1=(clave*2)-2;
    for(int i=0;i<clave;i++,q1-=2,q2+=2){
        int pos=i;
        cifrados.at(ind++)=mensaje.at(i);
        while(pos<mensaje.size()){
            pos+=q1;
            if(q1&&pos<mensaje.size())
                cifrados.at(ind++)=mensaje.at(pos);
            pos+=q2;
            if(q2&&pos<mensaje.size())
                cifrados.at(ind++)=mensaje.at(pos);
        }
    }
    return cifrados;
    }

string railfence::descifrado(string cifrado){
    string descifrados(cifrado.size(),' ');
    int ind=0,q2=0,q1=(clave*2)-2;
    for(int i=0;i<clave;i++,q1-=2,q2+=2){
        int pos=i;
        descifrados.at(i)=cifrado.at(ind++);
        while(pos<cifrado.size()){
            pos+=q1;
            if(q1&&pos<cifrado.size())
                descifrados.at(pos)=cifrado.at(ind++);
            pos+=q2;
            if(q2&&pos<cifrado.size())
                descifrados.at(pos)=cifrado.at(ind++);
        }
    }

return descifrados;

}


