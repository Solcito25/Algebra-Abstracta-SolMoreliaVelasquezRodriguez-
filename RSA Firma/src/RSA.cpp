#include "RSA.h"
#include "funciones.h"
#include "aleatorio.h"
#include <NTL/ZZ.h>
#include<fstream>
#include <sstream>
using namespace NTL;
RSA::RSA(int bits)///Constructor del receptor
{
    //ZZ p,q;
    p=findProbablyPrimeClosest(bits);
    q=findProbablyPrimeClosest(bits);
   /*p=conv<ZZ>("");
   q=conv<ZZ>("");*/
   n=p*q;
   ZZ pin((p-1)*(q-1));
   ZZ ee(1);
   //e=conv<ZZ>("");
   do{
        ee=NumeroAleatorio(bits);
   }
   while(euclides5(ee,pin)!= 1);
   e=ee;
   cout<<"p "<<p<<endl;
   cout<<"q "<<q<<endl;
   cout<<"n "<<n<<endl;
   cout<<"e "<<e<<endl;
   cout<<"pin "<<pin<<endl;

   d=multiplicativa(e,pin);
   cout<<"d "<<d<<endl;
}

ZZ RSA::aleatorio(ZZ lim){
    srand (time(NULL));
    return mod(ZZ(rand()),lim-1)+1;
}
RSA::RSA(ZZ E,ZZ N){///Constructor del emisor
    n=N;
    e=E;
}

string RSA::completarCeros(string mensaje, ZZ nr){
    int digit =ZZtoStr(nr).size()-1;
    int c = modINT(mensaje.size(),digit);
    string cero(digit-c,'0');
    return cero+mensaje;
}
string RSA:: bloques(string mensaje){
    int di=(to_string(alfabeto.size())).size();
    string alfa;string extra="22";
    string s=ZZtoStr(n);int digitos=s.size()-1;
    for(int i=0;i<mensaje.size();i++){
        int P=alfabeto.find(mensaje.at(i));
            if(to_string(P).size()<di){
                string ceros(di-to_string(P).size(),'0');
                ceros+=to_string(P);
                alfa+=ceros;
                }
             else
                alfa+=to_string(P);
    }

    while(mod(ZZ(alfa.size()),ZZ(digitos))!=ZZ(0)){
        alfa+=extra;
    }
    return alfa;
}
string RSA::cifrado(string mensaje,ZZ nr,ZZ er){
    //string bloque=bloques(mensaje);

    string s=ZZtoStr(nr);int digitos=s.size()-1;
    string fin;
    for(int i=0;i<mensaje.size();i+=digitos){
        ZZ num(conv<ZZ>(mensaje.substr(i,digitos).c_str()));
        num=exponencial(num,er,nr);
        if(ZZtoStr(num).size()<digitos+1){
                string ceros(digitos+1-ZZtoStr(num).size(),'0');
                ceros+=ZZtoStr(num);
                fin+=ceros;
        }
        else
            fin+=ZZtoStr(num);

    }

   return fin;
}

string RSA::ZZtoStr(ZZ a){
stringstream buffer;
    buffer<<a;
    string s=buffer.str();
return s;
}

string RSA::cifroConD(string msg){

    string s=ZZtoStr(n);int digitos=s.size()-1;
    string fin;
    for(int i=0;i<msg.size();i+=digitos){
        ZZ num(conv<ZZ>(msg.substr(i,digitos).c_str()));
        num=exponencial(num,d,n);
        if(ZZtoStr(num).size()<digitos+1){
                string ceros(digitos+1-ZZtoStr(num).size(),'0');
                ceros+=ZZtoStr(num);
                fin+=ceros;
        }
        else
            fin+=ZZtoStr(num);
    }

    return fin;
}

string RSA::firmarCifrar(string msgl,ZZ nr,ZZ er){
    ofstream file("cifrado.txt");///guarda mensaje cifrado
    string rubrica=cifroConD(bloques(msgl));
    rubrica=completarCeros(rubrica,nr);
    string ciffir=cifrado(rubrica,nr,er);
    file<<ciffir;
    return ciffir;
}
ZZ RSA::TRC(ZZ num){
    /// dp = mod(d,p-1) dq = mod(d,q-1)
    /// Clase de equivalencia de num en p mod(num,p)
    /// Clase de equivalencia de num en p mod(num,q)
    /// P1=q P2=pexp
    ZZ q1(multiplicativa(mod(q,p),p));
    ZZ q2(multiplicativa(mod(p,q),q));
    ZZ a1(exponencial(mod(num,p),mod(d,p-1),p));/// num^dp mod p
    ZZ a2(exponencial(mod(num,q),mod(d,q-1),q)); /// num^dq mod q
    return mod(mod(a1*q*q1,n)+mod(a2*p*q2,n),n);/// D= mod(x1+x2,n) +n*kComo k=0, el valor de n se anula

}

string RSA::descifrado(string mensaje){
    int di=(to_string(alfabeto.size())).size();
    string s=ZZtoStr(n),st;int digitos=s.size();
    for(int i=0;i<mensaje.size();i+=digitos){
        ZZ num(conv<ZZ>(mensaje.substr(i,digitos).c_str()));
        num=TRC(num);
        if(ZZtoStr(num).size()<digitos-1){
                string ceros(digitos-1-ZZtoStr(num).size(),'0');
                ceros+=ZZtoStr(num);
                st+=ceros;
        }
        else
            st+=ZZtoStr(num);
    }


    return st;
}
string RSA::descifroConE(string mensaje, ZZ nr, ZZ er){
    int a= modINT(mensaje.size(),ZZtoStr(nr).size());
    mensaje = mensaje.substr(a);
    cout<<mensaje<<endl;
    int di=(to_string(alfabeto.size())).size();
    string s=ZZtoStr(nr),st;int digitos=s.size();
    for(int i=0;i<mensaje.size();i+=digitos){
        ZZ num(conv<ZZ>(mensaje.substr(i,digitos).c_str()));
        num=exponencial(num,er,nr);
        if(ZZtoStr(num).size()<digitos-1){
                string ceros(digitos-1-ZZtoStr(num).size(),'0');
                ceros+=ZZtoStr(num);
                st+=ceros;
        }
        else
            st+=ZZtoStr(num);
    }

    string letters;
    for(int i=0;i<st.size();i+=di){
        letters+=alfabeto.at(stoi(st.substr(i,di)));
    }

    return letters;
    //return salida;
}

string RSA::DescifrarFirma(string msgn,ZZ nr, ZZ er){
    string des=descifrado(msgn);
    string desc=descifroConE(des,nr,er);
    ofstream archivo("descifrado.txt");///Mensaje descifrado
        archivo<<desc;
    return desc;
}

/*void RSA::NumALetras(){
    ifstream file("descifrado.txt");
    string linea;
    while(getline(file,linea)){
        int pos=stoi(linea);
        cout<<alfabeto.at(pos);
    }
    file.close();
}*/
