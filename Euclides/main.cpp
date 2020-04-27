#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;
#include "euclides.h"

int main()
{
    euclides pro;
    ZZ a, b;

    cin >> a;
    cin >> b;


    cout << "Algoritmo 1 \n";
    cout <<"MCD "<<pro.euclides1(a,b)<<"\n";
    cout << "Algoritmo 2 \n";
    cout <<"MCD "<<pro.euclides2(a,b)<<"\n";
    cout << "Algoritmo 3 \n";
    cout <<"MCD "<<pro.euclides3(a,b)<<"\n";
    cout << "Algoritmo 4 \n";
    cout <<"MCD "<<pro.euclides4(a,b)<<"\n";
    cout << "Algoritmo 5 \n";
    cout <<"MCD "<<pro.euclides5(a,b)<<"\n";
    cout << "Algoritmo 6 \n";
    cout <<"MCD "<<pro.euclides6(a,b)<<"\n";
    cout << "Algoritmo 7 \n";
    cout <<"MCD "<<pro.euclides7(a,b)<<"\n";
    cout << "Algoritmo 8 \n";
    cout <<"MCD "<<pro.euclides8(a,b)<<"\n";
    return 0;
}
