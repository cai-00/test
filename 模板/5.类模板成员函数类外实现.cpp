#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);

    void ShowPerson();

    T1 name;
    T2 age;
};

template <class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->age = age;
    this->name = name;
}

template <class T1, class T2>
void Person<T1,T2>::ShowPerson()
{
    cout << "name:" << this->name << "age:" << age;
}

int main()
{
    Person<string, int>p("Tom", 20);
}