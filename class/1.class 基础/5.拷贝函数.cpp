#include <iostream>
using namespace std;

class person
{
public:
    person()
    {
        cout << "构造函数" << endl;
    }

    person(int a)
    {
        m_age = a;
        cout << "有参构造函数" << endl;
    }

    person(const person &p) // 拷贝构造
    {
        m_age = p.m_age;
        cout << "拷贝函数 " << endl;
    }

    ~person()
    {
        cout << "析构函数" << endl;
    }

    int m_age;
};

void test()
{
    person p1(10);
    person p2(p1);

    cout << p1.m_age << endl;
    cout << p2.m_age << endl;
}

void dowork(person p)
{
}
void test1()
{
    person p5;
    dowork(p5);
}

// 3.值方式返回局部变量

person dowork2()
{
    person p3;
    cout << (int *)&p3 << endl;
    return p3;
}

void test2()
{
    person p = dowork2();
    cout << (int *)&p << endl;
}

int main()
{

    // test();
    // test1();
    test2();

    system("pause");

    return 0;
}