////
//// Created by 40767 on 11/3/2023.
////
//#include <iostream>
//
//#ifndef OOP_CLADIRE_H
//#define OOP_CLADIRE_H
//
//
//class Cladire
//{
//private:
//    int id;
//    std::string adresa, nume;
//public:
//
//    Cladire(int idd, std::string Add, std::string Num) : id(idd), adresa(Add), nume(Num) {}
//
//    Cladire(const Cladire& cld)
//    {
//        id=cld.id;
//        adresa=cld.adresa;
//        nume=cld.nume;
//    }
//    ~Cladire()
//    {
//        id=0;
//        adresa="";
//        nume="";
//    }
//    int getId()
//    {
//        return id;
//    }
//    void setId(int x)
//    {
//        id=x;
//    }
//    std::string getAdresa()
//    {
//        return adresa;
//    }
//    void setAdresa(std::string Adr)
//    {
//        adresa=Adr;
//    }
//    std::string getName()
//    {
//        return nume;
//    }
//    void setName(std::string Nm)
//    {
//        nume=Nm;
//    }
//    friend std::ostream& operator<<(std::ostream &os, const Cladire &cld)
//    {
//        os<<"("<<cld.id<<", "<<cld.nume<<", "<<cld.adresa<<")\n";
//        return os;
//    }
//    void operator=(const Cladire &cld)
//    {
//        id=cld.id;
//        nume=cld.nume;
//        adresa=cld.adresa;
//    }
//};
//
//
//
//#endif //OOP_CLADIRE_H
