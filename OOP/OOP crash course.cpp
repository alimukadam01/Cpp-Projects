#include <iostream>
#include <conio.h>
using namespace std;


class absractClass
{
    virtual void askForPromotion() = 0;

};


class employee : absractClass
{
    protected:
    
    string Name;
    string Company;
    int Age;


    public:

    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        if(age > 17)
        Age = age;
    }

    int getAge()
    {
        return Age;
    }



    void Info()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    virtual void askForPromotion()
    {
        if(Age>30)
            cout << Name << " got promoted." << endl;

        else
            cout << Name << " didn't get promoted." << endl;  
    }

    virtual void work()
    {
        cout << Name << " is checking email, task backlog and performing tasks..." << endl;
    }
};


class Develepor : public employee
{
    public:
    string favProgrammingLanguage;

    Develepor(string name, string company, int age, string FavProgrammingLanguage)
        : employee(name, company, age)
    {
        favProgrammingLanguage = FavProgrammingLanguage;
    }

    void fixBug()
    {
        cout << Name << " will fix the bug using " <<  favProgrammingLanguage << endl;
    }


    void work()
    {
        cout << Name << " is writing " << favProgrammingLanguage << " code." << endl;
    }
};


class teacher : public employee
{
    public:
    string subject;

    teacher(string name, string company, int age, string Subject)
        : employee(name, company, age)
    {
        subject = Subject;
    }


    void prepareLesson()
    {
        cout << Name << " is preparing " << subject << " lesson." << endl;
    }

    void work()
    {
        cout << Name << " is teaching " << subject << endl;
    }
};


int main()
{
    employee employee1("Ali", "Fiverr", 19);
    Develepor develepor1 = Develepor("Qusai", "MMS", 20, "Python");
    teacher teacher1 = teacher("Hunaid", "FCC", 53, "Mathematics");

    employee* e1 = &develepor1;
    employee* e2 = &teacher1;

    e1->work();
    e2->work();

    return 0;
}