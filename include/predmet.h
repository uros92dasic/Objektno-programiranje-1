#ifndef PREDMET_H
#define PREDMET_H

#include <iostream>

using namespace std;

class predmet
{
    public:
        predmet();
        virtual ~predmet();
        predmet(string naziv,int espb);
        string getNaziv();
        int getEspb();

    protected:

    private:
        int espb;
        string naziv;
};

#endif // PREDMET_H
