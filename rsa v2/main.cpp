#include <iostream>
#include "mat.h"
#include "RSA.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
int main()



{
    /*ZZ a,b;
    cin>>a>>b;*/
    RSA receptor(1024);
    cout<<receptor.descifrado("023403530811005403060545");
    //receptor.NumALetras();
    /*RSA emisor(a,b);
    cout<<emisor.cifrado("COMEHERE");*/



    return 0;
}
