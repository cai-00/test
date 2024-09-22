#include<iostream>
using namespace std;
class Polynomial
{
    friend Polynomial operator+(Polynomial &p1, Polynomial &p2);
    friend Polynomial operator-(Polynomial &p1, Polynomial &p2);
    friend Polynomial operator*(Polynomial &p1, Polynomial &p2);

public:
    Polynomial()
    {
        for(int i=0;i<5;i++)
        {
            x[i] = {0};
    
        }
    }
    void set(int*a)
    {
        for (int i = 0; i <5;i++)
        {
            x[i] = a[i];
            
        }
    }
    void get()
    {
        for (int i = 0; i < 5;i++)
        {
            cout << x[i] << "\t";
        }
        cout << endl;

    }
    Polynomial &operator=(const Polynomial&p)
    {
        for (int i = 0; i < 5;i++)
        {
            this->x[i] = p.x[i];
        }
        return *this;
    }
    Polynomial operator+=( Polynomial &p)
    {
        for (int i = 0; i < 5; i++)
        {
            this->x[i]+= p.x[i];
        }
        return *this;
    }

    Polynomial operator-=(Polynomial &p)
    {
        for (int i = 0; i < 5; i++)
        {
            this->x[i] -= p.x[i];
        }
        return *this;
    }
    Polynomial operator*=(Polynomial &p)
    {
        Polynomial temp;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                temp.x[i + j] += this->x[i] * p.x[j];
            }
        }

        return temp;
    }

    ~Polynomial()
    {
        
    }

    private:
        int x[10];
        
};

Polynomial operator+(Polynomial&p1,Polynomial&p2)
{
    Polynomial p3;
    for (int i=0;i<5;i++)
    {
        p3.x[i] = p1.x[i] + p2.x[i];
    }
    return p3;
}
Polynomial operator-(Polynomial &p1, Polynomial &p2)
{
    Polynomial p3;
    for (int i = 0; i < 5; i++)
    {
        p3.x[i] = p1.x[i] - p2.x[i];
    }
    return p3;
}
Polynomial operator*(Polynomial &p1, Polynomial &p2)
{
    Polynomial p3;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10;j++)
        {
            p3.x[i+j] += p1.x[i] * p2.x[j];
            
        }
    }
    return p3;
}

int main()
{
    int a[5] = {0, 2, 0, 0, 0};
    int b[5] = {0, 4, 5, 0, 0};

    Polynomial p1;
    p1.set(a);
    p1.get();

    Polynomial p2;
    p2.set( b);

    Polynomial p3;

    p3 = p1 + p2;
    p3.get();

    Polynomial p4;
    p4 = p1 - p2;
    p4.get();

    Polynomial p5;
    p5 = p1 * p2;
    p5.get();

    (p2 *= p1).get();


    system("pause");

    return 0;
}