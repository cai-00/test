#include <iostream>
using namespace std;
class point
{
public:
    void setx(int x)
    {
        m_x = x;
    }
    int getx()
    {
        return m_x;
    }

    void sety(int y)
    {
        m_y = y;
    }
    int gety()
    {
        return m_y;
    }

private:
    int m_x;
    int m_y;
};

class circle
{
public:
    void setr(int r)
    {
        m_r = r;
    }

    int getr()
    {
        return m_r;
    }

    void setcenter(point center)
    {
        m_center = center;
    }

    point getcenter()
    {
        return m_center;
    }

private:
    int m_r;

    point m_center; // 圆心    一个类可以作为另一个类的成员
};

void distance(circle &c, point &p)
{
    int dis = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
              (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());

    int rdis = c.getr() * c.getr();

    if (dis == rdis)
    {
        cout << "点在圆上" << endl;
    }
}

int main()
{
    circle c;
    c.setr(10);
    
    point center;
    center.setx(10);
    center.sety(0);
    c.setcenter(center);

    point p;
    p.setx(10);
    p.sety(10);

    distance(c, p);

    system("pause");

    return 0;
}
