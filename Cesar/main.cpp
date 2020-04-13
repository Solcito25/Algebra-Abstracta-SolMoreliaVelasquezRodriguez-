#include <iostream>
#include <string>
#include "cesar.h"
using namespace std;

int main()
{
    string mensaje;
    cout<<"Ingrese mensaje a cifrar"<<endl;
    getline(cin,mensaje);
    cesar emisor,receptor;
    emisor.cifrado(mensaje);
    receptor.descifrado(emisor.cifrado(mensaje));
}
