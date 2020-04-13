#include "practica1.h"
#include<string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

practica1::practica1()
{
    //ctor
}

practica1::~practica1()
{
    //dtor
}
/*1.	Convertir un objeto string a un array de tipo char, y viceversa*/
void practica1:: ToArrayChar(string palabra){
    char cadena[palabra.length()];
    palabra.copy(cadena,palabra.size());
    cout<<"[";
    for(int i=0;i<palabra.size();i++){
        cadena[i];
        cout<<cadena[i]<<",";
    }
    cout<<"]"<<endl;
    }

string practica1::ToString(char arrays[]){
    string cadena="";
    int tam=sizeof(arrays)+1;
    for(int i=0;i<tam;i++){
        cadena+=arrays[i];
    }
    return cadena;

}
/*2.	¿Cuál es la diferencia entre la función capacity y la función size de la clase string?
La diferencia es que la función capacity() retorna el tamaño actual del espacio asignado para la cadena,
 este no es necesariamente igual a la longitud de la cadena (cantidad de elementos que tiene la cadena )
  que es el valor que retorna la función size(). Si el valor que retorna la función capacity() es mayor
  es que asigna espacio  adicional para operaciones de cadena.
*/

//3.	Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.

string practica1::changeMayMin(string begi){
for(int i=0;i<begi.size();i++){
    if(begi.at(i)>=65&&begi.at(i)<=90)begi.at(i)+=32;
    else if (begi.at(i)>=97&&begi.at(i)<=122)begi.at(i)-=32;
}
return begi;
}
/*4.Recibir dos números por consola en variables tipo entero, luego construir un objeto string que concatene
el primer número seguido del segundo número. Imprimir la cadena resultante, y en una nueva línea su valor
multiplicado por 2. Usar funciones para convertir de string a entero y visceversa.*/


void practica1::IntToString(int a,int b){
    string as= to_string(a);
    string bs= to_string(b);
    string numero=as+bs;
    cout<<numero<<endl;
    int num=stoi(numero);
    cout<<num*2<<endl;
}


/*5.Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código*/

string practica1:: CantCarac(char y,int x){return string(x,y);}

/*6.Convertir la cadena: “Yo desaprobe el curso de Algebra Abstracta” a la cadena: “Yo aprobe el curso de Algebra Abstracta”. */
void practica1:: Desapruebo(){
  string a="Yo desaprobe el curso de Algebra Abstracta";
  int ind=a.find("desaprobe");
  a.replace(ind,9,"aprobe");
  cout<<a<<endl;
  }

/*7.Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.*/

int practica1::CantPalabras(string frase,string palabra){
    int i=0;
    int a=frase.find(palabra);
    while(a!=string::npos){
        i++;
        a=frase.find(palabra,a+1);
    }
return i;}
/*8.Recibir un string de longitud N e imprimir cada letra del string en una nueva línea usando iteradores.*/
void practica1::PrintLetra(string palabra){
    string::const_iterator iterador1=palabra.begin();
    while(iterador1!= palabra.end()){
        cout<<*iterador1<<endl;
        iterador1++;
    }
}
/*9.Recibir dos strings por consola e imprimir un string que tenga al segundo string en la mitad el primer string.
El primer string siempre tiene tamaño par.*/
string practica1:: UnirMitad(string palabra, string adjuntar){
     return palabra.insert((palabra.size())/2,adjuntar);
}

/*10.	Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero y
reemplazarlas por el tercer string recibido.*/

string practica1::Reemplazar(string frase,string tochange,string change){
   int a=frase.find(tochange);
   while(a!=string::npos){
    frase.replace(a,change.size(),change);
    a=frase.find(tochange,a+1);
}
return frase;
}
/*11.Dadas dos palabras, imprimir la que es lexicográficamente mayor.*/
void practica1::LexiMayor(string a, string b){
     if (a>b){
        cout<<a<<" es lexicograficamente mayor"<<endl;
     }
     else if(b>a){
        cout<<b<<" es lexicograficamente mayor"<<endl;
     }
     else cout<<a<<" y "<<b<< " son iguales"<<endl;
     }
