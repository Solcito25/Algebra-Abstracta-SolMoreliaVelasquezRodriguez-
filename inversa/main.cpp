#include <iostream>
#include <NTL/ZZ.h>
#include "inversa.h"
using namespace std;
using namespace NTL;
int main()
{
    inversa prueba;
    ZZ a(15);ZZ n(26);
    cout<<prueba.multiplicativa(a,n)<<endl;
    return 0;
}
