#include "Camera.h"

#include <utility>

Camera::Camera() : id(0), etj(nullptr), nr(0){}

Camera::Camera(int idd, Etaj *Etj, int nmr, std::string  clr, std::string  tp)
        : id(idd), etj(Etj), nr(nmr), culoare(std::move(clr)), tip(std::move(tp)) {}

Camera::Camera(const Camera &cmr) = default;

Camera::~Camera()
{
    id = 0;
    nr = 0;
    culoare = "";
    tip = "";
}

int Camera::getId() const
{
    return id;
}

void Camera::setId(int x)
{
    id = x;
}

int Camera::getNr() const
{
    return nr;
}

void Camera::setNr(int x)
{
    nr = x;
}

std::string Camera::getCuloare()
{
    return culoare;
}

void Camera::setCuloare(std::string x)
{
    culoare = std::move(x);
}

std::string Camera::getTip()
{
    return tip;
}

void Camera::setTip(std::string x)
{
    tip = std::move(x);
}

Etaj *Camera::getEtaj()
{
    return etj;
}

void Camera::setEtaj(const Etaj *Etj)
{
    etj = const_cast<Etaj *>(Etj);
}

std::ostream &operator<<(std::ostream &os, const Camera &cmr)
{
    os << "Camera cu nr: " << cmr.nr << " de pe etajul: " << cmr.etj->getNr() << ", de culoare " << cmr.culoare << ", tip " << cmr.tip << "\n";
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
        etj = cmr.etj;
    }
    return *this;
}
