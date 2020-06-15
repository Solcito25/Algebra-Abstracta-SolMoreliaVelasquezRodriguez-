#include "mate.h"
///#include <NTL/ZZ.h>
#include <iostream>
///using namespace NTL;
using namespace std;
mate::mate()
{
    //ctor
}

mate::~mate()
{
    //dtor
}

int mate::mod(int a,int b){
    int r=a-(b*(a/b));
    if(r<0)
        r=b+r;
    return r;
    }
int mate::ValAbs(int b){
if(b<0){
    int x=-1;
    return b*x;}
return b;

}
int mate::euclides5(int a, int b){
    int g=1;int x=2;int t;
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

int mate::extendido(int a,int n){
    int s1=1;int s2=0;
    while(n>0){
        int  q=a/n;
        int r=a-q*n;
        a=n; n=r;
        int s=s1-q*s2;
        s1=s2; s2=s;
    }
return s1;
}

int mate:: multiplicativa(int a,int n){
    int uno=1;
    if(euclides5(a,n)== uno){
        int inversa = extendido(a,n);
        if (inversa<0)
            inversa+=n;
        return inversa;
    }
    cout<<"No tiene inversa"<<endl;
}
