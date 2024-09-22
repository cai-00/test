#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int a = 0;

    srand(time(0));

    a = rand() % 100 + 1;//1~100

    cout << a << endl;

    system("pause");

    return 0;
}