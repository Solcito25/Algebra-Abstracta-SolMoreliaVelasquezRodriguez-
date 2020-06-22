#include "RSA.h"
#include "mat.h"
#include <NTL/ZZ.h>
#include<fstream>
using namespace NTL;
RSA::RSA()///Constructor del receptor
{
   ZZ p(104651);
   ZZ q(104659);
   n=p*q;
   ZZ pin((p-1)*(q-1));
   ZZ ee(1);mat mcd;
   e=13301;
   /*do{
        ee=aleatorio(pin);
   }
   while(mcd.euclides5(ee,pin)!= 1);
   e=ee;
   cout<<"n"<<n<<endl;
   cout<<"e"<<e<<endl;
   cout<<"pin"<<pin<<endl;*/

   d=mcd.multiplicativa(e,pin);
   cout<<"d"<<d<<endl;

}
ZZ RSA::aleatorio(ZZ lim){
    srand (time(NULL));    mat mcd;
    return mcd.mod(ZZ(rand()),lim-1)+1;
}
RSA::RSA(ZZ E,ZZ N){///Constructor del emisor
    n=N;
    e=E;
}
RSA::~RSA()
{
    //dtor
}
void RSA::cifrado(string mensaje){
    ofstream file("cifrado.txt");///guarda mensaje cifrado
    for(int i=0;i<mensaje.size();i++){
        int P=alfabeto.find(mensaje.at(i));
        mat expo;
        file<<expo.exponencial(ZZ(P),e,n)<<endl;
    }
}


void RSA::descifrado(){
    ifstream file ("cif.txt");/// contiene mensaje a descifrar
    ofstream archivo("descifrado.txt");///guarda la posicion de las letras
    string pos;ZZ num(1);
    while(getline(file,pos)){
            num= conv<ZZ>(pos.c_str());
            mat expo;
            num=expo.exponencial(num,d,n);
            archivo<<num<<endl;
        }
        file.close();
        archivo.close();
}

void RSA::NumALetras(){
    ifstream file("descifrado.txt");
    string linea;
    while(getline(file,linea)){
        int pos=stoi(linea);
        cout<<alfabeto.at(pos);
    }
    file.close();
}
