#ifndef ALEATORIO_H
#define ALEATORIO_H
#include <iostream>
#include <bits/stdc++.h>
#define _WIN32_WINNT 0x0501
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <chrono>
#include <psapi.h>
#include <bitset>
#include<NTL/ZZ.h>
using namespace std;
using namespace NTL;
int modINT(int a,int b);
void PrintMemoryInfo(DWORD processID,vector <unsigned long> &al);
vector<int>LLenarK();
vector<int> RC4();
void DesplazamientoIzq(int num,vector<int>&c);
vector<int>DES(int bits);
ZZ NumeroAleatorio(int bits);

#endif // ALEATORIO_H
