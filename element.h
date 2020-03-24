#include<iostream>

class Element{
    int info;
    Element* next;                      //pointer catre elementul urmatorul din lista
    Element* anter;                     //pointer catre elementul anterior din lista
public:
    Element();                          //constructor fara parametrii
    Element(int,Element*,Element*);     //constructor cu parametrii
    Element(const Element&);            //constructor de copiere
    void setInfo(int);
    void setNext(Element*);
    void setAnter(Element*);
    int getInfo();
    Element* getNext();
    Element* getAnter();

};
