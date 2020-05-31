#ifndef RAILFENCE_H
#define RAILFENCE_H
#include<string>
using namespace std;
class railfence
{
    public:
        railfence();
        virtual ~railfence();
        string cifrado(string mensaje);
        int mod(int,int);
        string descifrado(string mensaje);

    protected:

    private:
        int clave;
};

#endif // RAILFENCE_H
