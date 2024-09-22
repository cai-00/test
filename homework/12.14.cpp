#include <iostream>
#include<vector>
using namespace std;
class Account
{
public:
    Account()
    {
    }
    Account(double a)
    {
        if (a >= 0)
            m_a = a;
        else
        {
            m_a = 0;
            cout << "初始值无效" << endl;
        }
    }
    virtual double calculateInterest() 
    {
        return 0;
    }
    virtual void debit_fee(double c)
    {

    }
    virtual void credit_fee(double b)
    {

    }

    bool credit(double b) // 存入
    {
        m_a += b;
        return true;
    }

    bool debit(double c)//取出
    {
        if (c >= 0 && c <= m_a)
        {
            m_a -= c;
            return true;
        }

        else
            return false;
    }

    double getBalance()
    {
        return m_a;
    }

    virtual bool judge()
    {
        return 0;
    }

    double m_a;//存款
};

class SavingsAccount : virtual public Account
{
public:
    SavingsAccount(double a, double b)
    {
        m_a = a;
        m_b = b;
    }

    double calculateInterest()
    {
        return m_a * m_b;
    }

    bool judge()
    {
        return true;
    }

    double m_b;//利率
};
class CheckingAccount : virtual public Account
{
public:
    CheckingAccount(double a, double c)
    {
        m_a = a;
        m_c = c;
    }
    void credit_fee(double b)
    {
        Account A1;
        if (A1.Account::credit(b))
        {
            m_a -= m_c;
        }
    }

    void debit_fee(double c)
    {
        Account A1;
        if (A1.Account::debit(c))
        {

            m_a -= m_c;
        }
    }
    bool judge()
    {
        return false;
    }

    double m_c;//手续费
};

int main()
{
    vector<Account *> account;

    SavingsAccount s1(1000,0.1);
    CheckingAccount c1(1000,1);
    account.push_back(&s1);
    account.push_back(&c1);

    for (vector<Account *>::iterator it = account.begin(); it != account.end();it++)
    {
         (*it)->credit(100);
         (*it)->debit(10);
        if((*it)->judge())
        {
            (*it)->credit((*it)->calculateInterest());
            cout << (*it)->getBalance() << endl;
        }
        else if (!(*it)->judge())
        {
            (*it)->credit(1000);
            (*it)->credit_fee(1000);
            cout << (*it)->getBalance() << endl;
        }
        
    }

        system("pause");

    return 0;
}