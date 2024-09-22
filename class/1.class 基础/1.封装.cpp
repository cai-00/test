#include <iostream>
using namespace std;

double PI = 3.14;

// 创建一个类
class circle
{
public: // 访问权限
    // 属性和行为都为成员

    // 属性 成员属性 成员变量
    int m_r;

    // 行为 成员函数 成员方法

    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main()
{
    // 创建一个对象(实例化）

    circle c1;

    c1.m_r = 3;

    cout << "c1的周长为:" << c1.calculateZC() << endl;
    

    system("pause");

    return 0;
}