// Etaj.h
#ifndef ETAJ_H
#define ETAJ_H

#include <vector>
#include "../Camera/Camera.h"
#include <string>

class Etaj
{
protected:
    int id;
    int nr;
    std::vector<Camera> camere{Camera(1, 48, "verde", "dubla"), Camera(2, 49, "verde", "single")};

public:
    Etaj();
    ~Etaj();
    Etaj(const Etaj &etj);
    Etaj& operator=(const Etaj& other);
    friend std::ostream& operator<<(std::ostream& os, const Etaj& etaj);


    [[maybe_unused]] void adaugaCamera(const Camera& camera);



    [[nodiscard]] int getId() const;

    void addRoom([[maybe_unused]] const Camera &camera);
};

#endif // ETAJ_H
