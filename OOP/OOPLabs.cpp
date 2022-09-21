#include <iostream>
using namespace std;

class box
{
    double length;
    double width;
    double height;

    public:
    box() : length(0), width(0), height(0)
    {
    }
    box(int l, int w, int h) : length(l), width(w), height(h)
    {
    }
    double volume()
    {
        return length * width * height;
    }
    void showdata()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume() << endl;
    }
    box operator+(box b)
    {
        box b1;
        b1.length = this->length + b.length;
        b1.width = this->width + b.width;
        b1.height = this->height + b.height;
        return b1;
    }
    box operator-(box b)
    {
        box b1;
        b1.length = this->length - b.length;
        b1.width = this->width - b.width;
        b1.height = this->height - b.height;
        return b1;
    }
    box operator*(box b)
    {
        box b1;
        b1.length = this->length * b.length;
        b1.width = this->width * b.width;
        b1.height = this->height * b.height;
        return b1;
    }
    box operator/(box b)
    {
        box b1;
        b1.length = this->length / b.length;
        b1.width = this->width / b.width;
        b1.height = this->height / b.height;
        return b1;
    }
};

int main()
{
    box b1(2, 4, 5), b2(4, 5, 6), b3 = b1 + b2;
    cout << "Box # 01" << endl;
    b1.showdata();
    cout << endl;
    cout << "Box # 02" << endl;
    b2.showdata();
    cout << endl;
    cout << "Box # 03" << endl;
    b3.showdata();
    cout << endl;
    
    return 0;
}