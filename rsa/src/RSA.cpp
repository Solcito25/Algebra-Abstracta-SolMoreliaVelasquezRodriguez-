#include "RSA.h"
#include "mat.h"
#include <NTL/ZZ.h>
#include<fstream>
using namespace NTL;
RSA::RSA()
{
   ZZ p(17);
   ZZ q(43);
   n=p*q;
   ZZ pin((p-1)*(q-1));
   ZZ ee(1);mat mcd;
   do{
        ee=aleatorio(pin);
   }
   while(mcd.euclides5(ee,pin)!= 1 && ee<pin);
   e=ee;
   d=mcd.multiplicativa(e,pin);
}
ZZ RSA::aleatorio(ZZ lim){
    srand (time(NULL));    mat mcd;
    return mcd.euclides5(ZZ(rand()),lim-1)+1;
}
RSA::RSA(ZZ E,ZZ N){
    n=N;
    e=E;
}
RSA::~RSA()
{
    //dtor
}
void RSA::cifrado(string mensaje){
    ofstream file("cifrado.txt");
    for(int i=0;i<mensaje.size();i++){
        int P=alfabeto.find(mensaje.at(i));
        mat expo;
        file<<expo.exponencial(ZZ(P),e,n);
    }
}


void RSA::descifrado(){
    ifstream file ("cif.txt");
    string pos;ZZ num(1);
    while(getline(file,pos)){
            num= conv<ZZ>(pos.c_str());
            mat expo;
            num=expo.exponencial(num,d,n);
            cout<<num<<endl;
        }
}
