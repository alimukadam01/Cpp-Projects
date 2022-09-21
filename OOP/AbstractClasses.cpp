#include<iostream>
#include<conio.h>
using namespace std;

class Instrument
{    
    private:
    string name;

    public:

    virtual void makeSound() = 0; 

};


class Accordian : public Instrument
{
    public:
    
    void makeSound()
    {
        cout << "Accordian playing..." << endl;
    }

};


class Piano : public Instrument
{
    public:

    void makeSound()
    {
        cout << "Piano playing..." << endl;
    }
};

int main()
{
    
    Instrument* i1 = new Accordian();
    Instrument* i2 = new Piano();
 
    Instrument* instruments[2] = {i1, i2};

    for(int i=0; i < 2; i++)
    {
        instruments[i]->makeSound();
    } 

    return 0;
}

