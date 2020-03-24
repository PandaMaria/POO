#include"Lista.h"

Lista::Lista(){                               //initializare
    prim = ultim = NULL;
    length = 0;
}

Lista::Lista(int length){                     //initializare
    prim = ultim = NULL;
    this->length = length;
}

Lista::Lista(const Lista &lista){              //constructor de copiere
    this->length = 0;
    this->prim = NULL;
    this->ultim = NULL;
    Element *aux = lista.prim;                 //element auxiliar cu care se parcurge lista
    for(int i=0; i < lista.length; i++){
        this->pushRight(aux->getInfo());       //se introduc elemente in noua lista
        if(aux->getNext())                     //cand se apeleaza pushRight()se creeaza elemente noi in memorie
            aux = aux->getNext();
    }
}

int Lista::getSuma(){
    int suma=0;
    Element *el= prim;
    for(int i=0;i<length;i++){
        suma+=el->getInfo();
        el=el->getNext();
    }
    return suma;
}

void Lista::pushRight(int value){                       //metoda pentru introducerea elementelor in dreapta listei
    if(prim == NULL){                                   //verific daca lista este goala
        prim = ultim = new Element(value,NULL,NULL);
        length++;
    }else{
        Element* el = new Element(value,NULL,ultim);    //daca lista nu e goala se introduce elementul in dreapta si se
        ultim->setNext(el);                             //seteaza anter-ul lui la elementul anterior iar nextul lui la null
        el->setAnter(ultim);                             //si ii atribui pointerul ultim
        ultim = el;
        length++;
    }
}

void Lista::pushLeft(int value){                        //la fel ca pushRight()
    if(prim == NULL){
        prim = ultim = new Element(value,NULL,NULL);
        length++;
    }else{
        Element* el = new Element(value,prim,NULL);
        prim->setAnter(el);
        el->setNext(prim);
        prim = el;
        length++;
    }
}

void Lista::insertAt(int index,int value){
    if(index==0){
        this->pushLeft(value);
    }else if(index==this->getLength()-1){
        this->pushRight(value);
    }else{
        Element *el = prim;
        Element *toAdd = new Element();
        for(int i=0;i<index;i++){
            el = el->getNext();
        }
        toAdd->setInfo(value);
        el->getAnter()->setNext(toAdd);
        toAdd->setNext(el);
        toAdd->setAnter(el->getAnter());

        length++;
    }
}

void Lista::deleteEl(int value){
    Element *el = prim;
        for(int i=0;i<length;i++){
            if(el->getInfo()==value)
            {
                if(!el->getAnter()){
                    popLeft();
                }else if(!el->getNext()){
                    popRight();
                }else{
                    el->getAnter()->setNext(el->getNext());
                    el->getNext()->setAnter(el->getAnter());
                    delete el;
                    length--;
                }
            }
            el = el->getNext();
        }
}

int Lista::popRight(){                                  //metoda pentru scoaterea elementelor
    if(prim==NULL){
        throw runtime_error("Pop from empty Lista");    //daca lista este goala arunc exceptie
    }else if(prim == ultim){                            //verific daca are un singur element
        Element* toDelete = prim;
        prim = ultim = NULL;
        delete toDelete;                                //apelarea destructorului ~Element
        length--;
    }else{
        Element* toDelete = ultim;                      //daca lista are mai mult de un element
        ultim = ultim->getAnter();                      //setez pointerul ultim la penultimul element
        ultim->setNext(NULL);
        delete toDelete;                                //apelez destructorul pentru ultimul element
        length--;
    }
}

int Lista::popLeft(){                                   //la fel ca pentru popRight()
    if(prim==NULL){
        throw runtime_error("Pop from empty lista");
    }else if(prim == ultim){
        Element* toDelete = prim;
        prim = ultim = NULL;
        delete toDelete;
        length--;
    }else{
        Element* toDelete = prim;
        prim = prim->getNext();
        prim->setAnter(NULL);
        delete toDelete;
        length--;
    }
}

int Lista::getLength(){
    return length;
}

Element* Lista::getPrim(){
    return prim;
}

Element* Lista::getUltim(){
    return ultim;
}

int Lista::getIndex(int value){
    Element *el = prim;
    for(int i=0; i<length ; i++){
        if(el->getInfo()==value){
            return i;
        }
        el=el->getNext();
    }
    return -1;
}

bool Lista::operator>(Lista& lista ){
    if(this->getSuma()>lista.getSuma()){
        return true;
    }
    return false;
}

bool Lista::operator<(Lista& lista ){
    if(this->getSuma()<lista.getSuma()){
        return true;
    }
    return false;
}

Lista& Lista::operator*(int scalar){
    Lista *lista = new Lista();
    for(int i=0;i<length;i++){
        lista->pushRight(((*this)[i].getInfo())*scalar);
    }
    return *lista;
}

Lista Lista::getInverse(){
    Lista *lista = new Lista();
    for(int i=this->getLength()-1;i>=0;i--){
        lista->pushRight((*this)[i].getInfo());
    }
    return *lista;
}

int Lista::getMaxim(){
    int maxim=this->prim->getInfo();
    for(int i=0;i<length;i++){
        if((*this)[i].getInfo()>maxim){
            maxim = (*this)[i].getInfo();
        }
    }
    return maxim;
}

int Lista::getMinim(){
    int minim=this->prim->getInfo();
    for(int i=0;i<length;i++){
        if((*this)[i].getInfo()<minim){
            minim = (*this)[i].getInfo();
        }
    }
    return minim;
}


Lista& Lista::operator+(Lista& el){
    Lista *lista = new Lista(*this);
    for(int i=0;i<el.length;i++){
        lista->pushRight(el[i].getInfo());
    }

}

Element& Lista::operator[](int index){                  //supraincarcarea operatorului []
if(index >= this->getLength()){
        throw out_of_range ("Index out of bounds");     //daca indexul este inafara listei arunc exceptie out of range
    }else{
        Element *aux = this->prim;
        for(int i=0;i<index;i++){                       //altfel se parcurge lista cu un pointer care primeste valoarea
            aux=aux->getNext();                         //din adresa de memorie pe care o pointeaza
        }
        return *aux;
    }
}


ostream& operator<<(ostream& out, const Lista& lista){   //supraincarcarea operatorului <<
     Element *el = lista.prim;                           //parcurg lista cu un pointer
    while(el){
        out<<el->getInfo()<<" ";
        el=el->getNext();
    }
}

istream& operator>>(istream& in, Lista& lista){                 //suprascrierea operatorului >>
    for(int i=0;i<lista.getLength();i++){
        int val;
        in>>val;
        lista.pushRight(val);
        lista.length--;
    }
    return in;
}
