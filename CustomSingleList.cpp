#include<iostream>
#include<exception>
#include<stack>
#include<queue>
//Only use one class ?

template <typename T>
class Node 
{
private:
    T data;
    Node* next;
public:
    // Default constructor
    Node();
  
    // Parameterised Constructor
    Node(const T& data);

    void setData(const T& data);

    void setNext(Node* const next);

    T getData() const;

    Node<T>* getNext() const;
};
//Using only head for singly linked list
template <typename T>
class Linkedlist 
{
private:
    uint32_t mSize;
    
    //The first node
    Node<T>* head;

    // Linkedlist<T>* begin;
    // T value;

    //The last node
    Node<T>* tail;

    //The current node
    Node<T>* current;

public:
    // Default constructor
    Linkedlist();

    //Destructor
    ~Linkedlist();

    //Check empty list
    bool empty();

    //Size of Linked List
    uint32_t size(void);

    //Insert at the beginning 
    void push_front(const T& data);

    //Insert at the end
    void push_back(const T& data);

    //Insert after the choosen Node
    void insertAfter(uint32_t aIndex, const T& data);

    //Insert before the choosen Node
    void insertBefore(uint32_t aIndex, const T& data);

    //Delete the first Node
    void pop_front();

    //Delete the final Node
    void pop_back();

    //Delete the choosen Node
    void deleteNote(uint32_t aIndex);

    //Go to the beginning
    void begin();
        
    //Go to index
    void goTo(uint32_t aIndex);
        
    //Go to the end
    void end();
};

template <typename T>
Node<T>::Node():data(0),next(NULL){}
// {
//     next = NULL;
// }

template <typename T>
Node<T>::Node(const T& data)
{
    this->data = data;
    next = NULL;
}

template <typename T>
void Node<T>::setData(const T& data)
{
    this->data = data;
}

template <typename T>
void Node<T>::setNext(Node* const next)
{
    this->next = next;
}

template <typename T>
T Node<T>::getData() const
{
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return next;
}

template <typename T>
Linkedlist<T>::Linkedlist()
{
    mSize = 0;
    head = current = tail = NULL;
}

template <typename T>
Linkedlist<T>::~Linkedlist()
{
    current = head;
    while(current != NULL)
    {
        head->setNext(head);
        delete current;
        current = head;
    }
    head = current = tail = NULL;
}

template <typename T>
bool Linkedlist<T>::empty()
{
    return (head == NULL);
}

template <typename T>
uint32_t Linkedlist<T>::size(void)
{
    return mSize;
}

template <typename T>
void Linkedlist<T>::push_front(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    mSize++;
    if(empty())
    {
        newNode->setNext(NULL);
        head = current = tail = newNode;
    }
    else
    {
        //newNode(6) head(7)
        newNode->setNext(head);
        head = newNode;
    }
}

//at the end
template <typename T>
void Linkedlist<T>::push_back(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    mSize++;
    if(empty())
    {
        newNode->setNext(NULL);
        head = tail = newNode;
    }
    else
    {
        newNode->setNext(NULL);
        // 6 (tail) -> 7 (new node)
            // tail ( data, NULL)
            // newNode( new data, NULL)
        tail->setNext(newNode);
        //Old tail point to newNode
        tail = newNode;
        //newNode be new tail
    }
}

template <typename T>
void Linkedlist<T>::insertAfter(uint32_t aIndex, const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    goTo(aIndex);
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    current = newNode;
}

template <typename T>
void Linkedlist<T>::insertBefore(uint32_t aIndex, const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    goTo(aIndex);
    newNode->setNext(current);
    current = newNode;
}

template <typename T>
void Linkedlist<T>::begin()
{
    current = head;
}

template <typename T>
void Linkedlist<T>::end()
{
    current = tail;
}

template <typename T>
void Linkedlist<T>::goTo(uint32_t aIndex)
{    
    try
    {
        if(aIndex < mSize)
        {
            begin();
            for(uint32_t index = 0; index < (aIndex + 1); index ++)
            {
                if(!index)
                {
                    continue;
                }
                else
                {
                    current = current->getNext();
                }
            }
        }
        else
        {
            throw (aIndex);
        }
    } 
    catch(uint32_t aIndex)
    {
        std::cerr<<"Error: goTo("<<aIndex<<") -> out of index "<<std::endl;
    }
}

template <typename T>
void Linkedlist<T>::pop_front()
{
    std::cout<<head->getData()<<std::endl;
    mSize--;
    begin();
    head = head->getNext();
    delete current;
    std::cout<<head->getData()<<std::endl;
}

template <typename T>
void Linkedlist<T>::pop_back()
{
    std::cout<<tail->getData()<<std::endl;
    mSize--;
    //Go to previous tail
    goTo(mSize-1);
    current->setNext(NULL);
    delete tail;
    tail = current;
    std::cout<<tail->getData()<<std::endl;
}

template <typename T>
void Linkedlist<T>::deleteNote(uint32_t aIndex)
{
    //Will do later
}

int main(int argc, char** argv)
{
    Linkedlist<uint32_t> a;
    a.push_front(10);
    a.push_front(9);
    a.push_back(12);
    a.push_back(13);
    // a.insertAfter(2, 11);
    // a.pop_front();
    a.pop_back();
    // std::cout<<a.size()<<std::endl;
    // a.goTo(10);
    // std::cout<<a.size()<<std::endl;
    return 0;
}