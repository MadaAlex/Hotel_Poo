#ifndef ANGAJATI_H
#define ANGAJATI_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "../Camera/Camera.h"


class Angajati {
public:
    static const int MIN_SALARY_FOR_CLEANING = 1000;  // Example threshold for cleaning

    Angajati();
    Angajati(int idd, int Salariu, std::string Nume);
    Angajati(const Angajati &src);
    ~Angajati();

    friend std::ostream &operator<<(std::ostream &os, const Angajati &ang);
    Angajati &operator=(const Angajati &ang);

    [[maybe_unused]] [[maybe_unused]] void adaugaSubaltern(const Angajati &angajat);

     [[nodiscard]] double calculeazaSalariuAnual() const ;
     static void maresteSalariu(int procent, int &salariu);
    friend class Meniu;


    void curataCamera(const Camera &cam);

    [[maybe_unused]] [[nodiscard]] const std::vector<Angajati>& getSubalterni() const {
        return subalterni;
    }

    [[nodiscard]] int getId() const {
        return id;
    }

private:
    int id;
    int salariu;
    std::string nume;
    std::vector<Angajati> subalterni;

};

#endif // ANGAJATI_H
