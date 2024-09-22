#include <iostream>
using namespace std;

class Building
{
    friend void goodGay(Building &building);
    friend void goodGay2(Building *building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};
// 引用
void goodGay(Building &building)
{
    cout << building.m_SittingRoom << endl;
    cout << building.m_BedRoom << endl;
}

void test()
{
    Building building;
    goodGay(building);
}
// 指针
void goodGay2(Building *building)
{
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

void test2()
{
    Building building;
    goodGay2(&building);
}

int main()
{
    test();
    test2();

    system("pause");
    return 0;
}