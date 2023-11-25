#ifndef ANGAJATI_H
#define ANGAJATI_H

#include <iostream>
#include "../Etaj/Etaj.h"

class Angajati
{
protected:
    int id;
    Etaj *etj;
    int salariu;
    std::string nume;

public:
    Angajati();
    Angajati(int idd, Etaj *Etj, int Salariu, std::string Nume);
    Angajati(const Angajati &ang);
    ~Angajati();

    [[nodiscard]] int getId() const;
    void setId(int x);
    [[nodiscard]] int getSalariu() const;
    void setSalariu(int x);
    std::string getNume();
    void setNume(std::string x);
    Etaj *getEtaj();
    void setEtaj(const Etaj &Etj);

    friend std::ostream &operator<<(std::ostream &os, const Angajati &ang);
    Angajati & operator=(const Angajati &ang);
};

#endif // ANGAJATI_H
