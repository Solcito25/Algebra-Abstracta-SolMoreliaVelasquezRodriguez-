#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "viginere.h"
#include "kasiski.h"
using namespace std;
string kasiski::alfabeto="ABCDEFGHIJKLMÑNOPQRSTUVWXYZ";

int main()
{


    string mensaje;
    string aux;
    ifstream datos("poema.txt");
    if(datos.fail()){
        cout<<"Texto entrada ""poema.txt"" no existe"<<endl;
    }
    else
        while(getline(datos,mensaje)){
            aux+=mensaje;
            //aux+='\n';
        }



    viginere emisor;
    string cifrado=emisor.cifrado(aux);
    cout<<cifrado<<endl;
    viginere receptor;
    cout<<receptor.descifrado(cifrado)<<endl;

    //string mensajes="The MEgraph application used to display this network combines techniques such as topological range searching and motion highlighting to enable interactive exploration of complex network diagrams";
    /*string hola="hola";
    viginere emite;
    string cif=emite.cifrado(hola);
    cout<<cif<<endl;*/

    //string maria=" vrWaluurxnM 5xnwu UiDCCJsC4zkNr3Hmlb3sfFuEQf-hICuDIgkq tGOeHPxvcFehhT5iZmq2auRELPM4AoDooq 1GtoDEF HveGcF9m7Z1dCuiemc3-LDGXvozonFG3oAFEYFnrspv Ges5Q12Scr4t8cByKPRFlDvEADgkq FJFxPCiIwMijrC90Fl6cl";
    //cout<<emite.descifrado(maria);
   //viginere recibe;
    //cout<<cif<<endl;
    //cout<<recibe.descifrado(cif)<<endl;
    //string tem=emite.insertarAqui(aux);
    //cout<<tem<<endl;
    /*string temp=emite.cifrado(tem);
    cout<<temp<<endl;
    string g=recibe.descifrado(temp);
    cout<<recibe.quitarAqui(g)<<endl;
    //cout<<emite.cifrado2("abstracta");
/*vector <int> A={42,141,39};
kasiski pro;
cout<<pro.mcd(A)<<endl;*/


//string alfabetoASCII=" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_´abcdefghijklmnopqrstuvwxyz{|}~ßÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜø£Ø×ƒáíóúñÑªº¿";


/*viginere emisor(ascii);
//string mensaje="dia";
string cif=emisor.cifrado(aux);
cout<<cif<<endl;
cout<<emisor.descifrado(cif)<<endl;

*/
//kasiski prueba;
//cout<<prueba.Ataque("LNUDVMUYRMUDVLLPXAFZUEFAIOVWVMUOVMUEVMUEZCUDVSYWCIVCFGUCUNYCGALLGRCYTIJTRNNPJQOPJEMZITYLIAYYKRYEFDUDCAMAVRMZEAMBLEXPJCCQIEHPJTYXVNMLAEZTIMUOFRUFC");

}


