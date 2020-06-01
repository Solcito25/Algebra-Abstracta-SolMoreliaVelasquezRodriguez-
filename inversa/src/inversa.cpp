#include "inversa.h"
#include <NTL/ZZ.h>
#include <iostream>
using namespace NTL;
using namespace std;
inversa::inversa()
{
    //ctor
}

inversa::~inversa()
{
    //dtor
}

ZZ inversa::mod(ZZ a,ZZ b){
    ZZ r=a-(b*(a/b));
    if(r<0)
        r=b+r;
    return r;
    }
ZZ inversa::ValAbs(ZZ b){
if(b<0){
    ZZ x(-1);
    return b*x;}
return b;

}
ZZ inversa::euclides5(ZZ a, ZZ b){
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

ZZ inversa::extendido(ZZ a,ZZ n){
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

ZZ inversa:: multiplicativa(ZZ a,ZZ n){
    ZZ uno(1);
    if(euclides5(a,n)== uno){
        ZZ inversa(extendido(a,n));
        if (inversa<0)
            inversa+=n;
        return inversa;
    }
    cout<<"No tiene inversa"<<endl;
}
