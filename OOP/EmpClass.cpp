#include<iostream>
#include<conio.h>
using namespace std;

class employee
{
    private:
    string name;
    int  empId; 
    int salary; 
    int grade;

    public:

    employee(string n, int ID, int Salary,int Grade)
    {
        name = n;
        empId = ID;
        salary = Salary; 
        grade = Grade;
    } 

    void setSalary(int s)
    {
        salary = s;
    }

    void setGrade(int g)
    {
        grade = g;
    }

    int getSalary()
    {
        return salary;
    }

    int getGrade()
    {
        return grade;
    }

    void showData()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Salary: " << salary << endl;
    }

    void increment()
    {
        if(grade >= 21)
        {
            salary = (salary * 0.05) + salary;
            cout << "The salary now is: " << salary << endl;

        }

        else
        { 
            cout << "The salary is still: " << salary << endl;
        }
    }

};

int main()
{
    employee e1("Ali", 2014, 50000, 20);
    
    e1.showData();
    e1.increment();

    e1.setGrade(22);
    e1.showData();
    e1.increment();
   
    return 0;
}