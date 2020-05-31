#include "euclides.h"
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;
euclides::euclides()
{
    //ctor
}

euclides::~euclides()
{
    //dtor
}
ZZ euclides::mod(ZZ a,ZZ b){
    ZZ r=a-(b*(a/b));
    if(r<0)
        r=b-r;
    return r;
    }
ZZ euclides::ValAbs(ZZ b){
if(b<0){
    ZZ x(-1);
    return b*x;}
return b;

}
ZZ euclides::euclides1(ZZ a,ZZ b){
ZZ r=mod(a,b);
    do{
        cout<<" a "<<a<<" b "<<b<<endl;
        a=b;
        b=r;
        r=mod(a,b);
            }

    while(r!=0);
    return b;
}
ZZ euclides::euclides2(ZZ a,ZZ b){
    ZZ r=mod(a,b);
    do{
        cout<<" a "<<a<<" b "<<b<<endl;
        if(r>b/2)
        r=b-r;
        a=b;
        b=r;
        r=mod(a,b);
    }
    while(r!=0);
    return b;
}
ZZ euclides::euclides3 (ZZ a, ZZ b){
    if(b==0)
        return a;
    cout<<" a "<<a<<" b "<<b<<endl;
    return euclides3(b,mod(a,b));
}
ZZ euclides::euclides4(ZZ a, ZZ b){
ZZ x(2);
cout<<" a "<<a<<"    "<<" b "<<b<<endl;
if(ValAbs(b)>ValAbs(a))return euclides4(b,a);
else if (b==0) return a;
else if(mod(a,x)==0&&mod(b,x)==0){return 2*(euclides4(a>>1,b>>1));cout<<" a "<<a<<"    "<<" b "<<b<<endl;}
else if(mod(a,x)==0&&mod(b,x)!=0){return euclides4(a>>1,b);cout<<" a "<<a<<"    "<<" b "<<b<<endl;}
else if(mod(a,x)!=0&&mod(b,x)==0){return euclides4(a,b>>1);cout<<" a "<<a<<"    "<<" b "<<b<<endl;}
else {return euclides4((ValAbs(a)- ValAbs(b))>>1,b);cout<<" a "<<a<<"    "<<" b "<<b<<endl;}

}
ZZ euclides::euclides5(ZZ a, ZZ b){
ZZ g(1);ZZ x(2);ZZ t;
while (mod(a,x)==0&&mod(b,x)==0){
    a=a>>=1;b=b>>=1;g=2*g;
    cout<<" a "<<a<<" b "<<b<<" g "<<g<<endl;
}
while(a!=0){
    while(mod(a,x)==0){a>>=1;
    cout<<" a "<<a<<" b "<<b<<" t "<<t<<endl;
    }
    while(mod(b,x)==0){b>>=1;
    cout<<" a "<<a<<" b "<<b<<" t "<<t<<endl;
    }
    t=((ValAbs(a-b))>>1);
    if(a>=b)a=t;
    else b=t;
    cout<<" a "<<a<<" b "<<b<<" t "<<t<<endl;
}
//cout<<a<<"    "<<b<<endl;
return g*b;

}

ZZ euclides::euclides6(ZZ a, ZZ b){
    cout<<"r1"<<"    "<<"r2"<<endl;
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
       cout<<" a "<<a<<" b "<<b<<endl;
    }

return a;
}
ZZ euclides::euclides7(ZZ a,ZZ b){
    ZZ r(mod(a,b));
    if(r==0)return b;
    cout<<" a "<<a<<" b "<<b<<endl;
    return euclides7(b,r);
}
ZZ euclides::euclides8(ZZ a,ZZ b){
while(b>0){
    ZZ q(a/b);
    ZZ r(a-q*b);
    a=b;b=r;
    cout<<" a "<<a<<" b "<<b<<endl;
}
return a;
}
