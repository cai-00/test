#include <iostream>
using namespace std;
#define MAX 1000
void showmenu()
{
    cout << "1.添加联系人 " << endl;
    cout << "2.显示联系人 " << endl;
    cout << "3.删除联系人 " << endl;
    cout << "4.查找联系人 " << endl;
    cout << "5.修改联系人 " << endl;
    cout << "6.清空联系人 " << endl;
    cout << "0.退出通讯录 " << endl;
}

struct person
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};

struct addressbooks
{
    struct person personarray[MAX]; // 数组
    int m_size;
};

void addperson(addressbooks *abs)
{
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满" << endl;
        return;
    }

    else
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[abs->m_size].m_name = name;

        cout << "请输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[abs->m_size].m_age = age;

        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personarray[abs->m_size].m_phone = phone;

        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        abs->personarray[abs->m_size].m_address = address;

        abs->m_size++;

        cout << "添加成功" << endl;

        system("pause");

        system("cls"); // 清屏操作
    }
}

void showperson(addressbooks *abs)
{
    if (abs->m_size == 0)
    {
        cout << "通讯录为零" << endl;
    }

    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {

            cout << "姓名:" << abs->personarray[i].m_name << "\t";
            cout << "性别：" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personarray[i].m_age << "\t";
            cout << "电话：" << abs->personarray[i].m_phone << "\t";
            cout << "住址：" << abs->personarray[i].m_address << endl;
        }
    }

    system("pause");
    system("cls");
}

int exist(addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personarray[i].m_name == name)
        {
            return i;
        }
    }

    return -1;
}

void deleteperson(addressbooks *abs)
{
    cout << "请输入要删除联系人的名字" << endl;
    string name;
    cin >> name;

    int ret = exist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        for (int i = ret; i < abs->m_size; i++)
        {
            abs->personarray[i] = abs->personarray[i + 1];
            // 联系人前移，相当于删除
        }

        cout << "删除成功" << endl;
        abs->m_size--;
    }

    system("pause");
    system("cls");
}

void findperson(addressbooks *abs)
{
    cout << "请输入要查找联系人的名字" << endl;
    string name;
    cin >> name;
    int ret = exist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "姓名:" << abs->personarray[ret].m_name << "\t";
        cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personarray[ret].m_age << "\t";
        cout << "电话：" << abs->personarray[ret].m_phone << "\t";
        cout << "住址：" << abs->personarray[ret].m_address << endl;
        ;
    }
    system("pause");
    system("cls");
}

void modifyperson(addressbooks *abs)
{
    cout << "请输入要修改联系人的名字" << endl;
    string name;
    cin >> name;
    int ret = exist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[ret].m_name = name;

        cout << "请输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personarray[ret].m_sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[ret].m_age = age;

        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personarray[ret].m_phone = phone;

        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        abs->personarray[ret].m_address = address;

        cout << "修改成功" << endl;

        system("pause");

        system("cls"); // 清屏操作
    }
}

void cleanperson(addressbooks *abs)
{
    cout << "确定清空吗" << endl;
    cout << "1---确定" << endl;
    cout << "2---取消" << endl;
    int a = 0;
    cin >> a;
    if (a == 1)
    {
        abs->m_size = 0;
        cout << "通讯录已清空" << endl;
    }
    else if (a == 2)
    {
        cout << "已取消" << endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    addressbooks abs;

    abs.m_size = 0;

    while (true)
    {

        showmenu();

        int select = 0;

        cin >> select;

        switch (select)
        {
        case 1:

            addperson(&abs);

            break;
        case 2:

            showperson(&abs);
            break;
        case 3:
            /*	{
                    cout<<"请输入联系人的名字"<<endl;
                    string name;
                    cin>>name;
                    if(exist(&abs,name)==-1)
                    {
                        cout<<"查无此人"<<endl;
                    }
                    else
                    {
                        cout<<"查到此人"<<endl;
                    }
                }
                */

            deleteperson(&abs);

            break;
        case 4:

            findperson(&abs);
            break;
        case 5:

            modifyperson(&abs);
            break;
        case 6:
            cleanperson(&abs);
            break;
        case 0:

            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;

            break;
        default:
            break;
        }
    }
    return 0;
}