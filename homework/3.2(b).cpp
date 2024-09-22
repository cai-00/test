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
    }

    void insert(const Object &m)
    {
        Node *p = new Node(m);
        p->next = head;
        head = p;

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
    //交换节点p后面两个元素
    void Swap(Node *p)
    {
        Node *n1 = p->next;
        Node *n2 = p->next->next;
        p->next = n2;
        n1->next = n2->next;
        n2->next = n1;
    }

    int theSize;
    Node *head;
};

int main()
{
    List<int> L;

    L.insert(2);

    L.insert(1);

    L.Swap(L.head);

    L.GetData();


    return 0;
}