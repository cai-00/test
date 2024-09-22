#include<iostream>
#include<string>
using namespace std;

//构造函数
void test01()
{
    string s1;

    const char *str = "hello world";
    string s2(str);

    string s3(s2);

    string s4(4, 'a');

    cout << s2 << s3 << s4;
}
//赋值操作
void test02()
{
    string str1;
    str1 = "hello world";

    string str2;
    str2 = str1;

    string str3;
    str3 = 'q';

    string str4;
    str4.assign("hello world");

    string str5;
    str5.assign("hello C++", 5);
    // 把字符串前五个赋值给str5;

    string str6;
    str6.assign(str5);

    string str7;
    str7.assign(5, 'a');
}
//字符串拼接
void test03()
{
    string s1 = "I";
    s1 += "play game";

    s1 += ':';

    string s2 = "LOL DFN";
    s1 += s2;

    string s3 = "I";
    s3.append("play ");

    s3.append("game abcd", 4);//取前4个

    s3.append(s2);

    s3.append(s2, 0, 3);
    s3.append(s2, 4, 3);//从第二个参数的位置开始截取，取第三个参数个
}
//查找和替换
void test04()
{
    string str1 = "abcdefg";
    int pos = str1.find("de");//存在返回位置下标（4），不存在返回-1；
    //rfind从右边开始找

    str1.replace(1, 3, "1111");
    //从1号位置起3个字符替换为“1111”；
}
//字符串比较
void test05()
{
    string str1 = "hello";
    string str2 = "hello";

    if(str1.compare(str2)==0)//返回0
    {
        cout << "str1==str2" << endl;
    }
    else if (str1.compare(str2) > 0)//返回1
    {
        cout << "str1>str2" << endl;
    }
    else if (str1.compare(str2) < 0)//返回-1
    {
        cout << "str1<str2" << endl;
    }
}
//字符存取
void test06()
{
    string str = "hello";

    for (int i = 0; i < str.size();i++)
    {
        cout << str[i];
    }

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i);
    }

    str.at(1) = 'x';
}
//插入和删除
void test07()
{
    string str = "hello";
    str.insert(1, "111");
    //h111ello

    str.erase(1, 3);

}
//string 子串
void test08()
{
    string str = "abcdef";

    string subStr = str.substr(1, 3);
    //bcd
}
int main()
{
    test01();

    return 0;
}