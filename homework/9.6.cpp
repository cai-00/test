#include<iostream>
using namespace std;

class Complex
{
public:
    Complex(double a, double b)
        {
            realPart = a;
            imaginaryPart = b;
        }
    Complex &addrealPart(Complex &c1)
    {
        this->realPart+= c1.realPart ;
        return *this;
        
    }
    Complex &addimaginaryPart(Complex &c1)
    {
        this->imaginaryPart += c1.imaginaryPart;
        return *this;
    
    }
        double realPart;
        double imaginaryPart;
};

int main()
{
     
    Complex com1(1,2);
    Complex com2(2,1);

    
    com2.addrealPart(com1);
    com2.addimaginaryPart(com1);
    cout << com2.realPart << "+" << com2.imaginaryPart << "i"<<endl;

    system("pause");

    return 0;
}