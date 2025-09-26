#include<iostream>
using namespace std;

class set
{
    int m,n;
    public:
    void input(void);
    void display(void);
    int largest(void);
};
void set :: input(void)
{
    cin >> m >> n;
}
int set :: largest(void)
{
    if (m>n) return m;
    else return n;
}
void set :: display(void)
{
    cout << largest() << endl;
}

int main()
{
    set x;
    x.input();
    x.display();
    return 0;
}