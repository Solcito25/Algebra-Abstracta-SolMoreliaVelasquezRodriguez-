#include <iostream>
#include "mat.h"
#include "RSA.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
int main()
{
    RSA emisor(ZZ(101),ZZ(731));
    emisor.cifrado("TI");
    return 0;
}
