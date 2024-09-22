#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);

    ofs << "caijianhao" << endl;

    ofs.close();

    system("pause");
    return 0;
}