#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <string>


class Camera
{
protected:
    int id;
    int nr;
    std::string culoare;
    std::string tip;

public:
    Camera(int idd, int nmr, std::string  clr, std::string  tp);
    [[maybe_unused]] Camera(const Camera &cmr);
    ~Camera();
    friend std::ostream &operator<<(std::ostream &os, const Camera &cmr);
    Camera &operator=(const Camera &cmr);


//    void adaugaCamera(const Camera &camera);
//    void eliminaCamera(int cameraId);


    [[nodiscard]] int getId() const;
};

#endif // CAMERA_H
