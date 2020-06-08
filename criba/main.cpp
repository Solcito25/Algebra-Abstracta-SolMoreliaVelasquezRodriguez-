#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void primos(int tam){

    vector<bool>primo(tam-1);
    primo.at(0)=true;
    for(int j=1;j<tam-1;j+=2)
        primo.at(j)=true;
    for(int j=1;(j+2)*(j+2)<tam-2;j+=2){
            while(primo.at(j)==0)
               j+=2;
        for(int k=(j+1)<<1;k<tam-1;k+=(j+2))
            primo.at(k)=false;
    }
    ofstream file("numeros.txt");
    for(int j=0,i=2;i<=tam;j++,i++){
        if(primo.at(j)){
            file<<i<<'\n';}
    }
    file.close();
}

int main()
{
    int a=1000000000;
    primos(a);
    return 0;
}
