#include <iostream>
using namespace std;

class person
{
public:
    person()
    {
        cout << "构造函数" << endl;
    }

    person(int a, int height)
    {
        m_age = a;
        m_height = new int(height);
        cout << "有参构造函数" << endl;
    }

    person(const person &p) // 拷贝构造
    {
        m_age = p.m_age;
        cout << "拷贝函数 " << endl;
        m_height = new int(*p.m_height); // 深拷贝
    }

    ~person()
    {
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        cout << "析构函数" << endl;
    }

    int m_age;
    int *m_height;
};

void test()
{
    person p1(18, 160);

    person p2(p1);

    cout << p1.m_age << endl;
    cout << *p1.m_height << endl;
    cout << p2.m_age << endl;
    cout << *p2.m_height << endl;
}

int main()
{
    test();

    return 0;
}
