#include <iostream>
using namespace std;
class Myprint
{
    public:

    void operator()(string test)
    {
        cout << test << endl;
    }


};
class Date
{
public:
    int  operator()(int a,int b)
    {
        return a + b;
    }
};
int main()
{
    Myprint print;
    print("hello world");

    Date d;
    cout<<d(12, 13);
    system("pause");
    return 0;
}