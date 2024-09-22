#include <iostream>
#include<fstream>
using namespace std;

class Person
{
    public:
        char m_Name[64];
        int m_Age;
};
int main()
{
    //write
    ofstream ofs;
    ofs.open("person.txt",ios::out| ios::binary);

    Person p = {"zhangsan", 18};

    ofs.write((const char *)&p, sizeof(Person));

    ofs.close();

    //read
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);

    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;

    }

    Person p1;
    ifs.read((char *)&p1, sizeof(Person));

    cout << p1.m_Name << p1.m_Age << endl;
    

    ifs.close();

    system("pause");
    return 0;
}