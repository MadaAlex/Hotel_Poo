#include "Camera.h"


Camera::Camera(int idd, int nmr, std::string  clr, std::string  tp)
        : id(idd), nr(nmr), culoare(std::move((clr))), tip(std::move(tp)) {}

[[maybe_unused]] Camera::Camera(const Camera &src){

    id = src.id;
    nr = src.nr;
    culoare = src.culoare;
    tip = src.tip;
}

Camera::~Camera()
{
    std::cout << "Camera destructor" << std::endl;
}


std::ostream &operator<<(std::ostream &os, const Camera &cmr)
{
    os << "Camera cu nr: " << cmr.nr << ", de culoare " << cmr.culoare << ", tip " << cmr.tip << "\n";
    return os;
}

Camera &Camera::operator=(const Camera &cmr)
{
    if (this != &cmr)
    {
        id = cmr.id;
        nr = cmr.nr;
        culoare = cmr.culoare;
        tip = cmr.tip;

    }
    return *this;
}

int Camera::getId() const {
    return id;
}


//const Etaj &Camera::getEtaj() const {
//    return <#initializer#>;
//}


//void Etaj::adaugaCamera(const Camera &camera) {
//
//}
//
//void Etaj::eliminaCamera(int cameraId) {
//    // Remove room with the specified ID from the floor
//    // Implement according to your design
//}
