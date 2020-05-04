#include "Vigenere.h"
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
Vigenere::Vigenere(vector<string> alfa)
{
    alfabeto=alfa;
}
Vigenere::Vigenere(){



}
Vigenere::~Vigenere()
{
    //dtor
}
int Vigenere:: finds(vector<string> vec,string buscando){
    for(int pos=0;pos<vec.size();pos++)
        if(vec[pos]==buscando) return pos;
    return string::npos;
}
void Vigenere:: guardarcifrado(string cifrado){
    ofstream archivo("cifrado.txt");
    archivo<<cifrado;
    archivo.close();
}
void Vigenere::guardardescifrado(string descifrado){
    ofstream archivo("descifrado.txt");
    archivo<<descifrado;
    archivo.close();
}
string leermensaje(){
    string mensajes;
    ifstream archivo("mensaje.txt");
    archivo>>mensajes;
    archivo.close();
    return mensajes;
}

string Vigenere::cifrado(string mensaje){
    string cifrado;
    int aux;
    for(int i=0;i<mensaje.size();i++){
        int a=finds(alfabeto,mensaje.substr(i));
        int b=finds(alfabeto,clave.substr(i%clave.size()));
        if(a!=string::npos && b!=string::npos){
        int pos=(a+b)-2*iniAlfa;
        if(pos>=alfabeto.size()-iniAlfa)
            pos%=alfabeto.size()-iniAlfa;
        cifrado+=alfabeto.at(pos);
        }
        else
            cifrado+=mensaje.at(i);
    }
return cifrado;
}

string Vigenere::descifrado(string cifrado){
    string descifrado;
    for(int i=0;i<cifrado.size();i++){
        int a=finds(alfabeto,clave.substr(i%clave.size()));
        int b=finds(alfabeto,cifrado.substr(i));
        if(a!=string::npos && b!=string::npos){
        int pos=(a-b)-2*iniAlfa;
        if(pos<0)
            pos+=alfabeto.size();
        else if(pos>=alfabeto.size()-iniAlfa)
             pos%=alfabeto.size()-iniAlfa;
        descifrado+=alfabeto.at(pos);
        }
        else
            descifrado+=cifrado.at(i);

}
return descifrado;
}
