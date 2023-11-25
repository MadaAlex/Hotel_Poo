#include "Etaj.h"

#include <utility>

Etaj::Etaj() : id(0), cld(nullptr), nr(0), lift(false) {}

Etaj::Etaj(int idd, std::shared_ptr<Cladire> cldd, int nmr, bool lift_s)
        : id(idd), cld(std::move(cldd)), nr(nmr), lift(lift_s) {}

Etaj::Etaj(const Etaj &etj)= default;

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

std::shared_ptr<Cladire> Etaj::getCladire()
{
    return cld;
}

void Etaj::setCladire(const Cladire &clad)
{
    cld = std::make_shared<Cladire>(clad);
}

std::ostream &operator<<(std::ostream &os, const Etaj &etj)
{
    if (etj.lift)
        os << "Etajul cu nr:" << etj.nr << ", are lift, face parte din cladirea: " << *(etj.cld) << "\n";
    else
        os << "Etajul cu nr:" << etj.nr << ", nu are lift, face parte din cladirea: " << *(etj.cld) << "\n";
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
