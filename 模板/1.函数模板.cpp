#include <iostream>
using namespace std;

template<typename T>
void Swap(T&a,T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void func()
{
    cout << "func" << endl;
}

void test()
{
    func<int>();
}

int main()
{
    int a = 10;
    int b = 20;

    Swap(a, b);
    cout << a << endl
         << b << endl;

    Swap<int>(a, b);
    cout << a << endl
         << b << endl;

    system("pause");
    return 0;
}