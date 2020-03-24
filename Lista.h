#include"Element.h"
using namespace std;

class Lista{
    Element *prim, *ultim;
    unsigned length;
    int popRight();
    int popLeft();
    void pushRight(int);
    void pushLeft(int);
    Element* getPrim();
    Element* getUltim();

public:

    Lista();
    Lista(int);
    Lista(const Lista&);
    void insertAt(int,int);
    void deleteEl(int);
    int getLength();
    int getIndex(int);
    int getSuma();
    int getMaxim();
    int getMinim();

    Lista getInverse();

    bool operator>(Lista&);
    bool operator<(Lista&);

    Lista& operator*(int);
    Element& operator[](int);
    Lista& operator+(Lista&);
    friend ostream& operator<<(ostream& out,const Lista& lista);
    friend istream& operator>>(istream&,Lista&);
};
