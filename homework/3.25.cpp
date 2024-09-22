#include <iostream>
using namespace std;
class Stack
{

public:
    struct Node
    {
        int data;
        Node *next;

        Node(const int &d = 0, Node *n = nullptr)
            : data{d}, next{n} {}
    };

    Stack()
    {
        theSize = 0;
        min[0] = 1000000;
    }

    void push(const int &m)
    {
        Node *p = new Node(m);
        p->next = top;
        top = p;

        theSize++;

        if (min[theSize - 1] > m)
            min[theSize] = m;
        else
        {
            min[theSize] = min[theSize - 1];
        }
    }

    void pop()
    {
        top = top->next;
        theSize--;
    }

    void GetData()
    {
        Node *m = top;
        while (m)
        {
            cout << m->data << endl;

            m = m->next;
        }
    }

    int findMin()
    {
        return min[theSize];
    }

    int theSize;
    Node *top;
    int min[100];
};

int main()
{
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);

    s.pop();

    cout << s.findMin() << endl;
    cout << s.top->data << endl;
    cout << s.theSize << endl;

    return 0;
}