#ifndef MATE_H
#define MATE_H
///#include <NTL/ZZ.h>
///using namespace NTL;

class mate
{
    public:
        mate();
        virtual ~mate();
        int mod(int a,int b);
        int euclides5(int a, int b);
        int extendido(int a,int n);
        int multiplicativa(int a,int n);
        int ValAbs(int b);
    protected:

    private:
};

#endif // MATE_H
