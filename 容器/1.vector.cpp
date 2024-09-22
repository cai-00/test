#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void myPrint(int val)
{
    cout << val << endl;
}
void test1()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //first
    vector<int>::iterator itBegin = v.begin();

    vector<int>::iterator itEnd = v.end();

    while(itBegin!=itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    //second
    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << endl;
    }
    //third
    for_each(v.begin(), v.end(), myPrint);
}
 
//自定义数据类型
class Person
{
    public:
    Person(string name,int age)
    {
        m_name = name;
        m_age = age;
    }

    string m_name;
    int m_age;
};
void test2()
{
    vector<Person> v;

    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << it->m_name
             << it->m_age << endl;
    }
}

void test3()
{
    vector<Person*> v;

    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_name
             << (*it)->m_age << endl;
    }
}

int main()
{
    test1();

    return 0;
}