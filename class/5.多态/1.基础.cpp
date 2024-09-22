#include <iostream>
using namespace std;

class Animal
{
    public:
    virtual void speak()  //虚函数
    {
        cout << "动物在说话" << endl;
    }
};

class Cat:public Animal
{
    public:
    void speak()  //重写
    {
        cout << "猫在说话" << endl;
    }
};

void dospeak(Animal& animal)
{
    animal.speak();
}
int main()
{
    Cat cat;
    dospeak(cat);

    system("pause");
    return 0;
}