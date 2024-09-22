#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {

    }
    void show() const // 常函数
    {

            // m_a = 10;  不可修改
            m_b = 10;
    }

    void func()
    {

    }


    int m_a;

    mutable int m_b;
};

int main()
{
    const Person p1;//常对象，只能调用常函数

    p1.show();

    //p1.func();
}