#ifndef EUCLIDES_H
#define EUCLIDES_H
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class euclides
{
    public:
        euclides();
        virtual ~euclides();
        ZZ mod(ZZ a,ZZ b);
        ZZ ValAbs(ZZ b);
        ZZ euclides1(ZZ a,ZZ b);
        ZZ euclides2(ZZ a,ZZ b);
        ZZ euclides3 (ZZ a, ZZ b);
        ZZ euclides4(ZZ a, ZZ b);
        ZZ euclides5(ZZ a, ZZ b);
        ZZ euclides6(ZZ a, ZZ b);
        ZZ euclides7(ZZ a,ZZ b);
        ZZ euclides8(ZZ a,ZZ b);

    protected:

    private:
};

#endif // EUCLIDES_H
