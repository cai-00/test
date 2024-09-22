#include <iostream>
using namespace std;
class Age
{
public:
    Age(int a)
    {
        m_a = new int(a);
    }

    ~Age()
    {
        if(m_a!=NULL)
        {
            delete m_a;
            m_a = NULL;
        }

    }

    Age &operator=(const Age &p)
    {
        if (m_a != NULL)
        {
            delete m_a;
            m_a = NULL;
        }
        m_a = new int(*p.m_a);
        return *this;
    }
    

public:
    int* m_a;
};
int main()
{
    
    Age p1(18);
    Age p2(20);
    p2 = p1;

    cout << *p1.m_a << endl;
    cout << *p2.m_a << endl;

    system("pause");
    return 0;
}
