#ifndef UCENIK_H
#define UCENIK_H

#include <list>

#include "osoba.h"
#include <iostream>

using namespace std;

class ucenik : public osoba
{
    public:
        ucenik();
        ucenik(string ime,string prezime,int godine);
        virtual ~ucenik();

        void operator+=(int ocena);
        //void dodaj_ocenu(int ocena);
        void ispis();
        void izracunaj_prosek();
        double getProsek();
        list<int> getLista();

        static int broj_ucenika;
    protected:

    private:
        double prosek;
        list<int> ocene;

};

#endif // UCENIK_H
