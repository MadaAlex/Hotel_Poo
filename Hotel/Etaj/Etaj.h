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

    [[maybe_unused]] [[nodiscard]] int getId() const;
    void setId(int newId);  // New setter method for ID
    void setAddress(const std::string& newAddress);  // New setter method for address
    void setName(const std::string& newName);  // New setter method for name
    void adaugaCamera(Camera *camera);

private:
    int id;
    int nr;
    Camera* cameraPointer;
    std::string address;  // New member variable for address
    std::string name;  // New member variable for name
};

#endif // ETAJ_H
