#include <iostream>
#include "practica1.h"
#include<string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

using namespace std;

int main()
{
    practica1 str;
    /**/
    /*1.	Convertir un objeto string a un array de tipo char, y viceversa*/
    //str.ToArrayChar("holaaa");
    /*char cadena[]={'h','o','l','a','s'};
    cout<<str.ToString(cadena)<<endl;

    /*2.	¿Cuál es la diferencia entre la función capacity y la función size de la clase string?
        La diferencia es que la función capacity() retorna el tamaño actual del espacio asignado para la cadena,
        este no es necesariamente igual a la longitud de la cadena (cantidad de elementos que tiene la cadena )
        que es el valor que retorna la función size(). Si el valor que retorna la función capacity() es mayor
        es que asigna espacio  adicional para operaciones de cadena.*/

    //3.	Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.
    /*cout<<str.changeMayMin("GSgjgk HGFhgfWd")<<endl;*/

    /*4.Recibir dos números por consola en variables tipo entero, luego construir un objeto string que concatene
        el primer número seguido del segundo número. Imprimir la cadena resultante, y en una nueva línea su valor
        multiplicado por 2. Usar funciones para convertir de string a entero y visceversa.*/

    //str.IntToString(1,9);
    /*5.Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código*/
    //cout<<str.CantCarac('a',1000)<<endl;

    /*6.Convertir la cadena: “Yo desaprobe el curso de Algebra Abstracta” a la cadena: “Yo aprobe el curso de Algebra Abstracta”. */
    //str.Desapruebo();

    /*7.Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.*/
    /*string frase;
    cout<<"Ingrese la frase: ";
    getline(cin,frase);
    cout<<str.CantPalabras(frase,palabra);*/
    /*8.Recibir un string de longitud N e imprimir cada letra del string en una nueva línea usando iteradores.
    str.PrintLetra("Algebra Abstracta");*/

    /*9.Recibir dos strings por consola e imprimir un string que tenga al segundo string en la mitad el primer string.
        El primer string siempre tiene tamaño par.*/
    //cout<<str.UnirMitad("lada","pi");

    /*10.	Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero y
            reemplazarlas por el tercer string recibido.*/
       /* string frase;
        cout<<"Ingrese la frase: ";
        getline(cin,frase);
        cout<<"Ingrese la palabra que quiere cambiar: ";
        string palabra;
        cin>>palabra;
        string palabra2;
        cout<<"Ingrese la palabra que va a reemplazar la otra: ";
        cin>>palabra2;
       cout<<str.Reemplazar(frase,palabra,palabra2);*/

    /*11.Dadas dos palabras, imprimir la que es lexicográficamente mayor.*/
    //str.LexiMayor("holaaa","holaaa");

    /*12.Crear una función que reciba un número N (N va de 1 a 10),y que escriba N números con valores que van
         de 1 a 1000 en un archivo llamado “numeros.txt”.*/
    //str.Escribirfiles(5);

    /*13.	Leer los números en el archivo “numeros.txt” de la pregunta 10 e imprimir la sumatoria.*/
         //str.Sumatoria();
    /*18.7 (Cifrado simple) Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
            cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo
            el cifrado de clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.*/
            /*a) Escriba un programa que cifre un mensaje usando rot13.*/
                //cout<<str.rot13("Algebra")<<endl;

    /*b) Escriba un mensaje que descifre el mensaje codiﬁ cado usando 13 como la clave.*/
            //cout<<str.drot13("UBYN")<<endl;




    /*18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
        nuevo objeto string*/
    //cout<<str.ApellidosNombres("Velasquez Rodriguez","Sol")<<endl;
    /*18.12 Escriba un programa para jugar al ahorcado. El programa debe elegir una palabra (que se codifica directamente en el
        programa, o se lee de un archivo de texto) y mostrar lo siguiente:
        Adivine la palabra: XXXXXX
        Cada X representa una letra. El usuario trata de adivinar las letras en la palabra. Debera mostrarse la respuesta apropiada (si
        o no) despues de cada intento de adivinar. Despues de cada intento incorrecto, muestre el diagrama con otra parte del cuerpo
        incluida. Después de siete intentos incorrectos, el usuario deberá colgarse. La pantalla debe tener la siguiente apariencia:

        Después de cada intento de adivinar, muestre todos los intentos que hizo el usuario. Si el usuario adivina la palabra correcta-
        mente, el programa debe mostrar lo siguiente:

        Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no*/
    str.ahorcado("si");

    /*18.19Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string*/
    //cout<<str.InserCarcte("Sol")<<endl;
    /*18.21Escriba un programa que introduzca una linea de texto, reemplace todos los signos de puntuacion con espacios y utilice
            la funcion strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).*/
    /*cout<<"Ingrese la frase: ";
    string palabra;
    getline(cin,palabra);
    str.Tokens(palabra);
    str.Reverse("Hola Magr creo que yasta");*/

    /*18.27 Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) que ordene objetos string. Use la función
swap en su solución.*/
    /*string frase[]={"con","algebra","programacion"};
    str.Ordenar(frase,1,3);*/
    return 0;

}
