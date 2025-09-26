#include<iostream>
using namespace std;
class bus_info
{
    int bus_id;
    string bustype;
    int n;
    public:
    void getdata(int bno,string btype,int x);
    void putdata();
};

void bus_info :: getdata(int bno,string btype,int x)
{
    bus_id = bno;
    bustype = btype;
    n = x;
}
void bus_info :: putdata()
{
    cout << "Bus ID: ";
    cout << bus_id << endl;
    cout << "Bus Type: ";
    cout << bustype << endl;
    cout << "Number of Seats: ";
    cout << n << endl;
}
int main()
{
    bus_info x;
    x.getdata(1,"AC",55);
    x.putdata();
    return 0;
}
