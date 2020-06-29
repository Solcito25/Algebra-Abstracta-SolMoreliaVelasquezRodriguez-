#include "RSA.h"
#include "mat.h"
#include <NTL/ZZ.h>
#include<fstream>
#include <sstream>
using namespace NTL;
RSA::RSA(int bits)///Constructor del receptor
{
    ZZ p,q;
    /*string name=to_string(bits),num;
    name+="bits.txt";
    ifstream archivo(name);
    ZZ ra(aleatorio(ZZ(10)));
    for(ZZ i(0);i<ra;i++)
        getline(archivo,num);
    p=conv<ZZ>(num.c_str());
    for(ZZ i(0);i<ra;i++)
        getline(archivo,num);
    q=conv<ZZ>(num.c_str());*/
   p=conv<ZZ>("174118268575358983901619946685150996800720038706044081910630854265267030940359583434922827755641548580193890466395654468368549914559881125547103974207784204491435612766573163981454273959219817324672183336083040187285661486699888737314333340082721564924637522913806560820827816601736653930970627470824990865501");
   q=conv<ZZ>("176656997303223902095560256491598180971380732993768921435351520271158961476748001277698565063028402764520109441247809203999420881922890353371040260979842426191177375275250990256146658405602103682083965762652790303682088948560995391904786385195323037525430801172918718937212475657313929650740839978361468109599");
   n=p*q;
   ZZ pin((p-1)*(q-1));
   ZZ ee(1);
   e=6353;
   /*do{
        ee=aleatorio(pin);
   }
   while(euclides5(ee,pin)!= 1);
   e=ee;
   cout<<"p"<<p<<endl;
   cout<<"q"<<q<<endl;
   cout<<"n"<<n<<endl;
   cout<<"e"<<e<<endl;
   cout<<"pin"<<pin<<endl;*/

   d=multiplicativa(e,pin);
   cout<<"d"<<d<<endl;


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
        ZZ exp(exponencial(num,e,n));
        if(ZZtoStr(exp).size()<digitos+1){
                string ceros(digitos+1-ZZtoStr(exp).size(),'0');
                ceros+=ZZtoStr(exp);
                fin+=ceros;
        }
        else
            fin+=ZZtoStr(exp);

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

string RSA::descifrado(string mensaje){
    int di=(to_string(alfabeto.size())).size();
    string s=ZZtoStr(n),st;int digitos=s.size();
    for(int i=0;i<mensaje.size();i+=digitos){
        ZZ num(conv<ZZ>(mensaje.substr(i,digitos).c_str()));
        num=exponencial(num,d,n);
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

    //ifstream file ("cif.txt");/// contiene mensaje a descifrar
    ofstream archivo("descifrado.txt");///guarda la posicion de las letras
    /*string pos;ZZ num(1);
    while(getline(file,pos)){
            num= conv<ZZ>(pos.c_str());
            num=exponencial(num,d,n);
            archivo<<num<<endl;
        }
        file.close();
        archivo.close();*/
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
