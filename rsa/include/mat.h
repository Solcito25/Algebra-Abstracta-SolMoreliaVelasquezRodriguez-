#ifndef MAT_H
#define MAT_H
#include <NTL/ZZ.h>
using namespace NTL;

class mat
{
    public:
        mat();
        virtual ~mat();
        ZZ mod(ZZ a,ZZ b);
        ZZ euclides5(ZZ a, ZZ b);
        ZZ extendido(ZZ a,ZZ n);
        ZZ multiplicativa(ZZ a,ZZ n);
        ZZ ValAbs(ZZ b);
        ZZ exponencial(ZZ b,ZZ e,ZZ n);

    protected:

    private:
};

#endif // MAT_H
