#ifndef CLADIRE_H
#define CLADIRE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "../Client/Client.h"
#include "../Etaj/Etaj.h"


class Cladire {
public:
    Cladire();
    Cladire(int id, std::string adresa, std::string name);

    [[maybe_unused]] Cladire(const Cladire &src);
    ~Cladire();

    friend std::ostream &operator<<(std::ostream &os, const Cladire &cladire);

    void addClient(const Client &client);
    [[maybe_unused]] void addFloor(const Etaj &etaj);

private:
    int id;
    bool areLift;
    std::string adresa;
    std::string name;
    std::vector<Etaj> etaje;
    std::vector<Client> clienti;

    [[maybe_unused]] void addFloor(int floorId, const Etaj &etaj);
};

#endif // CLADIRE_H
