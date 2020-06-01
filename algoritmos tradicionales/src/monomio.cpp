#include "monomio.h"
using namespace std;
#include <iostream>
monomio::monomio()
{
    clave="DENARIOS";
    columnas="27";
}

monomio::~monomio()
{
    //dtor
}
int monomio::mod(int a,int b){
    int r=a-(b*(a/b));
    if(r<0)
        r=b-r;
    return r;
    }
string monomio::cifrado(string mensaje){
    string cif;
    for(int i=0;i<clave.size();i++){///se borra letras de la clave en el alfabeto
        int a=alfabeto.find(clave.at(i));
        alfabeto.erase(a,1);
    }
    for (int i=0;i<columnas.size();i++){///se coloca un espacio en las posiciones q ahora son columnas
        int b=stoi(columnas.substr(i,1));
        clave.insert(b," ");
    }
    string matriz=clave+alfabeto;

    while(mod(matriz.size(),columnas.size())!=0)
            matriz.append("#");
    for(int i=0;i<mensaje.size();i++){
        int a=matriz.find(mensaje.at(i)),aux1=0;
        if(a>=clave.size()){
            int j=0;
            while(j<columnas.size()&&aux1==0){
                if(a<(clave.size()*(j+2))){
                    int c=stoi(columnas.substr(j,1));
                    aux1=10*c;
                    }
                j++;
            }
            a=mod(a,clave.size());
            a+=aux1;
        }
        string aux=to_string(a);
        cif+=aux;
    }
return cif;
}
string monomio::descifrado(string mensajeCifrado){
    string descif;///72827
    for(int i=0;i<clave.size();i++){///se borra letras de la clave en el alfabeto
        int a=alfabeto.find(clave.at(i));
        alfabeto.erase(a,1);
    }
    for (int i=0;i<columnas.size();i++){///se coloca un espacio en las posiciones q ahora son columnas
        int b=stoi(columnas.substr(i,1));
        clave.insert(b," ");
    }
    string matriz=clave+alfabeto;

    while(mod(matriz.size(),columnas.size())!=0)
            matriz.append("#");

    for(int i=0;i<mensajeCifrado.size();i++){

        string aux=mensajeCifrado.substr(i,1);
        int j=0,aux1=0;
        while(j<columnas.size()&&aux1==0){
              if(aux.at(0)==columnas.at(j)){
                aux1=(j+1)*10;
                i++;
        }
        j++;
        }
        int b=stoi(mensajeCifrado.substr(i,1));
        b+=aux1;
        descif+=matriz.at(b);
        }
        return descif;
}
