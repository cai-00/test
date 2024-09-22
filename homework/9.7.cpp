#include <iostream>
using namespace std;

class Rational
{
public:
    Rational()
    {
        numerator = 0;
        denominator = 0;
    }

    Rational(int a, int b)
    {
        numerator = a;
        denominator = b;
    }

    void a(Rational &r1, Rational &r2)
    {

        this->numerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
        this->denominator = r1.denominator * r2.denominator;
    }
    void b(Rational &r1, Rational &r2)
    {

        this->numerator = r1.numerator * r2.denominator - r1.denominator * r2.numerator;
        this->denominator = r1.denominator * r2.denominator;
    }
    void c(Rational &r1, Rational &r2)
    {

        this->numerator = r1.numerator * r2.numerator;
        this->denominator = r1.denominator * r2.denominator;
    }
    void d(Rational &r1, Rational &r2)
    {

        this->numerator = r1.numerator * r2.denominator;
        this->denominator = r1.denominator * r2.numerator;
    }
    void ans()
    {
        for (int i = 2; i < 10; i++)
        {
            if (denominator % i == 0 && numerator % i == 0)
            {
                denominator /= i;
                numerator /= i;
            }
        }
    }
    int getnumerator()
    {
        return numerator;
    }
    int getdenominator()
    {
        return denominator;
    }
    void e()
    {
        cout << numerator << "/" << denominator << endl;
    }

    double f()
    {
        return numerator / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main()
{
    int x, y, w, v;
    cin >> x >> y >> w >> v;
    Rational r1(x, y);
    Rational r2(w, v);

    Rational r3;

    r3.c(r1, r2);
    r3.ans();
    r3.e();
    cout << r3.getnumerator() << "/" << r3.getdenominator() << endl;

    cout << r3.f();

    return 0;
}