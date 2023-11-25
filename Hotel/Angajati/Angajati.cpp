#include "Angajati.h"

#include <utility>

Angajati::Angajati()
{
    id = 0;
    salariu = 0;
    nume = "";
    etj = nullptr;  // Initialize pointer to nullptr
}

Angajati::Angajati(int idd, Etaj *Etj, int Salariu, std::string Nume)
{
    id = idd;
    etj = Etj;
    salariu = Salariu;
    nume = std::move(Nume);
}

Angajati::Angajati(const Angajati &ang)
{
    id = ang.id;
    salariu = ang.salariu;
    nume = ang.nume;
    etj = ang.etj;
}

Angajati::~Angajati()
{
    std::cout<<"Angajati destructor"<<std::endl;
}

int Angajati::getId() const
{
    return id;
}

void Angajati::setId(int x)
{
    id = x;
}

int Angajati::getSalariu() const
{
    return salariu;
}

void Angajati::setSalariu(int x)
{
    salariu = x;
}

std::string Angajati::getNume()
{
    return nume;
}

void Angajati::setNume(std::string x)
{
    nume = std::move(x);
}

Etaj *Angajati::getEtaj()
{
    return etj;
}

void Angajati::setEtaj(const Etaj &Etj)
{
    *etj = Etj;
}

std::ostream &operator<<(std::ostream &os, const Angajati &ang)
{
    os << "Angajatul cu id-ul: " << ang.id << " de pe etajul " << ang.etj->getNr() << ", are salariul " << ang.salariu << ", se numeste " << ang.nume << "\n";
    return os;
}

Angajati& Angajati::operator=(const Angajati &ang)
{
    if (this != &ang)
    {
        id = ang.id;
        salariu = ang.salariu;
        nume = ang.nume;
        etj = ang.etj;
    }
    return *this;
}
