#include "ucenik.h"
#include "osoba.h"

#include <list>

ucenik::ucenik()
{
    //ctor
}

ucenik::ucenik(string ime,string prezime,int godine) : osoba(ime,prezime,godine){
    this->broj_ucenika++;
}

/*void ucenik::dodaj_ocenu(int ocena){
    this->ocene.push_back(ocena);
}*/

void ucenik::operator+=(int ocena){
    this->ocene.push_back(ocena);
}

list<int> ucenik::getLista(){
    return this->ocene;
}

double ucenik::getProsek(){
    return this->prosek;
}

void ucenik::izracunaj_prosek(){
    double p=0;
    double j=0;
    for (list<int>::iterator it=this->ocene.begin(); it != this->ocene.end(); ++it){
        j++;
        p+=*it;
    }
    this->prosek = p/j;
}

void ucenik::ispis(){
    string o = osoba::podaci();
    cout<<o<<" ocene: ";
    for (list<int>::iterator it=this->ocene.begin(); it != this->ocene.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<" prosek ";
    cout<<this->prosek;
    cout<<endl;
}

ucenik::~ucenik()
{
    //dtor
}
