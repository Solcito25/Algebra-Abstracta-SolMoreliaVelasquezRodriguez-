#include <iostream>
#include <string>
#include <fstream>
#include "viginere.h"
using namespace std;

int main()
{


    string mensaje;
    string aux;
    ifstream datos("poema.txt");
    if(datos.fail()){
        cout<<"Texto entrada ""poema.txt"" no existe"<<endl;
    }
    else
        while(getline(datos,mensaje)){
            aux+=mensaje;
            aux+='\n';
        }



    viginere emisor;
    string cifrado=emisor.cifrado(aux);
    cout<<cifrado<<endl;
    viginere receptor;
    cout<<receptor.descifrado(cifrado)<<endl;

    string mensajes="hola";
    viginere emite;
    string cif=emite.cifrado(mensajes);
    viginere recibe;
    //cout<<cif<<endl;
    cout<<recibe.descifrado(cif)<<endl;
    string tem=emite.insertarAqui(aux);
    cout<<tem<<endl;
    string temp=emite.cifrado(tem);
    cout<<temp<<endl;
    string g=recibe.descifrado(temp);
    cout<<recibe.quitarAqui(g)<<endl;
    //cout<<emite.cifrado2("abstracta");


}
