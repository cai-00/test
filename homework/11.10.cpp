#include<iostream>
using namespace std;
 class Account
 {

    public:
    Account()
    {

    }
    Account (double a)
    {
        if(a>=0)
            m_a = a;
        else
            {m_a = 0;
                cout << "初始值无效" << endl;}
    }

    bool credit(double b)
    {
        m_a += b;
        return true;
    }

    bool debit(double c)
    {
        if(c>=0&&c<=m_a)
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



    double m_a;
 };

 class SavingsAccount:virtual public Account
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

        double m_b;
 };
 class CheckingAccount :virtual public Account
 {
    public:
    CheckingAccount (double a,double c)
    {
        m_a = a;
        m_c = c;
    }
        void credit( double b)
        {
            Account A1;
            if (A1.Account::credit(b))
            {
                
                m_a -= m_c;
            }
        }

    void debit(double c)
    {
    
        Account A1;
        if(A1.Account::debit(c))
        {
            
            m_a -= m_c;
        }

    }

        double m_c;
 };

 int main()
 {
     Account a1(1000);
     a1.credit(100);
     a1.debit(200);
     cout << a1.getBalance() << endl;

     SavingsAccount s1(a1.getBalance(), 0.1);
     a1.credit(s1.calculateInterest());
     cout << a1.getBalance() << endl;

     CheckingAccount c1(a1.getBalance(), 1);
     c1.credit( 100);
      c1.debit( 200);
     cout << c1.getBalance() << endl;

     system("pause");

     return 0;
  }