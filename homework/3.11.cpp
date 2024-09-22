#include <iostream>
using namespace std;
template <typename Object>
class List
{

public:
    struct Node
    {
        int data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {}
    };

    List()
    {
        theSize = 0;
        head = new Node;
    }

    void insert(const Object &m)
    {
        Node *p = new Node(m);
        p->next = head;
        head = p;

        theSize++;
    }

    int GetSize()
    {
        return theSize;
    }

    void PrintList()
    {
        Node *m = head;
        while (m)
        {
            cout << m->data << endl;

            m = m->next;
        }
    }
    
    bool contain(const Object&x)
    {
        Node *m = head;
        while (m)
        {
            if(m->data==x)
                return true;
            else
                m = m->next;
        }

        return false;
    }

    void Add(const Object&x)
    {
        if(!contain(x))
        {
            insert(x);
        }
    }

    void Delete(const Object&x)
    {
        if(contain(x))
        {
            if(head->data==x)
            {
                head = head->next;
            }
            else
            {
                Node *m = head;
                while (m->next)
                {
                    if (m->next->data == x)
                        m->next = m->next->next;

                    m = m->next;
                }
            }
        
        }
    }

    int theSize;
    Node *head;
};

int main()
{
    List<int> L;

    L.insert(2);

    L.insert(1);

    cout<<L.contain(1)<<endl;

    L.Add(3);

    L.Delete(2);

    L.PrintList();

    return 0;
}