#include <iostream>
using namespace std;

class A1
{
    public:
    A1(int i)
    {
        cout << "c1" << i << endl;
    }

    ~A1()
    {
        cout << "d1" << endl;
    }
};

class A2
{
    public:
    A2()
    {
        cout << "c2" << endl;
    }

    ~A2()
    {
        cout << "d2" << endl;
    }
};

class A3:public A2,virtual public A1
{
    public:
        int j;
        
        A3(int a, int b, int c):A1(a),mA1(b),j(c){
            cout << j << endl;
        }

    private:
        
        A2 mA2;
        A1 mA1;
};

int main()
{
    A3 a(1, 2, 3);

    return 0;
}