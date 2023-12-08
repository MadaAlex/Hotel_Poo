// Cladire.cpp
#include "Cladire.h"
#include <iostream>

Cladire::Cladire() : id(0), areLift(false) {}

Cladire::Cladire(int id, std::string adresa, std::string name)
        : id(id), areLift(false), adresa(std::move(adresa)), name(std::move(name)) {}

Cladire::Cladire(const Cladire &src)
        : id(src.id), areLift(src.areLift), adresa(src.adresa), name(src.name), etaje(src.etaje){
}

Cladire::~Cladire()
{
    std::cout << "Cladire destructor" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Cladire &cladire)
{
    os << "Cladire ID: " << cladire.id << ", Adresa: " << cladire.adresa << ", Nume: " << cladire.name
       << " are lift: " << cladire.areLift << "\n";

    for (const Etaj &etaj : cladire.etaje)
    {
        os << etaj;
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

void Cladire::addRoomToFloor(int floorId,const Camera &camera)
{
    for (Etaj &etaj : etaje)
    {
        if (etaj.getId() == floorId)
        {
            etaj.addRoom(camera);
            break;
        }
    }
}

