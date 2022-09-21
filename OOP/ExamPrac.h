#ifndef __EXAM_PRAC__
#define __EXAM_PRAC__
/*#include <iostream>
#include <conio.h>
using namespace std;*/



class Shape
{
    protected:
    std::string name = "not specified";
    int length = 0;
    int width = 0;

    public:

    Shape();

    Shape(std::string n, int l, int w){}

    void setName(std::string n);

    std::string getName() const;

    void setLength(int l);

    int getLength() const;

    void setWidth(int w);

    int getWidth() const;

    void showData();

    virtual void Area()=0;
    
};

class TDShape : public Shape
{
    private:
    int height;

    public:
    TDShape();

    TDShape(std::string n, int l, int w, int h);

    void setHeight(int h);

    int getHeight() const;

    void showData();

    void Area();

    TDShape operator+(const TDShape &b);

    TDShape operator-(const TDShape &b);

    TDShape operator*(const TDShape &b);

    TDShape operator/(const TDShape &b);




};

#endif