// Cladire.h
#ifndef CLADIRE_H
#define CLADIRE_H

#include <iostream>
#include <string>
#include <vector>
#include "../Etaj/Etaj.h"
#include "../Client/Client.h"


class Cladire {
private:
    int id;
    bool areLift;
    std::string adresa;
    std::string name;
    std::vector<Etaj> etaje;
    std::vector<Client> clienti;

public:
    Cladire();
    ~Cladire();
    Cladire(int id, std::string adresa, std::string name);
    Cladire(const Cladire &src);
    friend std::ostream &operator<<(std::ostream &os, const Cladire &cladire);

    void addClient(const Client &client);
    [[maybe_unused]] void addFloor(const Etaj &etaj);
    void addRoomToFloor(int floorId,const Camera &camera);
};

#endif // CLADIRE_H