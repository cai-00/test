#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// 构造函数
void test01()
{
    vector<int> v1;

    for (int i = 0; i <10;i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    //区间构造
    vector<int> v2(v1.begin(), v1.end());

    printVector(v2);

    vector<int> v3(10, 100);//10个100

    printVector(v3);

    vector<int> v4(v3);

    printVector(v4);
}

//赋值操作
void test02()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    vector<int> v2;
    v2 = v1;

    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());

    vector<int> v4;
    v4.assign(10, 100);
}

//容量和大小
void test03()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    if(v1.empty())//为真 代表为空
    {
        cout << "v1为空";
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量为:" << v1.capacity() << endl;
        cout << "v1的大小为:" << v1.size() << endl;
    }

    //重新指定大小,容量不变
    v1.resize(15,100);
    //默认用0填充新的位置；可以指定第二个参数来填充

    v1.resize(5);
    //指定变短，删除超出部分
}
//插入和删除
void test04()
{
    vector<int> v;
    //尾插
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    printVector(v);

    //尾删
    v.pop_back();

    //插入
    v.insert(v.begin(), 100);

    v.insert(v.begin(), 2,100);

    //删除
    v.erase(v.begin());

    v.erase(v.begin(), v.end());

    //清空
    v.clear();
}
//数据存取
void test05()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    //访问元素
    for (int i = 0; i < v1.size();i++)
    {
        cout << v1[i] << " ";
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }

    cout << "第一个元素" << v1.front() << endl;

    cout << "最后一个元素" << v1.back() << endl;
}

//互换容器
void test06()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int> v2;

    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    //交换

    v1.swap(v2);

    //实际用途，收缩内存
    vector<int> v;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量为:" << v.capacity() << endl;
    cout << "v的大小为:" << v.size() << endl;

    v.resize(3);
    cout << "v的容量为:" << v.capacity() << endl;
    cout << "v的大小为:" << v.size() << endl;

    vector<int>(v).swap(v);
    //vector<int>(v)为匿名对象， .Swap(v)是把匿名对象和v交换
    cout << "v的容量为:" << v.capacity() << endl;
    cout << "v的大小为:" << v.size() << endl;
}
//预留空间
void test07()
{
    vector<int> v;

    //预留空间
    v.reserve(100000);

    int num = 0;//统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if(p!=&v[0])
        {
            p = &v[0];

            num++;
        }
    }
}

int main()
{
    
}