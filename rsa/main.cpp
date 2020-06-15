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
    receptor.NumALetras();
    /*RSA emisor(ZZ(401),ZZ(731));
    emisor.cifrado("HOLA");*/
    return 0;
}
