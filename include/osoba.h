#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>

using namespace std;

class osoba
{
    public:
        osoba();
        osoba(string ime,string prezime,int godine);
        int getGodine();
        string getIme();
        string getPrezime();
        void setGodine(int godine);
        void setIme(string ime);
        void setPrezime(string prezime);
        string podaci();
        virtual ~osoba();

    protected:
        string ime;
        string prezime;
        int godine;
    private:
};

#endif // OSOBA_H
