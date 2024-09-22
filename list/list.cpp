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
            : data{d}, prev{p},  next{n} {}
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
    void Delete(int m)
    {
        Node *n = head;
        for (int i = 0; i < m; i++)
            n = n->next;

        n->next->prev = n->prev;
        n->prev->next = n->next;

        delete n;
        theSize--;
    }

    ~List()
    {
        for (int i = 1; i <= theSize; i++)
            Delete(i);

        delete head;
        delete tail;
    }

private:
    int theSize;
    Node *head;
    Node *tail;
};
void test01()
{
    List<int> L;

    L.insert(2);

    // L.Delete(1);

    L.GetData();
}
int main()
{

    test01();

    return 0;
}