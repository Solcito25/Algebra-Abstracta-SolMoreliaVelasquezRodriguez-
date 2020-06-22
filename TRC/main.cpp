#include <iostream>
#include<fstream>
#include<string>
#include <NTL/ZZ.h>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;
ZZ mod(ZZ a,ZZ b){
    ZZ r=a-(b*(a/b));
    if(r<0)
        r=b+r;
    return r;
    }
ZZ ValAbs(ZZ b){
if(b<0){
    ZZ x(-1);
    return b*x;}
return b;

}
ZZ euclides5(ZZ a, ZZ b){
    ZZ g(1);ZZ x(2);ZZ t;
    while (mod(a,x)==0&&mod(b,x)==0){
        a=a>>=1;b=b>>=1;g=2*g;
    }
    while(a!=0){
        while(mod(a,x)==0)a>>=1;
        while(mod(b,x)==0)b>>=1;
        t=((ValAbs(a-b))>>1);
        if(a>=b)a=t;
        else b=t;
    }
    return g*b;
    }

ZZ extendido(ZZ a,ZZ n){
    ZZ s1(1);ZZ s2(0);
    while(n>0){
        ZZ  q(a/n);
        ZZ r(a-q*n);
        a=n; n=r;
        ZZ s(s1-q*s2);
        s1=s2; s2=s;
    }
return s1;
}

ZZ multiplicativa(ZZ a,ZZ n){
    ZZ uno(1);
    if(euclides5(a,n)== uno){
        ZZ inversa(extendido(a,n));
        if (inversa<0)
            inversa+=n;
        return inversa;
    }
    cout<<"No tiene inversa"<<endl;
}

void Resto_Chino(){
ifstream archivo("datos.csv");
    Vec<ZZ> ecuaciones;
    string line;
    while(getline(archivo,line)){
        for(long i=0,j=line.find(",",i+1);j!=string::npos;i=j,j=line.find(",",++i))
            ecuaciones.append(conv<ZZ>((line.substr(i,j-i)).c_str()));
    }
    for(long i=0;i<ecuaciones.length();i+=3){
        if(ecuaciones.at(i)!=1)
            ecuaciones.at(i+1)=multiplicativa(ecuaciones.at(i),ecuaciones.at(i+2))*ecuaciones.at(i+1);
        }
    Vec<ZZ> pi;
    pi.append(ecuaciones.at(2));
    ZZ P(1);
    for(long i=5,j=0;i<ecuaciones.length();i+=3,j++)
        pi.append(ecuaciones.at(i));
    for(long i=0;i<pi.length();i++){
       for(long j=i+1;j<pi.length();j++){
           //ZZ mcd(euclides5(pi.at(i),pi.at(j)));
           if(euclides5(pi.at(i),pi.at(j))!= ZZ(1)){
              cout<<"No hay solucion porque no son coprimos"<<endl;return;}
    }
            P*=pi.at(i);}

    Vec<ZZ> Pi;Vec<ZZ> qi;
      for(long i=0;i<pi.length();i++){
         Pi.append(P/pi.at(i));
         qi.append(mod(multiplicativa(mod(Pi.at(i),pi.at(i)),pi.at(i)),pi.at(i)));
      }
    ZZ xo(0);
    for(long i=1,j=0;i<ecuaciones.length();i+=3,j++)
        xo+=mod(mod(ecuaciones.at(i),P)*Pi.at(j)*qi.at(j),P);

    xo=mod(xo,P);

    cout<<"X= "<<xo<<"+"<<P<<"k"<<endl;
}

int main()
{
    Resto_Chino();
}
