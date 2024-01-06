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
    //void adaugaCamera(Camera camera);

private:
    int id;
    int nr;
    Camera* cameraPointer;
};

#endif // ETAJ_H
