#include<iostream>
#include<time.h>
using namespace std;



template <typename T>
class MyArray
{
    T* arr;
    int Count;
    int size;
    int capacity;
    int grow;
    int sRound(int _size, int _grow);
public:
    MyArray();
    MyArray(int);
    MyArray(const MyArray&);
    ~MyArray();
    void Getsize();
    void SetSize(int size, int grow);
    void GetUpperBound();
    bool IsEmpty();
    void FreeExtra();
    void RemoveAll();
    void GetAt(int ob);
    void SetAt(int i, T obj);
    MyArray& operator[](const MyArray& obj);
    void Add(T obj);
    void Append(const MyArray& obj);
    MyArray& operator=(const MyArray& obj);
    void GetData();
    void InsertAt(int i, T obj);
    void RemoveAt(int i);


};
template <typename T>
MyArray<T>::MyArray()
{
    Count = 0;
    arr = NULL;
    size = 0;
}
template <typename T>
MyArray<T>::MyArray(int n)
{
    T* temp;
    temp->arr = new int[n];
    temp->size = n;
    for (int i = 0; i < n; i++)
        temp->arr[i] = rand() % 20;
    Count = 0;
    arr = NULL;
    size = 0;
}
template <typename T>
MyArray<T>::MyArray(const MyArray& N)
{
    T* temp = N.arr;
    while (temp != 0) {
        AddHvost(temp->arr);
        temp = temp->next;

    }
}

template<typename T>
MyArray<T>::~MyArray()
{
    delete[]arr;
    size = 0;
    capacity = 0;
}

template<typename T>
void MyArray<T>::Getsize()
{
    int size = strlen(arr);
}

template<typename T>
void MyArray<T>::SetSize(int s_size, int grow)
{
    grow = 1;
    int gsize = strlen(arr);
    if (s_size + grow > gsize())
        size = s_size + grow;
    else
        size = s_size;
}

template<typename T>
void MyArray<T>::GetUpperBound()
{
    return capacity - 1;
}

template<typename T>
bool MyArray<T>::IsEmpty()
{
    return capacity == 0 ? true : false;
}

template<typename T>
void MyArray<T>::FreeExtra()
{
    if (!IsEmpty())
    {
        T* temp = new T[capacity];
        for (int i = 0; i < capacity; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;

        size = capacity;
    }
}

template<typename T>
void MyArray<T>::RemoveAll()
{
    capacity = 0;
}

template<typename T>
void MyArray<T>::GetAt(int ob)
{
    return arr[ob];
}

template<typename T>
void MyArray<T>::SetAt(int i, T obj)
{
    arr[i] = obj;
}
template<typename T>
void MyArray<T>::GetData()
{
    return arr;
}
template<typename T>
void MyArray<T>::InsertAt(int i, T obj)
{
    if (i >= 0 && i <= capacity)
    {
        if (capacity >= size) size += grow;
        T* temp = new T[size];
        for (int k = 0; k < i; k++)
            temp[k] = arr[k];
        temp[i] = obj;
        for (int k = i; k < capacity; k++)
            temp[k + 1] = arr[k];
        capacity++;
        delete[]arr;
        arr = temp;
    }
}
template<typename T>
void MyArray<T>::RemoveAt(int i)
{
    if (i >= 0 && i < capacity)
    {
        for (int k = i; k < capacity - 1; k++)
            arr[k] = arr[k + 1];
        capacity--;
    }
}


template<typename T>
void MyArray<T>::Add(T obj)
{
    if (capacity >= size)
    {
        size += grow;
        T* temp = new T[size];
        for (int i = 0; i < capacity; i++)
            temp[i] = arr[i];
        delete[]arr;
        arr = temp;
    }

    arr[capacity++] = obj;
}

template<typename T>
void MyArray<T>::Append(const MyArray& obj)
{
    size = sRound(size + obj.size, grow);
    T* temp = new T[size];
    for (int i = 0; i < capacity; i++)
        temp[i] = arr[i];
    for (int i = 0; i < obj.capacity; i++)
        temp[i + capacity] = obj.arr[i];
    delete[] arr;
    arr = temp;
    capacity += obj.capacity;
}



int main() {



}