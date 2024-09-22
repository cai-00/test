#include <iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person
{
    public:

    Person(NameType name,AgeType age)
    {
        this->age = age;
        this->name = name;
    }

    void ShowPerson(){
        cout << "name:" << this->name << "age:" << age;
    }

    NameType name;
    AgeType age;
};
void test01()
{
    Person<string, int> p1("cai", 999);
    p1.ShowPerson();
}


//类对象做函数参数
//1.指定传入类型
void Print(Person<string, int>&p)
{
    p.ShowPerson();
}
void test02()
{
    Person<string, int> p("cai", 999);

    Print(p);
}
//2.参数模板化
template<class T1,class T2>
void Print2(Person<T1, T2> &p)
{
    p.ShowPerson();
    cout << "T1的类型:" << typeid(T1).name() << endl;
    cout << "T2的类型:" << typeid(T2).name() << endl;
}

void test03()
{
    Person<string, int> p("cai", 99);

    Print2(p);
}

//3.整个模板化
template <class T>
void Print3(T &p)
{
    p.ShowPerson();

    cout << "T的类型:" << typeid(T).name() << endl;
}

void test03()
{
    Person<string, int> p("cai", 9);

    Print3(p);
}

int main()
{
    test02();

    system("pause");
    return 0;
}