#include <iostream>
#include <cmath>
using namespace std;

class Figura
{
private:
    double a;
    double b;
public:
    virtual double Povrsina() = 0;
    virtual double Obim() = 0;
};

class Elipsa : Figura
{
private:
    double a;
    double b;
public:
    Elipsa(){a = 2.00; b = 3.00;}
    Elipsa(double aa, double bb){a = aa; b = bb;}
    Elispa(const Elipsa &E){ a = E.a; b = E.b;}

    double getA()const {return a;}
    double getB()const {return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    virtual double Povrsina()
    {
        double P = a*b*3.14;
        return P;
    }
    virtual double Obim()
    {
        double O = 3.14*(3*(a + b)-sqrt((3*a + b)*(a + 3*b)));
        return O;
    }
};
class Pravougaonik : Figura
{
private:
    double a;
    double b;
public:
    Pravougaonik(){a = 3.00; b = 5.00;}
    Pravougaonik(double aa, double bb){a = aa; b = bb;}
    Pravougaonik(const Pravougaonik &P){ a = P.a; b = P.b;}

    double getA()const {return a;}
    double getB()const {return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    virtual double Povrsina()
    {
        double P = a*b;
        return P;
    }
    virtual double Obim()
    {
        double O = 2*(a+b);
        return O;
    }
};
