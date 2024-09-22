#include <iostream>
using namespace std;

class Age
{
    friend ostream &operator<<(ostream &cout, Age &age);

public:
    Age(int a)
    {
        m_a = a;
    }

    Age &operator++()
    {
        m_a++;
        return *this;
    }

    Age operator++(int)
    {
        Age temp = *this;
        m_a++;
        return temp;
    }

private:
    int m_a;
};
ostream &operator<<(ostream &cout, Age &p)
{
    cout << "m_a=" << p.m_a ;
    return cout;
}

int main()
{
    Age age(12);
    age++;

    cout << ++age << endl;
    cout << age << endl;

    system("pause");
    return 0;
}