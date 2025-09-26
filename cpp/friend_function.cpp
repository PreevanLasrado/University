#include<iostream>
using namespace std;

class sample
{
    float a,b;
    public:
    void getdata(void);
    friend float mean(sample s);
};
void sample  :: getdata(void)
{
    cin >> a >> b;
}
float mean(sample s)
{
    float t;
    t=(s.a+s.b)/2;
    return t;
}
int main()
{
    sample s;
    s.getdata();
    float t1;
    t1=mean(s);
    cout << t1;
    return 0;
}
