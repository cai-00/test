#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct student
{
    string name;

    int score;
};

struct teacher
{
    string name;

    struct student Sarr[5];
};

int allocatespace(struct teacher Tarr[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        Tarr[i].name = "teacher-";
        Tarr[i].name += nameSeed[i];

        // cout<<Tarr[i].name<<endl;

        for (int j = 0; j < 5; j++)
        {
            Tarr[i].Sarr[j].name = "student-";
            Tarr[i].Sarr[j].name += nameSeed[j];

            int random = rand() % 61 + 40; // 40~100
            Tarr[i].Sarr[j].score = random;

            // cout<<Tarr[i].Sarr[j].name<<"\t";
        }
        // cout<<endl;
    }
}
void print(struct teacher Tarr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名为" << Tarr[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名为" << Tarr[i].Sarr[j].name << "  成绩为  " << Tarr[i].Sarr[j].score << endl;
        }
    }
}
int main()
{

    srand((unsigned int)time(NULL));

    struct teacher Tarr[3];

    int len = sizeof(Tarr) / sizeof(Tarr[0]);

    allocatespace(Tarr, len);

    print(Tarr, len);

    return 0;
}