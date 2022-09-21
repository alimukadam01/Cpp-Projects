#include<iostream>
#include<conio.h>
using namespace std;

class Box
{
    private:
    
    double width;
    double height;
    double length;

    public:

    Box()
    {

    }

    Box(double w, double h, double l) : width(w), height(h), length(l)
    {

    }

    double volume()
    {
        return height * width * length;
    }

    void setheight(double h)
    {
        height = h;
    }

    double getheight()
    {
        return height;
    }

    void setwidth(double w)
    {
        width = w;
    }

    double getwidth()
    {
        return width;
    }

    void setlength(double l)
    {
        length = l;
    }

    double getlength()
    {
        return length;
    }

    Box operator + (const Box &b)
    {
        Box box1;
        box1.height = this -> height + b.height;
        box1.width = this -> width + b.width;
        box1.length = this -> length + b.length;
        return box1;
    }

    Box operator - (const Box &b)
    {
        Box box1;
        box1.height = this -> height - b.height;
        box1.width = this -> width - b.width;
        box1.length = this -> length - b.length;
        return box1;
    }

    Box operator * (const Box &b)
    {
        Box box1;
        box1.height = this -> height * b.height;
        box1.width = this -> width * b.width;
        box1.length = this -> length * b.length;
        return box1;
    }

    Box operator / (const Box &b)
    {
        Box box1;
        box1.height = this -> height / b.height;
        box1.width = this -> width / b.width;
        box1.length = this -> length / b.length;
        return box1;
    }


};


class Complex
{
    private:
    double real;
    double img;

    public:

    Complex()
};


int main()
{
    Box b1(3, 4, 5);
    Box b2(5, 6, 7);

    Box b3 = b1 + b2;
    cout << b3.getheight() << endl;
    cout << b3.getlength() << endl;
    cout << b3.getwidth() << endl;




    return 0;
}