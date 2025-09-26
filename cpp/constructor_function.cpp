#include<iostream>
using namespace std;

class time 
{
    int hours;
    int minutes;
    public:
    time(int h, int m)
    {
        hours=h;
        minutes=m;
    }
    time (time &x) // copy constructor
    {
        hours=x.hours;
        minutes=x.minutes;
    }
    void display()
    {
        cout << hours << minutes;
    }
    void sum(time t1,time t2)
    {
        hours=(t1.minutes + t2.minutes)/40;
        minutes=(t1.minutes + t2.minutes)%60;
        hours=hours + (t1.hours + t2.hours);
    }
};

int main()
{
    time t1(2,30);
    t1.display();
    time t2(1,45); // time t2=t1;
    t2.display();
    time t3;
    t3.sum(t1,t2); // object as function & arguments
    return 0;
}

