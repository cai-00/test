#include <iostream>
using namespace std;

// 求两个长方体长方体的体积和面积是否相等
class cube
{

public:
    void setL(int a)
    {
        m_l = a;
    }
    int getL()
    {
        return m_l;
    }

    void setW(int b)
    {
        m_w = b;
    }
    int getW()
    {
        return m_w;
    }

    void setH(int c)
    {
        m_h = c;
    }
    int getH()
    {
        return m_h;
    }

    int s()
    {
        return 2 * m_l * m_w + 2 * m_l * m_h + 2 * m_h * m_w;
    }
    int v()
    {
        return m_l * m_w * m_h;
    }

    //类内判断
    bool same1(cube &c)
    {

        if (m_l == c.getL() && m_w == c.getW() && m_h == c.getH())
        {
            return true;
        }

        else
        {
            return false;
        }
    }

private:
    int m_l;
    int m_w;
    int m_h;
};

//类外判断
bool same(cube &c1, cube &c2)

{
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{
    cube c1;

    c1.setL(10);
    c1.setW(11);
    c1.setH(10);

    cube c2;

    c2.setL(10);
    c2.setW(11);
    c2.setH(10);

    cout << c1.s() << endl;
    cout << c1.v() << endl;

    bool ret = same(c1, c2);

    cout << ret << endl;

    bool ret1 = c1.same1(c2);

    cout << ret1 << endl;
}
