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
    Elipsa(const Elipsa &E){ a = E.a; b = E.b;}

    double getA()const {return a;}
    double getB()const {return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    double Povrsina()
    {
        double P = a*b*3.14;
        return P;
    }
     double Obim()
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

    double Povrsina()
    {
        double P = a*b;
        return P;
    }
    double Obim()
    {
        double O = 2*(a+b);
        return O;
    }
};
class Oblik
{
private:
    Pravougaonik A;
    Elipsa B;
public:
    Oblik() : A(), B(){}
    Oblik(double x, double y,double x1, double y1) : A(x,y), B(x1,y1){}
    Oblik(const Oblik &O) : A(O.A), B(O.B){}
double Obim2()
    {
        return A.Obim()+ B.Obim();
    }
    double Povrsina2()
    {
        return A.Povrsina()- B.Povrsina();
    }
};
class pravilanOblik : Oblik
{
public:
    Obim2(){};
    Povrsina2(){};
    pravilanOblik() : Oblik(3,3,2,2){}
    pravilanOblik(double x, double y) : Oblik(x,x,y,y){}
    pravilanOblik(const pravilanOblik &P) : Oblik((Oblik)P){}
};

int main()
{
    Pravougaonik P;
    Pravougaonik P1(3,7);
    Pravougaonik P2(P);
    cout<<P.Obim()<<","<<P.Povrsina()<<endl;
    cout<<P1.Obim()<<","<<P1.Povrsina()<<endl;
    cout<<P2.Obim()<<","<<P2.Povrsina()<<endl;

    Elipsa E;
    Elipsa E1(2,5);
    Elipsa E2(E);
    cout<<E.Obim()<<","<<E.Povrsina()<<endl;
    cout<<E1.Obim()<<","<<E1.Povrsina()<<endl;
    cout<<E2.Obim()<<","<<E2.Povrsina()<<endl;

    Oblik O;
    Oblik O1(5,2,3,4);
    Oblik O2(O);
    cout<<O.Obim2()<<","<<O.Povrsina2()<<endl;
    cout<<O1.Obim2()<<","<<O1.Povrsina2()<<endl;
    cout<<O2.Obim2()<<","<<O2.Povrsina2()<<endl;

    pravilanOblik PO;
    pravilanOblik PO1(2,3);
    pravilanOblik PO2(PO);
    cout<<PO.Obim2()<<","<<PO.Povrsina2()<<endl;
    cout<<PO1.Obim2()<<","<<PO1.Povrsina2()<<endl;
    cout<<PO2.Obim2()<<","<<PO2.Povrsina2()<<endl;
    return 0;
}
