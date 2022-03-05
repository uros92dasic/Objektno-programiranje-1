#include "profesor.h"

#include "predmet.h"

#include <iostream>

using namespace std;

profesor::profesor()
{
    //ctor
}

profesor::profesor(string ime,string prezime,int godine,predmet p): osoba(ime,prezime,godine){
    this->p=p;
}

string profesor::getNaziv(){
    return this->p.getNaziv();
}

void profesor::ispis(){
    cout<<"profesor "<<this->ime<<" "<<this->prezime<<" "<<this->godine<<" predaje: "<<this->getNaziv()<<" "<<this->getEspb()<<endl;
}

int profesor::getEspb(){
    return this->p.getEspb();
}

profesor::~profesor()
{
    //dtor
}
