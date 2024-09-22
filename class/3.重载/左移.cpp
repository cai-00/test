#include <iostream>
using namespace std;

class Age
{
    friend ostream &operator<<(ostream &cout, Age &age);

public:
    Age(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    private:
        int m_a;
        int m_b;
};
ostream& operator<<(ostream&cout,Age &p)
{
    cout << "m_a=" << p.m_a << " m_b=" << p.m_b;
    return cout;
}
int main()
{
    Age age(12, 23);
    cout << age << endl;
    system("pause");
    return 0;
}