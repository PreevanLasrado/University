#include<iostream>
using namespace std;

class time 
{
    int hours;
    int minutes;
    public:
    time ()
    {
        hours=0;
        minutes=0;
    }
    void display()
    {
        cout << hours << minutes;
    }
};

int main()
{
    time t1;
    t1.display();
    return 0;
}