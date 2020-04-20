#include <iostream>

using namespace std;

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
       cout<<temp;
       while(temp!=a)
        r++;
    }


    cout<<r<<endl<<q<<endl;
    return 0;
}
