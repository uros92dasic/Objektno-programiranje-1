#ifndef PROFESOR_H
#define PROFESOR_H

#include "predmet.h"
#include "osoba.h"


class profesor : public osoba
{
    public:
        profesor();
        profesor(string ime,string prezime,int godine,predmet p);
        virtual ~profesor();
        string getNaziv();
        int getEspb();
        void ispis();
    protected:

    private:
        predmet p;
};

#endif // PROFESOR_H
