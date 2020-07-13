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
    //p=findProbablyPrimeClosest(bits);
    //q=findProbablyPrimeClosest(bits);
   p=conv<ZZ>("141435257545301438250412064134471187802631682855068281935597881626618509578670490197497124974492212725638183174309841202854496434932711318178370145103657877988072135717908745716633250829195393749616690492117171477475091270819449530713861839066025679717807767719750437879880931385063596256882148537265260242941");
   q=conv<ZZ>("160881796038177215848663852830936019953296496293559472377087350881890686986363708560349040149326004342754536988240498601570426998737558255612616504124781737697837074277022430858940485426498155443552229624898389396697140734511255782247921754292228734293251798285061257033914651651108655614304119591080746196017");
   n=p*q;
   ZZ pin((p-1)*(q-1));
   ZZ ee(1);
   e=conv<ZZ>("160881796038177215848663852830936019953296496293559472377087350881890686986363708560349040149326004342754536988240498601570426998737558255612616504124781737697837074277022430858940485426498155443552229624898389396697140734511255782247921754292228734293251798285061257033914651651108655614304119591080746195717");
   /*do{
        ee=NumeroAleatorio(bits);
   }
   while(euclides5(ee,pin)!= 1);
   e=ee;*/
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
RSA::~RSA()
{
    //dtor
}
string RSA::cifrado(string mensaje){
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
    ofstream file("cifrado.txt");///guarda mensaje cifrado
    string fin;
    for(int i=0;i<alfa.size();i+=digitos){
        ZZ num(conv<ZZ>(alfa.substr(i,digitos).c_str()));
        num=exponencial(num,e,n);
        if(ZZtoStr(num).size()<digitos+1){
                string ceros(digitos+1-ZZtoStr(num).size(),'0');
                ceros+=ZZtoStr(num);
                fin+=ceros;
        }
        else
            fin+=ZZtoStr(num);
    }
    file<<fin;
   return fin;
}

string RSA::ZZtoStr(ZZ a){
stringstream buffer;
    buffer<<a;
    string s=buffer.str();
return s;
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
    string fin;
    for(int i=0;i<st.size();i+=di){
        int pos=stoi(st.substr(i,di));
        fin+=alfabeto.at(pos);
    }
    ofstream archivo("descifrado.txt");///Mensaje descifrado
        archivo<<fin;
    return fin;
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
