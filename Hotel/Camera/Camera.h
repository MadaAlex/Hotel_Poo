#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <memory> // Include the necessary header for std::shared_ptr
#include "../Etaj/Etaj.h"

class Camera
{
protected:
    int id;
    Etaj *etj;
    int nr;
    std::string culoare;
    std::string tip;

public:
    Camera();
    Camera(int idd, Etaj *Etj, int nmr, std::string  clr, std::string  tp);
    Camera(const Camera &cmr);
    ~Camera();

    int getId() const;
    void setId(int x);
    int getNr() const;
    void setNr(int x);
    std::string getCuloare();
    void setCuloare(std::string x);
    std::string getTip();
    void setTip(std::string x);
    Etaj *getEtaj();
    void setEtaj(const Etaj *Etj);

    friend std::ostream &operator<<(std::ostream &os, const Camera &cmr);
    Camera &operator=(const Camera &cmr);

    Camera(int idd, const std::shared_ptr<Etaj> &Etj, int nmr, std::string  clr, std::string  tp);
};

#endif // CAMERA_H
