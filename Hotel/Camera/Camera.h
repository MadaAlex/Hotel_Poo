#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <string>
#include <stdexcept>


class Camera {
public:
    Camera(int idd, int nmr, std::string clr, std::string tp);
    Camera(const Camera &src);
    ~Camera();

    friend std::ostream &operator<<(std::ostream &os, const Camera &cmr);
    Camera &operator=(const Camera &cmr);

    [[nodiscard]] int getId() const;

    [[maybe_unused]] [[nodiscard]] int getRoomNumber() const;

    [[maybe_unused]]   static void getEtaj() ;

private:
    int id;
    int nr;
    std::string culoare;
    std::string tip;
};

#endif // CAMERA_H
