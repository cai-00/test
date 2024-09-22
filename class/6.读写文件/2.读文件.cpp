#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //first
    char buf1[1024] = {0};
    while(ifs>>buf1)
    {
        cout << buf1 << endl;
    }

    //second
    char buf2[1024] = {0};
    while(ifs.getline(buf2,sizeof(buf2)))
    {
        cout << buf2 << endl;
    }

    //third
    string buf3;

    while(getline(ifs,buf3))
    {
        cout << buf3<< endl;
    }

    //fourth
    char c;
    while((c=ifs.get())!=EOF)
    {
        cout << c;
    }

    ifs.close();

    system("pause");
    return 0;
}