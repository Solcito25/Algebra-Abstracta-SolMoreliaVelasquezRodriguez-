#ifndef ALGTRADICIONALES_H
#define ALGTRADICIONALES_H
#include<string>
using namespace std;

class algTradicionales
{
    public:
        algTradicionales();
        virtual ~algTradicionales();
        string cifradoPoly(string mensaje);
        string descifradoPoly(string mensajeCifrado);
        int mod(int,int);
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    protected:

    private:

};

#endif // ALGTRADICIONALES_H
