////
//// Created by 40767 on 11/3/2023.
////
//
//#ifndef OOP_ETAJ_H
//#define OOP_ETAJ_H
//#include<iostream>
//#include "CLADIRE.h"
//
//class Etaj
//{
//protected:
//    int id;
//    Cladire* cld;
//    int nr;
//    bool lift;
//public:
//    Etaj()
//    {
//        id=0;
//        nr=0;
//        lift = 0;
//    }
//    Etaj(int idd,Cladire* cldd, int nmr, bool lift_s)
//    {
//        id=idd;
//        cld=cldd;
//        nr=nmr;
//        lift=lift_s;
//    }
//    Etaj(const Etaj& etj)
//    {
//        id=etj.id;
//        nr=etj.nr;
//        lift=etj.lift;
//        cld=etj.cld;
//    }
//    ~Etaj()
//    {
//        id=0;
//        nr=0;
//        lift = 0;
//    }
//    int getId()
//    {
//        return id;
//    }
//    void setId(int x)
//    {
//        id=x;
//    }
//    int getNr()
//    {
//        return nr;
//    }
//    void setNr(int x)
//    {
//        nr=x;
//    }
//
//    int getLift()
//    {
//        return lift;
//    }
//    void setLift(bool x)
//    {
//        lift=x;
//    }
//    Cladire* getCladire()
//    {
//        return cld;
//    }
//    void setCladire(const Cladire& clad)
//    {
//        *cld = clad;
//    }
//    friend ostream& operator<<(ostream &os, const Etaj &etj)
//    {
//        if(etj.lift) os<<"Etajul cu nr:"<<etj.nr<<", are lift, face parte din cladirea: "<<*etj.cld<<"\n";
//        else os<<"Etajul cu nr:"<<etj.nr<<", nu are lift, face parte din cladirea: "<<*etj.cld<<"\n";
//        return os;
//    }
//    void operator=(const Etaj &etj)
//    {
//        id=etj.id;
//        nr=etj.nr;
//        lift=etj.lift;
//
//    }
//
//};
//
//
//
//#endif //OOP_ETAJ_H
