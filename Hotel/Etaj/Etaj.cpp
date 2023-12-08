// Etaj.cpp
#include <algorithm>
#include "Etaj.h"

Etaj::Etaj() : id(0), nr(0) {}

Etaj::Etaj(const Etaj &etj){
    id = etj.id;
    nr = etj.nr;
    camere = etj.camere;
}

Etaj::~Etaj()
{
    std::cout << "Etaj destrutor" <<"\n";
}


[[maybe_unused]] void Etaj::adaugaCamera(const Camera& camera)
{
    camere.push_back(camera);
}

Etaj& Etaj::operator=(const Etaj& other)
{
    if (this != &other)
    {
        id = other.id;
        nr = other.nr;
        camere = other.camere;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Etaj& etaj) {
    os << "Etaj ID: " << etaj.id << ", Numar: " << etaj.nr << "\nCamere:";
    for (const auto &camera: etaj.camere) {
        os << "\n" << camera;
    }
    return os;
}


int Etaj::getId() const {
    return id;
}


void Etaj::addRoom([[maybe_unused]] const Camera &camera) {

}
