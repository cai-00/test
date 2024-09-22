#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num[5] = {2, 4, 5, 6, 1};

    sort(num, num + 5);

    for (int i = 0; i < 5;i++)
    {
        cout << num[i] << endl;
    }

    system("pause");

    return 0;
}