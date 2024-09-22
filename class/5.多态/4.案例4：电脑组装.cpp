#include <iostream>
using namespace std;

class CPU
{
    public:
        virtual void calculate() = 0;
};
class VC
{
public:
    virtual void display() = 0;
};
class Memory
{
public:
    virtual void storage() = 0;
};

class Computer
{
    public:
    Computer(CPU*cpu,VC*vc,Memory*mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work()
    {
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    ~Computer()
    {
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

    private:
        CPU *m_cpu;
        VC *m_vc;
        Memory *m_mem;
};

class IntelCPU:public CPU
{
    void calculate()
    {
        cout << "intelcpu" << endl;
    }
};
class IntelVC : public VC
{
    void display()
    {
        cout << "intelvc" << endl;
    }
};
class IntelMemory : public Memory
{
    void storage()
    {
        cout << "intelmemory" << endl;
    }
};
void test()
{
    CPU *intelcpu = new IntelCPU;
    VC *intelvc = new IntelVC;
    Memory *intelmem = new IntelMemory;

    Computer *computer1 = new Computer(intelcpu, intelvc, intelmem);
    computer1->work();
    delete computer1;

    Computer *computer2 = new Computer(new IntelCPU, new IntelVC, new IntelMemory);
    computer2->work();
    delete computer2;
}
int main()
{
    test();
    system("pause");
    return 0;
}