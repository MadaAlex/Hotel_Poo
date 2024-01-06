#include "Cladire.h"

Cladire::Cladire() : id(0), areLift(false) {}

Cladire::Cladire(int id, std::string adresa, std::string name)
        : id(id), areLift(false), adresa(std::move(adresa)), name(std::move(name)) {}

[[maybe_unused]] Cladire::Cladire(const Cladire &src)
        : id(src.id), areLift(src.areLift), adresa(src.adresa), name(src.name), etaje(src.etaje), clienti(src.clienti) {}

Cladire::~Cladire()
{
    std::cout << "Cladire destructor" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Cladire &cladire)
{
    os << "Cladire ID: " << cladire.id << ", Adresa: " << cladire.adresa << ", Nume: " << cladire.name
       << " has lift: " << cladire.areLift << "\n";

    for (const Etaj &etaj : cladire.etaje)
    {
        os << etaj;
    }

    os << "Clients:";
    for (const Client &client : cladire.clienti)
    {
        os << "\n" << client;
    }

    return os;
}

void Cladire::addClient(const Client &client)
{
    clienti.push_back(client);
}

[[maybe_unused]] void Cladire::addFloor(const Etaj &etaj)
{
    etaje.push_back(etaj);
}

[[maybe_unused]] void Cladire::addFloor(int floorId, const Etaj &etaj)
{

    if (static_cast<std::vector<Etaj>::size_type>(floorId) >= etaje.size())
    {
        throw std::out_of_range("Invalid floor ID.");
    }


    if (static_cast<std::vector<Etaj>::size_type>(floorId) >= etaje.size())

    {
        etaje[floorId] = etaj;
    }
    else
    {
        etaje.push_back(etaj);
    }
}

