#include <iostream>
#include <conio.h>
#include "ExamPrac.h"
using namespace std;

Shape::Shape()
{
    name = "not specified";
    length = 0;
    width = 0;
}

Shape::Shape(string n, int l, int w) : name(n), length(l), width(w) {}

void Shape::setName(string n)
{
    Shape::name = n;
}

string Shape::getName() const
{
    return name;
}

void Shape::setLength(int l)
{
    length = l;
}

int Shape::getLength() const
{
    return length;
}

void Shape::setWidth(int w)
{
    width = w;
}

int Shape::getWidth() const
{
    return width;
}

void Shape::showData()
{
    cout << "The name of the shape is " << this->getName() << endl;
    cout << "The length is " << this->getLength() << endl;
    cout << "The width is " << this->getWidth() << endl;
}

TDShape::TDShape()
{
    name ;
    length;
    width;
    height;
}

TDShape::TDShape(string n, int l, int w, int h) : Shape(name, length, width)
{
    height = h;
}

void TDShape::setHeight(int h)
{
    height = h;
}

int TDShape::getHeight() const
{
    return height;
}

void TDShape::showData()
{
    cout << "The name of the shape is " << name << endl;
    cout << "The length is " << length << endl;
    cout << "The width is " << width << endl;
    cout << "The height is " << height << endl;
}

void TDShape::Area()
{
    cout << "the area of this object is " << length * width * height << endl;
}

TDShape TDShape::operator+(const TDShape &b)
{
    TDShape s1;
    s1.height = this->height + b.height;
    s1.length = this->length + b.length;
    s1.width = this->width + b.width;

    return s1;
}

TDShape TDShape::operator-(const TDShape &b)
{
    TDShape s1;
    s1.height = this->height - b.height;
    s1.length = this->length - b.length;
    s1.width = this->width - b.width;
    return s1;
}

TDShape TDShape::operator*(const TDShape &b)
{
    TDShape s1;
    s1.height = this->height * b.height;
    s1.length = this->length * b.length;
    s1.width = this->width * b.width;
    return s1;
}

TDShape TDShape::operator/(const TDShape &b)
{
    TDShape s1;
    s1.height = this->height / b.height;
    s1.length = this->length / b.length;
    s1.width = this->width / b.width;
    return s1;
}

