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

    List And(List&ls)
    {
        List <Object>result;
        Node *p1 = ls.head;
        Node *p2 = this->head;

        while(p1!=nullptr&&p2!=nullptr)
        {
            if(p1->data<p2->data)
            {
                p1 = p1->next;
            }
            else if(p1->data>p2->data)
            {
                p2 = p2->next;
            }
            else{
                result.insert(p1->data);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return result;
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
    

    int theSize;
    Node *head;
};

int main()
{
    List<int> L;

    L.insert(1);
    L.insert(2);
    L.insert(4);

    List<int> L1;

    L1.insert(1);
    L1.insert(3);
    L1.insert(5);

    List<int> L2= L.And(L1);

    L.GetData();
    cout << endl;
    L1.GetData();
    cout << endl;
    L2.GetData();

    return 0;
}