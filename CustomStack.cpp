#include<iostream>
#include<stack>
template <typename T> 
class CustomStack
{
private:
    uint32_t mSize;
    T mData;
    CustomStack* mPtr;
public:

    CustomStack();
    
    ~CustomStack();
    
    void setData(const T& mData);
    
    void setNext(CustomStack* const mPtr);
    
    T getData();
    
    CustomStack<T>* getNext();
    
    uint32_t size(void);
    
    bool empty();

    CustomStack<T>* newData(T mData);

    void push(T mData);

    void pop();
    
    T peek();
};

template <typename T>
CustomStack<T>::CustomStack():mSize(0), mData(-1), mPtr(NULL){}

template <typename T>
CustomStack<T>::~CustomStack()
{
    CustomStack* temp;
    temp = mPtr;
    while (temp != NULL)
    {
        mPtr->setNext(mPtr);
        delete temp;
        temp = mPtr;
    }
    mPtr = temp = NULL;
    mSize = 0;
}

template <typename T>
void CustomStack<T>::setData(const T& mData)
{
    this->mData = mData;
}

template <typename T>
void CustomStack<T>::setNext(CustomStack* const mPtr)
{
    this->mPtr = mPtr;
}

template <typename T>
T CustomStack<T>::getData()
{
    return mData;
}

template <typename T>
CustomStack<T>* CustomStack<T>::getNext()
{
    return mPtr;
}

template <typename T>
uint32_t CustomStack<T>::size(void)
{
    return mSize;
}

template <typename T>
bool CustomStack<T>::empty()
{
    return !mSize;
}

template <typename T>
void CustomStack<T>::push(T mData)
{
    CustomStack<T>* stackNode = new CustomStack();
    stackNode->setData(mData);
    stackNode->setNext(NULL);
    mPtr = stackNode;
    mSize++;
    std::cout<<mPtr->getData()<<std::endl;
}

template <typename T>
void CustomStack<T>::pop()
{
    // mSize--;
    if(empty())
    {
        std::cerr<<"No thing to remove"<<std::endl;
    }
    else
    {
        CustomStack<T>* temp = mPtr;
        mPtr = mPtr->getNext();
        temp = mPtr;
        delete temp;
        mSize--;
    }
}

template <typename T> 
T CustomStack<T>::peek()
{
    // for(uint32_t aIndex = 0; aIndex < mSize-1; aIndex++)
    // {

    //     mPtr = mPtr->getNext();
    // }
    return mPtr->getData();
}

int main(int argc, char** argv)
{
    CustomStack<int> stackOne;
    
    stackOne.push(100);
    stackOne.push(101);
    stackOne.push(102);
    stackOne.push(103);
    // std::cout<<"Size of stack: "<<stackOne.size()<<std::endl;
    
    // stackOne.pop();
    std::cout<<"peak: "<<stackOne.peek()<<std::endl;
    // std::cout<<"Size of stack: "<<stackOne.size()<<std::endl;
    // std::cout<<stackOne.empty()<<std::endl;
    return 0;
}