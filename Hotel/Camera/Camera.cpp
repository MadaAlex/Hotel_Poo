#include "Camera.h"


Camera::Camera(int idd, int nmr, std::string clr, std::string tp)
        : id(idd), nr(nmr), culoare(std::move(clr)), tip(std::move(tp)) {}

Camera::Camera(const Camera &src)
        : id(src.id), nr(src.nr), culoare(src.culoare), tip(src.tip) {}

Camera::~Camera()
{
    std::cout << "Camera destructor" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Camera &cmr)
{
    os << "Camera with number: " << cmr.nr << ", color " << cmr.culoare << ", type " << cmr.tip << "\n";
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

int Camera::getId() const
{
    return id;
}

 int Camera::getRoomNumber() const
{
    return nr;
}

