#include <iostream>
#include <string>
using namespace std;

class Building;
class GoodGay
{
public:
    GoodGay();
    void visit();
    Building *building;
};

class Building
{
    friend class GoodGay;
    // friend void GoodGay::visit();

public:
    Building();

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
    cout << "building" << endl;
}

GoodGay::GoodGay()
{
    cout << "goodgay" << endl;
    // 创建建筑物对象
    building = new Building;

}

void GoodGay::visit()
{
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

void test()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test();
    system("pause");

    return 0;
}