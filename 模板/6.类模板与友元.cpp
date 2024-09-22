#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person;

template <class T1, class T2>
void print2(Person<T1, T2> p)
{
    cout << p.name << p.age << endl;
}

template <class T1, class T2>
class Person
{
    //全局函数类内实现
    friend void print1(Person<T1, T2> p)
    {
        cout << p.name << p.age << endl;
    }
    // 全局函数类外实现
    //加空模板函数列表，且让编译器提前知道
    friend void print2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->age = age;
        this->name = name;
    }
private:
    T1 name;
    T2 age;
};

void test1()
{
    Person<string, int> p("Tom", 18);
    print1(p);
}
void test2()
{
    Person<string, int> p("Jerry", 18);
    print1(p);
}
int main()
{
    Person<string, int> p("Tom", 20);
}