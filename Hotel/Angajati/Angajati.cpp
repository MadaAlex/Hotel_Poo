#include "Angajati.h"
#include <iostream>
#include <stdexcept>

Angajati::Angajati()
        : id(0), salariu(0)
{
}

Angajati::Angajati(int idd, int Salariu, std::string Nume)
        : id(idd), salariu(Salariu), nume(std::move(Nume))
{
    // Validate input parameters
    if (id < 0 || salariu < 0) {
        throw std::invalid_argument("Invalid argument: ID and salariu must be non-negative.");
    }
}

Angajati::Angajati(const Angajati &src)
        : id(src.id), salariu(src.salariu), nume(src.nume) {
}

Angajati::~Angajati()
{
    std::cout << "Angajati destructor" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Angajati &ang)
{
    os << "Angajatul cu id-ul: " << ang.id << ", are salariul " << ang.salariu << ", se numeste " << ang.nume << "\n";
    return os;
}

Angajati &Angajati::operator=(const Angajati &ang)
{
    if (this != &ang)
    {
        // Validate input parameters
        if (ang.id < 0 || ang.salariu < 0) {
            throw std::invalid_argument("Invalid argument: ID and salariu must be non-negative.");
        }

        id = ang.id;
        salariu = ang.salariu;
        nume = ang.nume;
    }
    return *this;
}

[[maybe_unused]] void Angajati::adaugaSubaltern(const Angajati& angajat) {
    // Check for duplicates
    for (const auto &sub : subalterni) {
        if (sub.id == angajat.id) {
            throw std::invalid_argument("Angajatul cu acest ID este deja un subaltern.");
        }
    }
    subalterni.push_back(angajat);
}


[[maybe_unused]] void Angajati::curataCamera(Camera &cam) {
    // Check if the employee is qualified to clean the camera
    if (salariu < MIN_SALARY_FOR_CLEANING) {
        throw std::logic_error("Angajatul nu are salariu suficient pentru a curata camera.");
    }
    std::cout << "Angajatul cu numele " << nume << " curata camera cu Id-ul " << cam.getId() << std::endl;
}

[[maybe_unused]] double Angajati::calculeazaSalariuAnual() const {
    return salariu * 12;
}

[[maybe_unused]] void Angajati::maresteSalariu(int procent, int &salariu) {
    // Validate input parameters
    if (procent < 0) {
        throw std::invalid_argument("Invalid argument: Procent must be non-negative.");
    }

    salariu += salariu * (procent / 100);
}
