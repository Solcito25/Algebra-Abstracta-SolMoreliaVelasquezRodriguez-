#include "kasiski.h"
#include <vector>
using namespace std;
kasiski::kasiski()
{
    //ctor
}

kasiski::~kasiski()
{
    //dtor
}

int kasiski:: mcd (vector<int>a){
int residuo,mcd,tam=a.size(),i=0;
//numero=a[i];
for(i;i<tam;i++){
    if(i==0)
        mcd=a[0];
    do{
       residuo=mcd%a[i];
       mcd=a[i];
       a[i]=residuo;
    }

    while(residuo!=0);
}
return mcd;
}
