#include <iostream>
#include "ExamPrac.h"
using namespace std;


int main()
{

    TDShape s1;
    TDShape s2("Cuboid", 2, 4, 6);

    s1.setName("Cube");
    s1.setLength(20);
    s1.setWidth(12);
    s1.setHeight(1);

    TDShape s3 = s1 + s2;
    s3.showData();
    s3.Area();

    s1.Area();

    return 0;
}