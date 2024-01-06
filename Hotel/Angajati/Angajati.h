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

    [[maybe_unused]] void adaugaSubaltern(const Angajati &angajat);

    [[maybe_unused]] [[nodiscard]]  double calculeazaSalariuAnual() const;
    [[maybe_unused]] static void maresteSalariu(int procent, int &salariu);

    // Add getters for id and salariu if needed

private:
    int id;
    int salariu;
    std::string nume;
    std::vector<Angajati> subalterni;

    [[maybe_unused]] void curataCamera(const Camera &cam);
};

#endif // ANGAJATI_H
