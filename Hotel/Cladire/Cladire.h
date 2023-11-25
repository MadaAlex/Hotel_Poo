#ifndef CLADIRE_H
#define CLADIRE_H

#include <iostream>

class Cladire
{
protected:
    int id;
    std::string adresa, nume;

public:
    Cladire();
    Cladire(int idd, std::string Add, std::string Num);
    Cladire(const Cladire &cld);
    ~Cladire();

    [[nodiscard]] int getId() const;
    void setId(int x);
    std::string getAdresa();
    void setAdresa(std::string Adr);
    std::string getName();
    void setName(std::string Nm);

    friend std::ostream &operator<<(std::ostream &os, const Cladire &cld);
    Cladire & operator=(const Cladire &cld);
};

#endif // CLADIRE_H