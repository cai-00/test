#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

void printlist(list<int> &v)
{
    for (list<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// 构造函数
void test01()
{
    list<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printlist(v1);

    // 区间构造
    list<int> v2(v1.begin(), v1.end());

    printlist(v2);

    list<int> v3(10, 100); // 10个100

    printlist(v3);

    list<int> v4(v3);

    printlist(v4);
}

// 赋值操作
void test02()
{
    list<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printlist(v1);

    list<int> v2;
    v2 = v1;

    printlist(v2);

    list<int> v3;
    v3.assign(v1.begin(), v1.end());

    list<int > v4;
    v4.assign(10, 100);

    //交换
    v3.swap(v1);
}

// 容量和大小
void test03()
{
    list<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printlist(v1);

    if (v1.empty()) // 为真 代表为空
    {
        cout << "v1为空";
    }
    else
    {
        cout << "v1不为空" << endl;
        // cout << "v1的容量为:" << v1.capacity() << endl;
        cout << "v1的大小为:" << v1.size() << endl;
    }

    // 重新指定大小,容量不变
    v1.resize(15, 100);
    // 默认用0填充新的位置；可以指定第二个参数来填充

    v1.resize(5);
    // 指定变短，删除超出部分
}
// 插入和删除
void test04()
{
    list<int> v;
    // 尾插
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //头插
    v.push_front(10);

    printlist(v);

    // 尾删
    v.pop_back();

    //头删
    v.pop_front();

    // 插入
    v.insert(v.begin(), 100);

    v.insert(v.begin(), 2, 100);

    // 删除
    v.erase(v.begin());

    v.erase(v.begin(), v.end());

    //移除
    v.push_back(1000);
    v.remove(1000);

    // 清空
    v.clear();
}
// 数据存取
void test05()
{
    list<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }


    cout << "第一个元素" << v1.front() << endl;

    cout << "最后一个元素" << v1.back() << endl;
}
bool myCompare(int v1,int v2)
{
    return v1 > v2;
}
//反转和排序
void test06()
{
    list<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    printlist(v);
    v.reverse();

    v.sort();//升序

    v.sort(myCompare);//降序，指定规则（自定义)

}

int main()
{
}