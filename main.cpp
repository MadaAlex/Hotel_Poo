#include <iostream>
#include "Hotel/Cladire/Cladire.h"
#include "Hotel/Etaj/Etaj.h"
#include "Hotel/Camera/Camera.h"
#include "Hotel/Angajati/Angajati.h"

int main()
{
    Cladire cladire(1, "Main Street", "Office Building");
    std::cout << cladire.getId() << std::endl;
    cladire.setAdresa("New Address");
    std::cout << cladire.getAdresa() << std::endl;
    cladire.setName("New Name");
    std::cout << cladire.getName() << std::endl;

    Etaj etaj(1, &cladire, 2, true);
    std::cout << etaj.getId() << std::endl;
    etaj.setId(2);
    std::cout << etaj.getNr() << std::endl;
    etaj.setNr(3);
    std::cout << etaj.getLift() << std::endl;
    etaj.setLift(false);

    Camera camera(1, &etaj, 32, "neagra", "single");

    Etaj* cameraEtaj = camera.getEtaj();
    std::cout << cameraEtaj->getId() << std::endl;

    std::cout << camera << std::endl;

    Angajati angajat(1, &etaj, 4000, "Mircea");
    std::cout << angajat << std::endl;

    Etaj etaj1(1, nullptr, 1, true);
    Etaj etaj2(2, nullptr, 2, false);
    Camera camera1(1, &etaj1, 101, "red", "wide");
    Camera camera2(2, &etaj2, 102, "blue", "telephoto");
    Angajati angajat1(1, &etaj, 3000, "John Doe");
    Angajati angajat2(2, &etaj, 4000, "Jane Doe");

    std::cout << camera1.getId() << std::endl;
    std::cout << camera1.getNr() << std::endl;
    std::cout << camera1.getCuloare() << std::endl;
    std::cout << camera1.getTip() << std::endl;
    camera1.setId(201);
    camera1.setNr(202);
    camera1.setCuloare("green");
    camera1.setTip("macro");
    std::cout << camera1.getId() << std::endl;
    std::cout << camera1.getNr() << std::endl;
    std::cout << camera1.getCuloare() << std::endl;
    std::cout << camera1.getTip() << std::endl;
    camera1.setEtaj(&etaj2);
    std::cout << camera1 << std::endl;

    std::cout << angajat1.getId() << std::endl;
    std::cout << angajat1.getSalariu() << std::endl;
    std::cout << angajat1.getNume() << std::endl;
    angajat1.setId(101);
    angajat1.setSalariu(3500);
    angajat1.setNume("John Smith");
    std::cout << angajat1.getId() << std::endl;
    std::cout << angajat1.getSalariu() << std::endl;
    std::cout << angajat1.getNume() << std::endl;
    std::cout << angajat1 << std::endl;

    return 0;
}
