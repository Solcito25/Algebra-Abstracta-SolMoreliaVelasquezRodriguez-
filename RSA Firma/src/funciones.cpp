#include "funciones.h"
#include "aleatorio.h"
#include <iostream>
#include <NTL/ZZ.h>
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

ZZ exponencial(ZZ b,ZZ e,ZZ n){
    ZZ pow(1);
    do {
        if(mod(e,ZZ(2))!=ZZ(0)){
           pow=mod(b*pow,n);
        }
       b=mod(b*b,n);
       e/=2;
    }
    while(e!=ZZ(0));
   return pow;
}

bool millerRabinOdd(ZZ n,int nVeces){

    //cout<<veces<<endl;
    int firstPrimes[]={2, 3, 5, 7, 11, 13, 17};
    if(mod(n,ZZ(2))==ZZ(0)) return false;
    if(mod(n,ZZ(3))==ZZ(0)) return false;
    if(mod(n,ZZ(5))==ZZ(0)) return false;
    if(mod(n,ZZ(7))==ZZ(0)) return false;
    if(mod(n,ZZ(11))==ZZ(0)) return false;
    if(mod(n,ZZ(13))==ZZ(0)) return false;

    ZZ m = n-1;
    long k=0;
    while(mod(n,ZZ(2))==0){
        m>>=1;
        k++;
    }
    while(nVeces--){
        ZZ a(firstPrimes[nVeces-1]);///NUMERO Aleatorio entre x>1,x<n CUIDADO!!!
        ZZ t(exponencial(a,m,n));
        long j=1;
        if(t==ZZ(1)||t==ZZ(n-1))//es probablemente primo
            continue;//probablemente primo
        while(j<k){
            t=exponencial(t,ZZ(2),n);
            if(t==ZZ(1)||t!=n-1) return false;
            j++;
        }
        if(t!=n-1) return false;
    }
    return true;
}

ZZ findProbablyPrimeClosest(int bits){
    ZZ n=NumeroAleatorio(bits);
    ZZ a=mod(n,ZZ(6));
     n-=a+ZZ(5); //para obtener la forma 6n+5
     if(millerRabinOdd(n,40)) return n;
     else{
        while(true){
            n+=2;
            if(millerRabinOdd(n,7)) return n;
            n+=4;
            if(millerRabinOdd(n,7)) return n;
        }
     }
}
