// Etaj.cpp

#include "Etaj.h"

#include <stdexcept>

Etaj::Etaj() : id(0), nr(0), cameraPointer(nullptr) {}

Etaj::Etaj(const Etaj &etj)
        : id(etj.id), nr(etj.nr), address(etj.address), name(etj.name)
{

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

// If you decide to implement adaugaCamera using pointers, handle memory allocation appropriately.
void Etaj::adaugaCamera(Camera* camera)
{
    if (camera->getRoomNumber() < 0) {
        throw std::invalid_argument("Invalid argument: Room number must be non-negative.");
    }

    cameraPointer = camera;
}

Etaj& Etaj::operator=(const Etaj& other)
{
    if (this != &other)
    {
        id = other.id;
        nr = other.nr;
        address = other.address;
        name = other.name;

        // Deep copy for the Camera pointer
        delete cameraPointer;  // Release existing memory
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
    os << "Address: " << etaj.address << "\n";
    os << "Name: " << etaj.name << "\n";
    if (etaj.cameraPointer) {
        os << "Camera:\n" << *(etaj.cameraPointer);
    } else {
        os << "No Camera\n";
    }
    return os;
}

void Etaj::setId(long int newId) {

    id = newId;
}

void Etaj::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Etaj::setName(const std::string& newName) {
    name = newName;
}
