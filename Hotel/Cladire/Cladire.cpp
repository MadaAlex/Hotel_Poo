#include "Cladire.h"

Cladire::Cladire() : id(0)
{
}

Cladire::Cladire(int idd, std::string Add, std::string Num) : id(idd), adresa(std::move(Add)), nume(std::move(Num))
{
}

Cladire::Cladire(const Cladire &cld)= default;

Cladire::~Cladire()
{
    std::cout << "Cladire destructor" << std::endl;
}

int Cladire::getId() const
{
    return id;
}

void Cladire::setId(int x)
{
    id = x;
}

std::string Cladire::getAdresa()
{
    return adresa;
}

void Cladire::setAdresa(std::string Adr)
{
    adresa = std::move(Adr);
}

std::string Cladire::getName()
{
    return nume;
}

void Cladire::setName(std::string Nm)
{
    nume = std::move(Nm);
}

std::ostream &operator<<(std::ostream &os, const Cladire &cld)
{
    os << "(" << cld.id << ", " << cld.nume << ", " << cld.adresa << ")\n";
    return os;
}

Cladire & Cladire::operator=(const Cladire &cld)
{
    if (this != &cld)
    {
        id = cld.id;
        nume = cld.nume;
        adresa = cld.adresa;
    }
    return *this;
}
