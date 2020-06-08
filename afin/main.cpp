#include <iostream>
#include "afin.h"
#include <stdlib.h>
#include <time.h>
#include<string>
using namespace std;

int main()
{
    //afin receptor(409,19);
    //cout<<receptor.descifrado("PNZZQZXTG");

    afin emisor;
    cout<<emisor.cifrado("HOLA")<<endl;
    return 0;
}
