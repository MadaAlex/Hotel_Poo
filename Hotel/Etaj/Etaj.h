// Etaj.h

#ifndef ETAJ_H
#define ETAJ_H

#include <iostream>
#include <vector>
#include "../Camera/Camera.h"

class Etaj {
public:
    Etaj();
    Etaj(const Etaj& etj);
    ~Etaj();
    Etaj& operator=(const Etaj& other);
    friend std::ostream& operator<<(std::ostream& os, const Etaj& etaj);

    void setId(long int newId);
    void setAddress(const std::string& newAddress);
    void setName(const std::string& newName);
    void adaugaCamera(Camera *camera);

private:
    long int id;
    int nr;
    Camera* cameraPointer;
    std::string address;
    std::string name;
};

#endif // ETAJ_H
