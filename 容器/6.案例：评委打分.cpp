#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

class Person
{
    public:
    Person(string name,int score)
    {
        this->name = name;
        this->score = score;
    }

    string name;
    int score;
};

void creatPerson(vector<Person>&v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5;i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        v.push_back(p);
    }
}

void setScore(vector<Person> &v) 
{
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        deque<int> d;
        for (int i = 0; i < 10;i++)
        {
            int score = rand() % 41 + 60;//60~100
            d.push_back(score);
        }

        sort(d.begin(), d.end());

        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
        {
            sum += *dit;
        }

        int avg = sum / d.size();

        it->score = avg;
    }
}

void showScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << "name:" << it->name << "score:" << it->score << endl;
    }
}
int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    
    vector<Person>v;
    creatPerson(v);

    setScore(v);

    showScore(v);

    system("pause");
    return 0;
}