#include <iostream>
#include <deque>
#include<algorithm>
using namespace std;

void printdeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// 构造函数
void test01()
{
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    printdeque(d1);

    // 区间构造
    deque<int> d2(d1.begin(), d1.end());

    printdeque(d2);

    deque<int> d3(10, 100); // 10个100

    printdeque(d3);

    deque<int> d4(d3);

    printdeque(d4);
}

// 赋值操作
void test02()
{
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    printdeque(d1);

    deque<int> d2;
    d2 = d1;

    printdeque(d2);

    deque<int> d3;
    d3.assign(d1.begin(), d1.end());

    deque<int> d4;
    d4.assign(10, 100);
}

// 大小
void test03()
{
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    printdeque(d1);

    if (d1.empty()) // 为真 代表为空
    {
        cout << "d1为空";
    }
    else
    {
        cout << "d1不为空" << endl;
        // cout << "v1的容量为:" << d1.capacity() << endl;
        cout << "d1的大小为:" << d1.size() << endl;
    }

    // 重新指定大小
    d1.resize(15, 100);
    // 默认用0填充新的位置；可以指定第二个参数来填充

    d1.resize(5);
    // 指定变短，删除超出部分
}
// 插入和删除
void test04()
{
    deque<int> d;
    // 尾插
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    // 头插
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);

    printdeque(d);

    // 尾删
    d.pop_back();

    // 头删
    d.pop_front();

    // 插入
    d.insert(d.begin(), 100);
    //返回新数据位置

    d.insert(d.begin(), 2, 100);

    deque<int> d2;
    // 尾插
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end());//按照区间插入

    // 删除
    deque<int>::iterator it = d.end();
    it++;
    d.erase(it);

    d.erase(d.begin(), d.end());

    // 清空
    d.clear();
}
// 数据存取
void test05()
{
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    // 访问元素
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }

    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";
    }

    cout << "第一个元素" << d1.front() << endl;

    cout << "最后一个元素" << d1.back() << endl;
}

// 排序
void test06()
{
    deque<int> d;
    // 尾插
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    // 头插
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);

    //排序
    sort(d.begin(), d.end());
    //从小到大
}

int main()
{
}