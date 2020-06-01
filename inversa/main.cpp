#include <iostream>
#include <NTL/ZZ.h>
#include "inversa.h"
using namespace std;
using namespace NTL;
int main()
{
    inversa prueba;
    ZZ a(61);ZZ n(89);
    cout<<prueba.multiplicativa(a,n)<<endl;
    return 0;
}
