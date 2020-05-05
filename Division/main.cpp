#include <iostream>

using namespace std;
int mod(int a,int b){

    int r=a-(b*(a/b));
    if(r<0)
        r=b-r;
    return r;
    }
int main()
{
    int a,q,r,n;
    cout << "Ingresar a: " << endl;
    cin>>a;
    cout << "Ingresar n: " << endl;
    cin>>n;
    r=a%n;
    q=a/n;

    if(r<0){
       r=r*(-1);
       q=q-1;
       int temp =(q*n)+r;
       while(temp!=a){
        r++;
        temp=(q*n)+r;
       }
    }


    cout<<"residuo: "<<r<<endl;
    cout<<"cociente: "<<q<<endl;
    return 0;
}
