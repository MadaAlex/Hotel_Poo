// Cladire.h
#ifndef CLADIRE_H
#define CLADIRE_H

#include <iostream>
#include <string>

class Cladire
{
private:
    int id;
    std::string adresa;
    std::string name;

public:
    Cladire();
    Cladire(int id, std::string  adresa, std::string  name);

    [[nodiscard]] int getId() const;

    [[maybe_unused]] void setId(int x);

    [[nodiscard]] std::string getAdresa() const;
    void setAdresa(const std::string& x);

    [[nodiscard]] std::string getName() const;
    void setName(const std::string& x);

    friend std::ostream& operator<<(std::ostream& os, const Cladire& cladire);
};

#endif // CLADIRE_H
