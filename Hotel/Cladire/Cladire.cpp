#include "Cladire.h"

Cladire::Cladire() : id(0){}

Cladire::Cladire(int id, std::string  adresa, std::string  name)
        : id(id), adresa(std::move(adresa)), name(std::move(name)) {}

int Cladire::getId() const
{
    return id;
}

[[maybe_unused]] void Cladire::setId(int x)
{
    id = x;
}

std::string Cladire::getAdresa() const
{
    return adresa;
}

void Cladire::setAdresa(const std::string& x)
{
    adresa = x;
}

std::string Cladire::getName() const
{
    return name;
}

void Cladire::setName(const std::string& x)
{
    name = x;
}

std::ostream& operator<<(std::ostream& os, const Cladire& cladire)
{
    os << "Cladire ID: " << cladire.id << ", Adresa: " << cladire.adresa << ", Nume: " << cladire.name << "\n";
    return os;
}