/*12.Crear una función que reciba un número N (N va de 1 a 10),y que escriba N números con valores que van
de 1 a 1000 en un archivo llamado “numeros.txt”.*/

void practica1 ::Escribirfiles(int n){
    ofstream file;
    file.open("numeros.txt");
    for(int i=0;i<n;i++){
        int a=rand()%1000+1;
        string temp=to_string(a);
        file<<temp<<endl;
    }
    file.close();
}

/*13.	Leer los números en el archivo “numeros.txt” de la pregunta 10 e imprimir la sumatoria.*/
int practica1 ::Sumatoria(){
    int num,sum,suma=0;
    string add;
    ifstream datos("numeros.txt");
    if(datos.fail()){
        cout<<"Texto entrada ""numeros.txt"" no existe"<<endl;
    }
    else{
        while(getline(datos,add)){
            sum=stoi(add);
            suma+=sum;
        }
    cout<<suma<<endl;
}
}
/*18.7 (Cifrado simple) Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo
del cifrado de clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.*/
/*a) Escriba un programa que cifre un mensaje usando rot13.*/
string practica1::rot13(string palabra){
    for(int i=0;i<palabra.size();i++){
    if(palabra[i]>=65&&palabra[i]<=90){
        palabra[i]+=13;
       if (palabra[i]>90)
        {palabra[i]=(palabra[i]-90)+65;}

    }
    else if (palabra[i]>=97&&palabra[i]<=122){
        if(palabra[i]<110)
            palabra[i]+=13;
        else{
            palabra[i]-=13;
       }
    }
    }
    return palabra;
}
/*b) Escriba un mensaje que descifre el mensaje codiﬁ cado usando 13 como la clave.*/
string practica1::drot13(string palabra){
    for(int i=0;i<palabra.size();i++){
        if(palabra[i]>=65&&palabra[i]<=90){
            if(palabra[i]>=78)
                palabra[i]-=13;
            else{
                palabra[i]+=13;
        }
        }
        else if (palabra[i]>=97&&palabra[i]<=122){
            if(palabra[i]>=110)
                palabra[i]-=13;
            else{
                palabra[i]+=13;
           }
        }
    }
    return palabra;
}

/*c)Después de escribir los programas de los incisos (a) y (b), responda brevemente a la siguiente pregunta: si no conociera
la clave para el inciso (b), ¿qué tan difícil cree usted que sería quebrantar el código? ¿Qué pasaría si tuviera acceso
a un poder de cómputo considerable ( por ejemplo, supercomputadoras)? En el ejercicio 18.26 le pediremos que escriba un programa
para lograr esto.
Seria facil porque las posibilidades son de 1-26 (letras del abecedario) y una supercomputadora seria util porque con un bucle
probariamos hasta que la frase tenga sentido, y con las caracteristicas de la computadora las operaciones serian mas rapidas.                                                 )



*/
/*18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
nuevo objeto string*/

string practica1::ApellidosNombres(string apellidos,string nombre){
    string completo=nombre+" "+apellidos;
    return completo;
}

/*18.12Escriba un programa para jugar al ahorcado. El programa debe elegir una palabra (que se codifica directamente en el
programa, o se lee de un archivo de texto) y mostrar lo siguiente:
Adivine la palabra: XXXXXX
Cada X representa una letra. El usuario trata de adivinar las letras en la palabra. Debera mostrarse la respuesta apropiada (si
o no) despues de cada intento de adivinar. Despues de cada intento incorrecto, muestre el diagrama con otra parte del cuerpo
incluida. Después de siete intentos incorrectos, el usuario deberá colgarse. La pantalla debe tener la siguiente apariencia:

Después de cada intento de adivinar, muestre todos los intentos que hizo el usuario. Si el usuario adivina la palabra correcta-
mente, el programa debe mostrar lo siguiente:

Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no*/
string practica1::reempAhorcado(string palabra,string cifrado,string intento){
   int a=palabra.find(intento);
   while(a!=string::npos){
        cifrado.replace(a,1,intento);
        a=palabra.find(intento,a+1);
    }
    return cifrado;
}


