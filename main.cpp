#include <iostream>


class Cladire
{
protected:
    int id;
    std::string adresa, nume;
public:
    Cladire()
    {
        id=0;
        adresa="";
        nume="";
    }
    Cladire(int idd, std::string Add, std::string Num)
    {
        id=idd;
        adresa=Add;
        nume=Num;
    }
    Cladire(const Cladire& cld)
    {
        id=cld.id;
        adresa=cld.adresa;
        nume=cld.nume;
    }
    ~Cladire()
    {
        id=0;
        adresa="";
        nume="";
    }
    int getId()
    {
        return id;
    }
    void setId(int x)
    {
        id=x;
    }
    std::string getAdresa()
    {
        return adresa;
    }
    void setAdresa(std::string Adr)
    {
        adresa=Adr;
    }
    std::string getName()
    {
        return nume;
    }
    void setName(std::string Nm)
    {
        nume=Nm;
    }
    friend std::ostream& operator<<(std::ostream &os, const Cladire &cld)
    {
        os<<"("<<cld.id<<", "<<cld.nume<<", "<<cld.adresa<<")\n";
        return os;
    }
    void operator=(const Cladire &cld)
    {
        id=cld.id;
        nume=cld.nume;
        adresa=cld.adresa;
    }
};

class Etaj
{
protected:
    int id;
    Cladire* cld;
    int nr;
    bool lift;
public:
    Etaj()
    {
        id=0;
        nr=0;
        lift = 0;
    }
    Etaj(int idd,Cladire* cldd, int nmr, bool lift_s)
    {
        id=idd;
        cld=cldd;
        nr=nmr;
        lift=lift_s;
    }
    Etaj(const Etaj& etj)
    {
        id=etj.id;
        nr=etj.nr;
        lift=etj.lift;
        cld=etj.cld;
    }
    ~Etaj()
    {
        id=0;
        nr=0;
        lift = 0;
    }
    int getId()
    {
        return id;
    }
    void setId(int x)
    {
        id=x;
    }
    int getNr()
    {
        return nr;
    }
    void setNr(int x)
    {
        nr=x;
    }

    int getLift()
    {
        return lift;
    }
    void setLift(bool x)
    {
        lift=x;
    }
    Cladire* getCladire()
    {
        return cld;
    }
    void setCladire(const Cladire& clad)
    {
        *cld = clad;
    }
    friend std::ostream& operator<<(std::ostream &os, const Etaj &etj)
    {
        if(etj.lift) os<<"Etajul cu nr:"<<etj.nr<<", are lift, face parte din cladirea: "<<*etj.cld<<"\n";
        else os<<"Etajul cu nr:"<<etj.nr<<", nu are lift, face parte din cladirea: "<<*etj.cld<<"\n";
        return os;
    }
    void operator=(const Etaj &etj)
    {
        id=etj.id;
        nr=etj.nr;
        lift=etj.lift;

    }

};

class Camera
{
protected:
    int id;
    Etaj* etj;
    int nr;
    std::string culoare;
    std::string tip;
public:
    Camera()
    {
        id=0;
        nr=0;
        culoare="";
        tip="";
    }
    Camera(int idd,Etaj* Etj, int nmr, std::string clr, std::string tp)
    {
        id=idd;
        etj=Etj;
        nr=nmr;
        culoare=clr;
        tip=tp;

    }
    Camera(const Camera& cmr)
    {
        id=cmr.id;
        nr=cmr.nr;
        culoare=cmr.culoare;
        tip=cmr.tip;
        etj=cmr.etj;
    }
    ~Camera()
    {
        id=0;
        nr=0;
        culoare ="";
        tip="";
    }
    int getId()
    {
        return id;
    }
    void setId(int x)
    {
        id=x;
    }
    int getNr()
    {
        return nr;
    }
    void setNr(int x)
    {
        nr=x;
    }

    std::string getCuloare()
    {
        return culoare;
    }
    void setCuloare(std::string x)
    {
        culoare = x;
    }

    std::string getTip()
    {
        return tip;
    }
    void setTip(std::string x)
    {
        tip= x;
    }
    Etaj* getEtaj()
    {
        return etj;
    }
    void setEtaj(const Etaj& Etj)
    {
        *etj = Etj;
    }
    friend std::ostream& operator<<(std::ostream &os, const Camera &cmr)
    {
        os<<"Camera cu nr: "<<cmr.nr<<" de pe etajul: "<<cmr.etj->getNr()<<", de culoare "<<cmr.culoare<<", tip "<<cmr.tip<<"\n";

        return os;
    }
    void operator=(const Camera &cmr)
    {
        id=cmr.id;
        nr=cmr.nr;
        culoare=cmr.culoare;
        tip=cmr.tip;


    }
};

class Angajati
{
protected:
    int id;
    Etaj* etj;
    int salariu;
    std::string nume;

public:
    Angajati()
    {
        id=0;
        salariu=0;
        nume="";

    }
    Angajati(int idd, Etaj* Etj, int Salariu, std::string Nume)
    {
        id=idd;
        etj=Etj;
        salariu= Salariu;
        nume=Nume;


    }
    Angajati(const Angajati& ang)
    {
        id=ang.id;
        salariu=ang.salariu;
        nume=ang.nume;
        etj=ang.etj;
    }
    ~Angajati()
    {
        id=0;
        nume="";
        salariu =0;

    }
    int getId()
    {
        return id;
    }
    void setId(int x)
    {
        id=x;
    }
    int getSalariu()
    {
        return salariu;
    }
    void setSalariu(int x)
    {
        salariu=x;
    }

    std::string getNume()
    {
        return nume;
    }
    void setNume(std::string x)
    {
        nume = x;
    }


    Etaj* getEtaj()
    {
        return etj;
    }
    void setEtaj(const Etaj& Etj)
    {
        *etj = Etj;
    }
    friend std::ostream& operator<<(std::ostream &os, const Angajati &ang)
    {
        os<<"Angajatul cu id-ul: "<<ang.id<<" de pe etajul "<<ang.etj->getNr()<<", are salariul "<<ang.salariu<<", se numeste "<<ang.nume<<"\n";

        return os;
    }
    void operator=(const Angajati &ang)
    {
        id=ang.id;
        salariu=ang.salariu;
        nume=ang.nume;



    }
};

int main()
{
    std::cout<<"Prima clasa(Cladire):"<<std::endl;
    Cladire A(1,"204, Splaiul Independentei", "Camin Grozavesti");
    std::cout<<A<<std::endl;
    Cladire B;
    B=A;
    std::cout<<"A doua clasa(Etaj):"<<std::endl;
    Etaj C(1,&A, 3, 0);
    std::cout<<C;
    std::cout<<"A treia clasa:(Camera)"<<std::endl;
    Camera D(1,&C, 32, "neagra", "single");
    std::cout<< D<<std::endl;
    std::cout<<"A patra clasa:(Angajati)"<<std::endl;
    Angajati E(1, &C, 4000,"Mircea");
    std::cout<<E;
    return 0;
}
