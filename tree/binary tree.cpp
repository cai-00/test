#include <iostream>
using namespace std;

template <typename Object>
class BinaryTree
{
public:
    struct BinaryNode
    {
        Object element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Object &theElement, BinaryNode *le, BinaryNode *rt)
            : element{theElement}, left{le}, right{rt} {}
    };

    BinaryNode *root;
    BinaryNode *Min;
    BinaryNode *Max;

    BinaryTree()
    {
        root = new BinaryNode{Object{}, nullptr, nullptr};
    }

    bool contains(const Object &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (x > t->element)
            return (x, t->right);
        else
            return true;
    }

    void insert(const Object &x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (x > t->element)
            insert(x, t->right);
        else
            ;
    }

    /*BinaryNode *findMin(BinaryNode *t) const
    {

        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }
    */
};

int main()
{
    BinaryTree<int> b;

    b.insert(1, b.root);

    //b.Min = b.findMin(b.root);

    cout << b.Min->element;

    //b.Max = b.findMax(b.root);

    cout << b.Max->element;
}