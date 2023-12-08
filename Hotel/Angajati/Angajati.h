#ifndef ANGAJATI_H
#define ANGAJATI_H

#include <iostream>
#include "../Etaj/Etaj.h"
#include "../Camera/Camera.h"

class Angajati
{
protected:
    int id;
    int salariu;
    std::string nume;
    std::vector<Angajati> subalterni;
public:

    Angajati();
    ~Angajati();
    Angajati(int idd, int Salariu, std::string Nume);
    Angajati& operator=(const Angajati& player);

    [[maybe_unused]] Angajati(const Angajati &ang);

    friend std::ostream &operator<<(std::ostream &os, const Angajati &ang);


    [[maybe_unused]] void adaugaSubaltern(const Angajati&);

    [[maybe_unused]] void curataCamera(Camera& cam);

    [[maybe_unused]] [[nodiscard]] double calculeazaSalariuAnual() const;

    [[maybe_unused]] static void maresteSalariu(int procent, int salariu);

};

#endif // ANGAJATI_H
