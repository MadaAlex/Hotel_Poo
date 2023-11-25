#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "../Etaj/Etaj.h"

class Camera
{
protected:
    int id;
    Etaj *etj{};
    int nr;
    std::string culoare;
    std::string tip;

public:
    Camera();
    Camera(int idd, Etaj *Etj, int nmr, std::string clr, std::string tp);
    Camera(const Camera &cmr);
    ~Camera();

    [[nodiscard]] int getId() const;
    void setId(int x);
    [[nodiscard]] int getNr() const;
    void setNr(int x);

    [[maybe_unused]] std::string getCuloare();
    void setCuloare(std::string x);
    std::string getTip();
    void setTip(std::string x);
    Etaj *getEtaj();
    void setEtaj(const Etaj &Etj);

    friend std::ostream &operator<<(std::ostream &os, const Camera &cmr);
    Camera & operator=(const Camera &cmr);
};

#endif // CAMERA_H
