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
        age = a;
        cout << "有参构造函数" << endl;
    }

    person(const person &p) // 拷贝构造
    {
        age = p.age;
        cout << "拷贝函数 " << endl;
    }

    ~person()
    {
        cout << "析构函数" << endl;
    }

    int age;
};

int test()
{
    // 1.括号法
    person p1; // 默认构造不加括号
    person p2(10);
    person p3(p2);

    cout << p1.age << endl;
    cout << p2.age << endl;
    cout << p3.age << endl;

    // 2.显示法
    person p4;
    person p5 = person(20);
    person p6 = person(p5);

    // 3.隐式转化法
    person p7;
    person p8 = 50;
    person p9 = p8;
}

int main()
{

    test();
    system("pause");

    return 0;
}