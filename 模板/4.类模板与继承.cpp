#include <iostream>
using namespace std;

template<class T>
class Base
{
    T m;
};

class Son:public Base<int>
{
};

void test()
{
    Son s1;
}

//子类也为类模板
template<class T1,class T2>
class Son2:public Base<T2>
{
    T1 obj;
};

void test2()
{
    Son2<int, char> s2;
}

int main()
{
    system("pause");
    return 0;
}