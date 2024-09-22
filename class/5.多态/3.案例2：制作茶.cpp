#include <iostream>
using namespace std;
class MakeDrink
{
    public:
        virtual void boil() = 0;
        virtual void pourtea() = 0;
        virtual void pourwater() = 0;

        virtual void Makedrink()
        {
            boil();
            pourtea();
            pourwater();
        }
};

class MakeTea:public MakeDrink
{
public:
    virtual void boil()
    {
        cout << "boilwater" << endl;
    }
    virtual void pourtea() 
    {
        cout << "pourtea" << endl;
    }
    virtual void pourwater() 
    {
        cout << "pourwater" << endl;
    }
};

void makedrink(MakeDrink*drink)
{
    drink->Makedrink();
    delete drink;
}

void test()
{
    makedrink(new MakeTea);

}

    int main()
    {
        test();
        system("pause");
        return 0;
    }