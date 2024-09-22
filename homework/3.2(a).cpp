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
        Node *prev;

        Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
            : data{d}, prev{p}, next{n} {}
    };

    List()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    void insert(const Object &m)
    {
        Node *p = new Node(m);
        p->next = head->next;
        p->prev = p->next->prev;
        head->next->prev = p;
        head->next = p;

        theSize++;
    }

    void GetData()
    {            
        Node *m = head;
        while (m)
        {
            cout << m->data << endl;

            m = m->next;
        }
    }
    //交换元素p和p下一个元素
    void Swap(Node*p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = p->next;
        p->next = p->next->next;
        p->next->prev = p;
        p->prev->next = p;
    }


    int theSize;
    Node *head;
    Node *tail;
};

int main()
{
    List<int> L;

    L.insert(2);

    L.insert(1);

    L.GetData();

    L.Swap(L.head->next);

    L.GetData();

    return 0;
}