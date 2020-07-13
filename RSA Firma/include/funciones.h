#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ mod(ZZ a,ZZ b);
ZZ ValAbs(ZZ b);
ZZ euclides5(ZZ a, ZZ b);

ZZ extendido(ZZ a,ZZ n);

ZZ multiplicativa(ZZ a,ZZ n);

ZZ exponencial(ZZ b,ZZ e,ZZ n);
bool millerRabinOdd(ZZ n,int nVeces);
ZZ findProbablyPrimeClosest(int bits);
#endif // FUNCIONES_H