void practica1::ahorcado(string continuar){
    bool estado=true;
    while(estado==true && continuar=="si"){
        int a=rand()%9+0;
        string palabra[]={"abstracta","algebra","hola","bien","opcion","cuaderno","hoja","ahorcado","intentos","iniciar"};
        int b=palabra[a].size();
        string cifrada(b,'X');
        string temp;
        int i=0;
        int j=1;
        string intento;
        string humano[8]={" "," O\n","/","|","\\\n"," |","\n/"," \\"};
        cout<<"Ahorcado"<<endl;
        cout<<cifrada<<endl;
        temp=cifrada;
        while(i<=7&&continuar!="no"){
            cout<<'\n'<<"Ingrese la letra: "<<endl;
            cin>>intento;
            temp=reempAhorcado(palabra[b],cifrada,intento);
            if(temp==cifrada){
                cout<<temp<<endl;
                cout<<"no es"<<endl;
                for(int i=1;i<=j;i++){
                    cout<<humano[i];
                   }
                   j++;
            }
            else if(temp==palabra[b]){
                cout<<palabra[b]<<endl;
                cout<<"Intentos: "<<i<<endl;
                cout<<"Fallados: "<<j-1<<endl;
                cout<<"Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no"<<endl;
                string cont;
                cin>>cont;
                if(cont=="no")
                    continuar=cont;
                    estado=false;
                }
            else{
                cout<<temp<<endl;
                cout<<"si es"<<endl;

                //for(int i=1;i<=j;i++){
                  //  cout<<humano[i];
                    }
        i++;
        cifrada=temp;
        }


    }

    }




/*18.19Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string*/
string practica1::InserCarcte(string palabra){
    string aster="******";
    return palabra.insert((palabra.size()/2),aster);
}

/*18.21Escriba un programa que introduzca una linea de texto, reemplace todos los signos de puntuacion con espacios y utilice
la funcion strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).*/
void practica1::Tokens(string frase){
   int a=frase.size()-1;
   int b;
    while(a){
        b=frase.find_first_of(",;.?¡¿!()-" );
        a=b;
        if(b==string::npos) {
            break;
    }
        frase.replace(a,1," ");
}
    cout<<frase<<endl;
    char * ptr1=strtok(&frase[0]," ");
    while(ptr1!=NULL){
        cout<<ptr1<<endl;
        ptr1=strtok(NULL," ");
}
}
/*18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.*/

void practica1:: Reverse(string frase){
string::reverse_iterator iterador1=frase.rbegin();
    while(iterador1!=frase.rend()){
        cout<<*iterador1;
        iterador1++;
}
}

/*18.27 Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) que ordene objetos string. Use la función
swap en su solución.*/
bool practica1::ascendente(string a,string b){
    return a<b;
}
 bool practica1::descendente(string a,string b){
    return a>b;
}
void practica1::OrdenarSeleccion(string palabra[],int tam,bool(*compara)(string, string)){
    int menorOmayor;
    for(int i=0;i<tam-1;i++){
        menorOmayor=i;
        for(int index=i+1;index<tam;index++)
            if(!(*compara)(palabra[menorOmayor],palabra[index])){
                menorOmayor=index;
            }
            swap(palabra[menorOmayor],palabra[i]);
        }
    }


void practica1::Ordenar(string palabra[],int orden,int tam){
if(orden==1)
    OrdenarSeleccion(palabra,tam,ascendente);
else
    OrdenarSeleccion(palabra,tam,descendente);
for(int i=0;i<tam;i++)
cout<<palabra[i]<<endl;

}




