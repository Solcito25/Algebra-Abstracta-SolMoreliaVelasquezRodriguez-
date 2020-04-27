#include "kasiski.h"
#include <vector>
#include<string>
#include <iostream>
using namespace std;

kasiski::kasiski()
{
    //ctor
}

kasiski::~kasiski()
{
    //dtor
}


string kasiski::Ataque(string mensaje){
    string clave;
    vector <int> distancias=distanciaSecuenciasRepetidas(mensaje);
    int lenClave=mcd(distancias);
    vector <string> subcadenas=divCadena(lenClave,mensaje);
    for(int i=0;i<subcadenas.size();i++)
        clave+=analisisFrecuenciasClave(subcadenas[i]);


    return clave;
}

vector <int> kasiski::distanciaSecuenciasRepetidas(string mensaje){
    string strRepetida=mensaje.substr(0,3);
    vector <string> cadenasRepetidas;
    vector <int> distancias;
    for (int i=0;i<mensaje.size()-3;i++){
        size_t finder=mensaje.find(strRepetida,i+1);
        if (finder!=string::npos){
            cadenasRepetidas.push_back(strRepetida);
            distancias.push_back(finder-i);
        }
        strRepetida=mensaje.substr(i+1,3);
    }

    return distancias;
}

int kasiski::mcd (vector<int>a){
    int residuo,mcd,tam=a.size(),i=0;
    for(i;i<tam;i++){
        if(i==0)
            mcd=a[0];
        do{
           residuo=mcd%a[i];
           mcd=a[i];
           a[i]=residuo;
        }

        while(residuo!=0);
    }
    return mcd;
}

//ir buscando bucle cadenas de 3 char
vector <string> kasiski::divCadena(int noSubcadenas,string mensaje){
    vector <string> subcadenas(noSubcadenas);
    int tam=mensaje.size();
    for(int i=0;i<tam/noSubcadenas;i++){
        for(int j=0;j<noSubcadenas;j++){
            subcadenas[j]+=mensaje[(i*noSubcadenas+j)];
        }
    }
    int residuo=(tam%noSubcadenas);
    if(residuo){
        for (int i=0;i<residuo;i++){
            subcadenas[i]+=mensaje[tam-residuo+i];
        }
    }

    return subcadenas;
}

vector<int> kasiski::frecuencia(string mensaje){
    vector <int> frecuent(alfabeto.size());
    for (int i=0;i<frecuent.size();i++){
        frecuent[i]=contInString(alfabeto.substr(i,1),mensaje);
        //cout<<"Frecuencia en mensaje: "<<alfabeto[i]<<" "<<frecuent[i]<<endl;//FUNCIONA
    }
    return frecuent;
}

int kasiski::contInString(string buscar, string mensaje){
    int cont=0;
    size_t finder=mensaje.find(buscar);
    while (finder!=string::npos){
        cont++;
        finder=mensaje.find(buscar,finder+1);
    }
    return cont;
}
//Cambio de valor de 10 a 11
string kasiski::analisisFrecuenciasClave(string mensaje){
    int posFrecuent[]={0,4,11+4};
    vector <int> arr(alfabeto.size());
    vector <int> suma(alfabeto.size());
    arr=frecuencia(mensaje);
    for (int i=0;i<alfabeto.size();i++){
        suma[i]=arr[(i+posFrecuent[0])%alfabeto.size()];
        suma[i]+=arr[(i+posFrecuent[1])%alfabeto.size()];
        suma[i]+=arr[(i+posFrecuent[2])%alfabeto.size()];
    }
    int mayPos=findPosMayor(suma);
    ;
    return alfabeto.substr(mayPos,1);
}

int kasiski::findPosMayor(vector <int> arr){
    int posMay=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[posMay]) posMay=i;

    }


    return posMay;
}
