#include "vig.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
vig::vig()
{
    //ctor
}

vig::~vig()
{
    //dtor
}
int vig:: finds(vector<string> vec,string buscando){
    for(int pos=0;pos<vec.size();pos++)
        if(vec[pos]==buscando) return pos;
    return string::npos;
}
string vig::cifrado(){
    string mensaje=leermensaje("mensaje");
    string cifrado;
    for(int i=0;i<mensaje.size();i++){
        int a=finds(alfabeto,mensaje.substr(i,1));
        int b=finds(alfabeto,clave.substr(i%clave.size(),1));
        int pos=(a+b)-2*iniAlfa;
        if(pos>=alfabeto.size()-iniAlfa)
            pos%=alfabeto.size()-iniAlfa;
        cifrado+=alfabeto.at(pos+iniAlfa);
        cifrado+='\n';
    }
    guardarmensaje(cifrado,"cifrado");
return cifrado;
}
void vig::guardarmensaje(string mensaje, string doc){
    ofstream file;
    file.open(doc+".txt");
    file<<mensaje;
    file.close();
}
string vig::leermensaje(string archivo){
string mensaje,aux;
ifstream datos(archivo+".txt");
    if(datos.fail()){
        cout<<"Texto entrada "".txt"" no existe"<<endl;
    }
    else
        while(getline(datos,mensaje))
            aux+=mensaje;

return aux;
}
string vig::descifrado(){
    string cifrado;
    string descifrado;
    ifstream datos("cifrado.txt");
    while(!datos.eof())
        datos>>cifrado;
    for(int i=0;i<cifrado.size();i++){
        int a=finds(alfabeto,clave.substr(i%clave.size(),1));
        int b=finds(alfabeto,cifrado);
        int pos=(a-b)-iniAlfa;
        if(pos<iniAlfa)
            pos+=(alfabeto.size()-iniAlfa);
        else if(pos>=alfabeto.size()-iniAlfa)
             pos%=(alfabeto.size()-iniAlfa);
        descifrado+=alfabeto.at(pos);
        descifrado+='\n';

}
guardarmensaje(descifrado,"descifrado");
return descifrado;
}
