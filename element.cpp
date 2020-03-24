#include"Element.h"

Element::Element(){                       //initializarea elementului
    info = 0;
    next = NULL;
    anter = NULL;
}

Element::Element(int info, Element* next, Element* anter){
    this->info = info;
    this->next = next;
    this->anter = anter;
}

Element::Element(const Element& el){        // salvez informatia in constructorul de copiere si
    this->info = info;                      // elementul va avea atributele next si anter initializate
    next = NULL;
    anter = NULL;
}

void Element::setInfo(int info){
    this->info = info;
}

void Element::setNext(Element* next){
    this->next = next;
}

void Element::setAnter(Element* anter){
    this->anter = anter;
}

int Element::getInfo(){
    return info;
}

Element* Element::getNext(){
    return next;
}

Element* Element::getAnter(){
    return anter;
}


