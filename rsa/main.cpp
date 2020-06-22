#include <iostream>
#include "mat.h"
#include "RSA.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
int main()



{
    RSA receptor;
    receptor.descifrado();
    //receptor.NumALetras();
    /*RSA emisor(ZZ(33091),ZZ(36089));
    emisor.cifrado("s");*/



    return 0;
}
