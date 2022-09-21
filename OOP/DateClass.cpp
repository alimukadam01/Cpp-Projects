#include<iostream>
#include<conio.h>
using namespace std;

class date
{
    private:
    int year;
    int month;
    int day;

    public:
    static const int monthsperyear = 12;
    date(int y, int m, int d)
    {
       year = (y > 0 && y <= 2050) ? y : 0;
       month = (m > 0 && m <= 12) ? m : 0;
       day = checkday(d);
    }

    int checkday(int d1)
    {
        int dayspermonth[monthsperyear + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d1 <= dayspermonth[month])
        {
            return d1;
        }
        else
        {
            return 0;
        }
    }

    void showdate()
    {
        string name[] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        cout << year << "/" << name[month] << "/" << day;
    }
};


class time
{
    private:
    int hour;
    int min;
    int sec;

    public:
    
    time(int h, int m, int s)
    {
        hour = (h > 0 && h < 25) ? h : 0;
        min = (m > 0 && m < 61) ? m : 0;
        sec = (s > 0 && s < 61) ? s : 0;

    }

    void showtime()
    { 
      cout << hour << ":" << min << ":" << sec << endl;  
    }
    
};


class employee
{
    private:
    string name;
    string dept;
    date birthdate;
    date joiningdate;
    time joiningtime;

    public:

    employee(string n, string d, date bd, date jd, time jt) : name(n), dept(d), birthdate(bd), joiningdate(jd), joiningtime(jt)
    {

    }
    
    void showdata()
    {
        cout << "Employee name is " << name << endl;
        cout << "Employee department is " << dept << endl;
        cout << "Employee born on ";
        birthdate.showdate();
        cout << endl << "Employee joined " << dept << " in ";
        joiningdate.showdate();
        cout << " at time ";
        joiningtime.showtime();
    }
};
int main()
{   
    date bd1(2001, 9, 29);
    date jd1(2020, 7, 1);
    time jt1(13, 12, 11);
    employee e1("Ali", "Sotware Engineering", bd1, jd1, jt1);
    e1.showdata();

    return 0;
}