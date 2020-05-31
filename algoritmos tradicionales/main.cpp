#include <iostream>
#include "algTradicionales.h"
#include<string>
#include "railfence.h"
using namespace std;

int main()
{
    /*algTradicionales emisor;
    string mensaje;
    getline(cin,mensaje);
    mensaje= emisor.cifradoPoly(mensaje);
    cout<<"cifrado: "<<mensaje<<endl;
    cout<<"descifrado: "<<emisor.descifradoPoly(mensaje)<<endl;*/
    railfence emisor;
    string cifrados=emisor.cifrado("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout<<"cifrado final "<<cifrados<<endl;
    //string descif=emisor.descifrado("AIQYBHJPRXZCGKOSWDFLNTVEMU");
    //cout<<descif<<endl;
}
