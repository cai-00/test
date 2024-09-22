#include<iostream>
#include<queue>
using namespace std;

class Person
{
    public:
        Person(string name,int age)
        {
            this->age = age;
            this->name = name;
        }

        string name;
        int age;
};

void test()
{
    queue<Person> q;

    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);

    q.push(p1);
    q.push(p2);
    q.push(p3);

    cout << q.size() << endl;

    while (!q.empty())
    {
        cout << q.front().name<<q.front().age;

        cout << q.back().name << q.back().age;

        q.pop();
    }

    cout << q.size();
}