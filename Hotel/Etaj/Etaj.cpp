#include "Etaj.h"

Etaj::Etaj()
{
    id = 0;
    nr = 0;
    lift = false;
    cld = nullptr;
}

Etaj::Etaj(int idd, Cladire *cldd, int nmr, bool lift_s)
{
    id = idd;
    cld = cldd;
    nr = nmr;
    lift = lift_s;
}

Etaj::Etaj(const Etaj &etj)
{
    id = etj.id;
    nr = etj.nr;
    lift = etj.lift;
    cld = etj.cld;
}

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

int Etaj::getLift() const
{
    return lift;
}

void Etaj::setLift(bool x)
{
    lift = x;
}

Cladire *Etaj::getCladire()
{
    return cld;
}

void Etaj::setCladire(const Cladire &clad)
{

        delete cld;

    cld = new Cladire(clad);
}

std::ostream &operator<<(std::ostream &os, const Etaj &etj)
{
    if (etj.lift)
        os << "Etajul cu nr:" << etj.nr << ", are lift, face parte din cladirea: " << *etj.cld << "\n";
    else
        os << "Etajul cu nr:" << etj.nr << ", nu are lift, face parte din cladirea: " << *etj.cld << "\n";
    return os;
}

Etaj & Etaj::operator=(const Etaj &etj)
{
    if (this != &etj)
    {
        id = etj.id;
        nr = etj.nr;
        lift = etj.lift;
        delete cld;
        cld = new Cladire(*(etj.cld));
    }
    return *this;
}
