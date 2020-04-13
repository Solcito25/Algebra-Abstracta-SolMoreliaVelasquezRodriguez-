#ifndef CESAR_H
#define CESAR_H
#include <string>
using namespace std;
class cesar
{
    public:
        cesar();
        string cifrado(string mensaje);
        string descifrado(string mensajeCifrado);
        string alfabeto;
        virtual ~cesar();

    protected:

    private:
        int clave;
};

#endif // CESAR_H
