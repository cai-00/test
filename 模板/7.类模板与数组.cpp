#include <iostream>
using namespace std;

template<class T>
class MyArray
{
    public:
    //有参构造
    MyArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity]; 
    }
    //拷贝构造
    MyArray(const MyArray&arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

         //深拷贝
        this->pAddress = new T[arr.m_capacity];

        for (int i = 0; i < this->m_size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    //operator=防止浅拷贝
    MyArray& operator=(const MyArray&arr)
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        // 深拷贝
        this->pAddress = new T[arr.m_capacity];

        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法
    void Push_Back(const T&val)
    {
        //判断是否已满
        if(this->m_capacity==this->m_size)
        {
            return;
        }
        this->pAddress[this->m_size] = val;
        this->m_size++; 
    }
    //尾删法
    void Pop_Back()
    {
        if(this->m_size==0)
        {
            return;
        }
        this->m_size--;//逻辑删除
    }

    //通过下标访问数据,重载[]
    T* operator[](int index)
    {
        return this->pAddress[index];
    }
    //返回数组大小，容量
    int getCapacity()
    {
        return this->m_capacity;
    }
    int getSize()
    {
        return this->m_size;
    }

    ~MyArray()
    {
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    private:
        T *pAddress;
        int m_capacity;//容量
        int m_size;//大小
};

int main()
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;

    MyArray<int> arr(5);
    for (int i = 0; i < 5;i++)
    {
        arr.Push_Back(i);
    }
    
    system("pause");
    return 0;
}