#include <iostream>
using namespace std;

void bubblesort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shuchu(int *arr, int len)
{
    for (int i = 0; i < len; i++)

        cout << arr[i] << "\t" << endl;
}

int main()
{

    int arr[] = {3, 5, 4, 2, 1, 6, 7, 8, 9, 10};

    int len = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, len);

    shuchu(arr, len);
}