#include<iostream>
#include<stack>
using namespace std;

void test01()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.size()<<endl;

    while(!s.empty())
    {
        cout << s.top();

        s.pop();
    }

    cout << s.size();
}

int main()
{
    test01();
}