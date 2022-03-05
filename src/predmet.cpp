#include "predmet.h"

predmet::predmet()
{
    //ctor
}

predmet::predmet(string naziv,int espb){
    this->espb=espb;
    this->naziv=naziv;
}

string predmet::getNaziv(){
    return this->naziv;
}

int predmet::getEspb(){
    return this->espb;
}

predmet::~predmet()
{
    //dtor
}
