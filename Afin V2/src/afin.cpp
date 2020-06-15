#include "afin.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
using namespace std;
afin::afin()
{
   GenerarClaves();
}
afin::afin(int x,int y)
{
    mate inversa;
    a=inversa.multiplicativa(x,alfabeto.size());
    b=y;
}
afin::~afin()
{
    //dtor
}
int afin::aleatorio(){
    srand (time(NULL));
    int num = rand() % 500 + 1;
    return num;
}
void afin::GenerarClaves(){
    mate modu;
    b=modu.mod(aleatorio(),alfabeto.size());int aa;
    do{
       aa=modu.mod(aleatorio(),alfabeto.size());
    }while(modu.euclides5(aa,alfabeto.size())!=1);
    a=aa;
}

string afin::cifrado(string mensaje){
    cout<<"a"<<a<<endl;
    cout<<"b"<<b<<endl;
    string cifrado;mate modu;
    for(int i=0;i<mensaje.size();i++){
        int m=alfabeto.find(mensaje.at(i));
        int posc=modu.mod(a*m+b,alfabeto.size());
        cifrado+=alfabeto.at(posc);
    }
    return cifrado;
}

string afin::descifrado(string cif){
string descifrado;mate modu;
    for(int i=0;i<cif.size();i++){
        int m=alfabeto.find(cif.at(i));
        int posc=modu.mod(a*(m-b),alfabeto.size());
        descifrado+=alfabeto.at(posc);
    }
    return descifrado;
}
