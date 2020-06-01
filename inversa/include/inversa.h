#ifndef INVERSA_H
#define INVERSA_H
#include <NTL/ZZ.h>
using namespace NTL;
class inversa
{
    public:
        inversa();
        virtual ~inversa();
        ZZ mod(ZZ a,ZZ b);
        ZZ euclides5(ZZ a, ZZ b);
        ZZ extendido(ZZ a,ZZ n);
        ZZ multiplicativa(ZZ a,ZZ n);
        ZZ ValAbs(ZZ b);
    protected:

    private:
};

#endif // INVERSA_H
