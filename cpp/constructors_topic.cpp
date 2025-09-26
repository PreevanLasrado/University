/* Topics – Default, parameterized, copy constructors, Default arguments with
constructor, Dynamic initialization of objects using parameterized constructor,
Dynamic constructor */

#include<iostream>
using namespace std;

class Time {
int hours;
int minutes;

public:
// 1. Default constructor
Time() 
{
    hours=0;
    minutes=0;
}

// 2. Parameterized constructor with default arguments
Time(int h=1, int m=30) 
{
    hours = h;
    minutes = m;
}

// 3. Copy constructor
Time(Time &t) 
{
    hours = t.hours;
    minutes = t.minutes;
}

// Display time
void puttime()
{
    cout << "Hours:" << hours << "Minutes:" << minutes << endl;
}

// Function to add two times
void sum(Time t1, Time t2) 
{
    minutes = t1.minutes + t2.minutes;
    hours = minutes / 60;
    minutes = minutes % 60;
    hours = hours + t1.hours + t2.hours;
}
};

int main()
{
// Dynamic initialization of objects using parameterized constructor
Time t1(2, 45), t2(3, 30);

// 4. Dynamic constructor (object created on heap)
Time *t4 = new Time(1, 50); // dynamically created object

// Default arguments with constructor
Time t3(2);
cout << "\n"; 
t3.puttime();

// Use sum method to add t1 and t2 and store result in t3
t3.sum(t1, t2);

// Copy constructor example
Time t5 = t3;

// Output
cout << "\nTime t1:\n";
t1.puttime();
cout << "\nTime t2:\n"; 
t2.puttime();
cout << "\nSum (t3 = t1 + t2):\n"; 
t3.puttime();
cout << "\nCopy of t3 in t5:\n"; 
t5.puttime();
cout << "\nDynamically created t4:\n"; 
t4->puttime();

// Free dynamically allocated memory
delete t4;

return 0;
}