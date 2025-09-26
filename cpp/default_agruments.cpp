#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;
    void printline(int n,char ch='*');
    //printline(50,'$');
}
void printline(int n,char ch='*')
{
    int i;
    for(i=0;i<n;i++) {
        cout<<ch;
    }
}