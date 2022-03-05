#include <iostream>
#include "osoba.h"
#include "ucenik.h"
#include <fstream>
#include <list>
#include <queue>
#include "predmet.h"
#include "profesor.h"

using namespace std;

bool opadajuce(ucenik x, ucenik y)
{
  if(x.getProsek()>y.getProsek()){
    return true;
  }else{
    return false;
  }
}
bool rstuce(ucenik x, ucenik y)
{
  if(x.getProsek()>y.getProsek()){
    return false;
  }else{
    return true;
  }
}

int ucenik::broj_ucenika = 0;

int main()
{
    list <ucenik> lista;

    queue<profesor> prof;

    ifstream f("ucenici.txt");
    if(f.is_open()){
        string ime,prezime;
        int godine;
        while(f>>ime){
            f>>prezime;
            f>>godine;
            ucenik pom = ucenik(ime,prezime,godine);
            int j;
            f>>j;
            for(int i=0;i<j;i++){
                int ocena;
                f>>ocena;
                pom+=ocena;
            }
            pom.izracunaj_prosek();
            lista.push_back(pom);
        }
        f.close();


        while(true){
            cout<<"0. izlaz"<<endl;
            cout<<"1. prikazi ucenike"<<endl;
            cout<<"2. sortiraj opadajuce"<<endl;
            cout<<"3. sortiraj rastuce"<<endl;
            cout<<"4. dodaj ucenika"<<endl;
            cout<<"5. sacuvaj"<<endl;
            cout<<"6. prikazi profesore"<<endl;
            int izbor;
            cin>>izbor;
            system("cls");
            if(izbor==0){
                return 0;
            }else if(izbor==1){
                for(list<ucenik>::iterator it=lista.begin(); it != lista.end(); ++it){
                    ((ucenik) *it).ispis();
                }
            }else if(izbor==2){
                lista.sort(opadajuce);
                for(list<ucenik>::iterator it=lista.begin(); it != lista.end(); ++it){
                    ((ucenik) *it).ispis();
                }
            }else if(izbor==3){
                lista.sort(rstuce);
                for(list<ucenik>::iterator it=lista.begin(); it != lista.end(); ++it){
                    ((ucenik) *it).ispis();
                }
            }else if(izbor==4){
                string ime,prezime;
                int godine;
                cout<<"unesite ime: ";
                cin>>ime;
                cout<<"unesite prezime: ";
                cin>>prezime;
                cout<<"unesite godine:";
                cin>>godine;
                ucenik p = ucenik(ime,prezime,godine);
                int o=-1;
                while(o!=0){
                    cout<<"unosite ocene(0 za prekid)";
                    cin>>o;
                    if(o>0 && o<6){
                        p+=o;
                    }
                }
                p.izracunaj_prosek();
                lista.push_back(p);
            }else if(izbor==5){
                ofstream myfile;
                myfile.open ("ucenici.txt");
                for(list<ucenik>::iterator it=lista.begin(); it != lista.end(); ++it){
                    ((ucenik) *it).ispis();
                    myfile<<((ucenik) *it).getIme()<<" ";
                    myfile<<((ucenik) *it).getPrezime()<<" ";
                    myfile<<((ucenik) *it).getGodine()<<" ";
                    list<int> o = ((ucenik) *it).getLista();
                    myfile<<o.size()<<" ";
                    for(list<int>::iterator it2=o.begin(); it2 != o.end(); ++it2){
                        myfile<<*it2<<" ";
                    }
                    myfile<<"\n";
                }

                myfile.close();
            }else if(izbor==6){
                predmet p1 = predmet("matematika",5);
                profesor pr1 = profesor("pera","peric",34,p1);
                prof.push(pr1);

                predmet p2 = predmet("srpski",4);
                profesor pr2 = profesor("mika","ivanovic",29,p2);
                prof.push(pr2);

                predmet p3 = predmet("matematika",5);
                profesor pr3 = profesor("pera","peric",34,p3);
                prof.push(pr3);

                while (!prof.empty()) {
                    profesor pom = prof.front();
                    pom.ispis();
                    prof.pop();
                }
            }
        }
    }else{
        cout<<"neuspelo otvaranje fajla"<<endl;
        exit(0);
    }

    /*ucenik u1 = ucenik("nemanja","popovic",22);
    u1+=2;
    u1+=4;
    u1+=2;
    u1.izracunaj_prosek();
    u1.ispis();

    ucenik u2 = ucenik("marko","ivanovic",24);
    u2+=1;
    u2+=1;
    u2+=3;
    u2.izracunaj_prosek();
    u2.ispis();

    ucenik u3 = ucenik("petar","panic",23);
    u3+=5;
    u3+=5;
    u3+=4;
    u3.izracunaj_prosek();
    u3.ispis();

    cout<<"sortirani ucenici po proseku"<<endl;
    list <ucenik> lista;
    lista.push_back(u1);
    lista.push_back(u2);
    lista.push_back(u3);
    lista.sort(sortiraj);

    for(list<ucenik>::iterator it=lista.begin(); it != lista.end(); ++it){
        ((ucenik) *it).ispis();
    }

    cout<<"ukupno ucenika: "<<ucenik::broj_ucenika<<endl;*/

    return 0;
}
