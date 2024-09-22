#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Sort(T arr, int len)
{
    for (int i = 0; i < len;i++)
    {
        int min = i;
        for (int j = i+1; j < len;j++)
        {
            if(arr[min]>arr[j])
                min = j;
        }
        if(min!=i)
        {
            Swap(arr[min], arr[i]);
        }
    }
}

template<class T>
void printArr(T arr,int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    char charArr[] = "bdsaf";

    int num = sizeof(charArr) / sizeof(char);

    Sort(charArr, num);

    printArr(charArr, num);

    return 0;
}
