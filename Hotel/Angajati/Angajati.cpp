#include "Angajati.h"

Angajati::Angajati()
        : id(0), salariu(0)
{
}

Angajati::Angajati(int idd, int Salariu, std::string Nume)
        : id(idd), salariu(Salariu), nume(std::move(Nume))
{
}

[[maybe_unused]] Angajati::Angajati(const Angajati & src){
    id = src.id;
    salariu = src.salariu;
    nume = src.nume;
}

Angajati::~Angajati()
{
    std::cout << "Angajati destructor" << std::endl;
}


std::ostream &operator<<(std::ostream &os, const Angajati &ang)
{
    os << "Angajatul cu id-ul: " << ang.id << ", are salariul " << ang.salariu << ", se numeste " << ang.nume << "\n";
    return os;
}

Angajati &Angajati::operator=(const Angajati &ang)
{
    if (this != &ang)
    {
        id = ang.id;
        salariu = ang.salariu;
        nume = ang.nume;
    }
    return *this;
}

[[maybe_unused]] void Angajati::adaugaSubaltern(const Angajati& angajat) {
    subalterni.push_back(angajat);
}

[[maybe_unused]] void Angajati::curataCamera(Camera &cam) {
    std::cout<<"Angajatul cu numele"<<nume<<" curata camera cu Id-ul "<<cam.getId()<<std::endl;

}

[[maybe_unused]] [[nodiscard]] double Angajati::calculeazaSalariuAnual() const {
    return salariu * 12;
}

[[maybe_unused]] void Angajati::maresteSalariu(int procent, int salariu) {
    salariu += salariu * (procent/100);
}