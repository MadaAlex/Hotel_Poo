#include "Etaj.h"

Etaj::Etaj() : id(0), cld(nullptr), nr(0), lift(false) {}

Etaj::Etaj(int idd, Cladire* cldd, int nmr, bool lift_s)
        : id(idd), cld(cldd), nr(nmr), lift(lift_s) {}

Etaj::Etaj(const Etaj &etj)
        : id(etj.id), cld(etj.cld), nr(etj.nr), lift(etj.lift) {}

Etaj::~Etaj()
{
    std::cout << "Etaj destructor" << std::endl;
}

int Etaj::getId() const
{
    return id;
}

void Etaj::setId(int x)
{
    id = x;
}

int Etaj::getNr() const
{
    return nr;
}

void Etaj::setNr(int x)
{
    nr = x;
}

bool Etaj::getLift() const
{
    return lift;
}

void Etaj::setLift(bool x)
{
    lift = x;
}

Cladire* Etaj::getCladire()
{
    return cld;
}

void Etaj::setCladire(Cladire* clad)
{
    cld = clad;
}

std::ostream &operator<<(std::ostream &os, const Etaj &etj)
{
    os << "Etajul cu ID-ul: " << etj.id << " de pe etajul " << etj.nr
       << " are lift: " << etj.lift << ", se afla in cladirea cu ID-ul: "
       << etj.cld->getId() << "\n";
    return os;
}

Etaj &Etaj::operator=(const Etaj &etj)
{
    if (this != &etj)
    {
        id = etj.id;
        cld = etj.cld;
        nr = etj.nr;
        lift = etj.lift;
    }
    return *this;
}
