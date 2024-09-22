#include <iostream>
using namespace std;

class Calculate
{
    public:

    virtual int getresult()
    {
        return 0;

    }

    int num1;
    int num2;
};

class AddCalculate:public Calculate
{
    public:
    int getresult()
    {
        return num1 + num2;
    }
};
class SubCalculate : public Calculate
{
public:
    int getresult()
    {
        return num1-num2;
    }
};
class MulCalculate : public Calculate
{
public:
    int getresult()
    {
        return num1 * num2;
    }
};

void test()
{
    Calculate *abc = new AddCalculate;
    abc->num1 = 10;
    abc->num2 = 100;
    cout << abc->num1 << "+" << abc->num2 <<"="<< abc->getresult() << endl;
    delete abc;

    abc = new MulCalculate;
    abc->num1 = 10;
    abc->num2 = 100;
    cout << abc->num1 << "*" << abc->num2 << "=" << abc->getresult() << endl;
    delete abc;
}
int main()
{
    test();
    system("pause");
    return 0;
}