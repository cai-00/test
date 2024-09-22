#include<iostream>
using namespace std;
int main ()
{
    //质数和不超过N，最多num个，和为ans
    int N, num, ans = 0;
    cin >>N;

    for (int i = 2;;i++)
    {
        int is_prime = 1;
        for (int j = 2; j * j <= i;j++)
        {
            if(i%j==0)
            {
                is_prime = 0;
                break;
            }
        }

            if(!is_prime)
                continue;
            if(i+ans>N)
                break;
            cout << i << endl;
            ans+=i;
            num++;
        
    }

    cout << num <<endl<< ans;

    system("pause");

    return 0;
}