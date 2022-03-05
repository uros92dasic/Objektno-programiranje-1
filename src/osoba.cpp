#include "osoba.h"
#include <sstream>
#include <string>


osoba::osoba()
{
    //ctor
}

osoba::osoba(string ime,string prezime,int godine){
    this->ime=ime;
    this->prezime=prezime;
    this->godine=godine;
}

int osoba::getGodine(){
    return this->godine;
}

string osoba::getIme(){
    return this->ime;
}

string osoba::getPrezime(){
    return this->prezime;
}

void osoba::setGodine(int godine){
    this->godine=godine;
}

void osoba::setIme(string ime){
    this->ime=ime;
}

void osoba::setPrezime(string prezime){
    this->prezime=prezime;
}

string osoba::podaci(){
    std::ostringstream stm;
    stm<<this->godine;
    string g = stm.str();
    return this->ime+" "+this->prezime+" "+g;
}

osoba::~osoba()
{
    //dtor
}
