#include<iostream>
using namespace std;

class RationalNumber //分数类
{
    friend RationalNumber operator+(RationalNumber &r1, RationalNumber &r2);

    public:
        RationalNumber() {}
        RationalNumber(int a, int b)
        {
            m_a = a;
            if (b > 0)
            {
                m_b = b;
            }

            for (int i = 2; i < 10; i++)
            {
                if (m_a % i == 0 && m_b % i == 0)
                {
                    m_a = m_a / i;
                    m_b = m_b / i;
                }
            }
        }
        //    关系
        bool operator==(RationalNumber &r)
        {
            if (this->m_a == r.m_a && this->m_b == r.m_b)
            {
                return true;
            }
            else
                return false;
        }

        int getm_a()
        {
            return m_a;
        }
        int getm_b()
        {
            return m_b;
        }

    private:
        int m_a;
        int m_b;
};

RationalNumber operator+(RationalNumber &r1, RationalNumber &r2)
{
    RationalNumber r3;
    r3.m_a = r1.m_a * r2.m_b + r2.m_a * r1.m_b;
    r3.m_b = r1.m_b * r2.m_b;
    RationalNumber r4(r3.m_a, r3.m_b);

    return r4;
}
int main()
{
    RationalNumber r1(2, 4);
    cout << r1.getm_a() << "/" << r1.getm_b() << endl;

    RationalNumber r2(3, 4);

    RationalNumber r3;
    r3 = r1 + r2;
    cout << r3.getm_a() << "/" << r3.getm_b() << endl;

    if (r1 == r2)
    {
        cout << "r1==r2" << endl;
    }
    else
    {
        cout << "r1!=r2" << endl;
    }

    system("pause");
    return 0;
}
