#include<iostream>
using namespace std;

int *fun()
{
    int *a = new int(10);
    return a;
}

int main ()
{
    int *p = fun();
    cout << *p << endl;
    delete p;

    int *arr = new int[10];
    for (int i = 0; i < 10;i++)
    {
        arr[i] = i + 100;

    }

    for (int i = 0; i < 10;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;

    system("pause");

    return 0;
}