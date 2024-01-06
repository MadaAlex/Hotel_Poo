#include "Etaj.h"

#include <stdexcept>

Etaj::Etaj() : id(0), nr(0), cameraPointer(nullptr) {}

Etaj::Etaj(const Etaj &etj)
        : id(etj.id), nr(etj.nr)
{
    // Deep copy for the Camera pointer
    if (etj.cameraPointer) {
        cameraPointer = new Camera(*etj.cameraPointer);
    } else {
        cameraPointer = nullptr;
    }
}

Etaj::~Etaj()
{
    delete cameraPointer;  // Release memory
    std::cout << "Etaj destructor" << "\n";
}

void Etaj::adaugaCamera(Camera* camera)
{
    if (camera->getRoomNumber() < 0) {
        throw std::invalid_argument("Invalid argument: Room number must be non-negative.");
    }

    // Release existing memory
    delete cameraPointer;

    // Deep copy for the Camera pointer
    if (camera) {
        cameraPointer = new Camera(*camera);
    } else {
        cameraPointer = nullptr;
    }
}

Etaj& Etaj::operator=(const Etaj& other)
{
    if (this != &other)
    {
        id = other.id;
        nr = other.nr;

        // Release existing memory
        delete cameraPointer;

        // Deep copy for the Camera pointer
        if (other.cameraPointer) {
            cameraPointer = new Camera(*other.cameraPointer);
        } else {
            cameraPointer = nullptr;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Etaj& etaj) {
    os << "Etaj ID: " << etaj.id << ", Numar: " << etaj.nr << "\n";
    if (etaj.cameraPointer) {
        os << "Camera:\n" << *(etaj.cameraPointer);
    } else {
        os << "No Camera\n";
    }
    return os;
}

[[maybe_unused]] int Etaj::getId() const {
    return id;
}
