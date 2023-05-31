#include<iostream>

template <typename T> class CustomArray
{
    private:
        uint32_t mSize;
        uint32_t mCapacity;
        T* mPtr;
    public:
        //Default constructor
        CustomArray(uint32_t aSize = 0, const T& aVal = 0);
        
        //Copy constructor
        CustomArray( const CustomArray& aSource );


        //Overload assignment operator
        CustomArray& operator=(const CustomArray& aSource);

        //
        uint32_t size(void);

        uint32_t capacity(void);

        void resize(uint32_t aNewSize);

        bool empty(void);

        void reserve(uint32_t aNewCapacity);

        void shrink_to_fit(void);

        T& operator[](uint32_t aIndex);

        T& at(uint32_t aIndex);

        T& front();

        T& back();

        T* data(void);

        void push_back(const T& aElement);

        void pop_back(void);

        void insert(uint32_t aIndex, const T& aElement);

        void insert(uint32_t aIndex, const CustomArray<T> &aAddArray);

        void erase(uint32_t aBeginIndex, uint32_t aEndIndex);

        void swap(CustomArray &aAnotherVector);

        void clear();
};

//Constructor : PASS
template <typename T>
CustomArray<T> :: CustomArray(uint32_t aSize, const T& aVal)
{
    mSize = aSize;

    //Correct capacity
    mCapacity = aSize * 2;
    mPtr = new T [mCapacity];
    while(aSize-- > 0)
    {
        mPtr[aSize] = aVal;
    }
}

//Copy constructor
template <typename T>
CustomArray<T> :: CustomArray(const CustomArray &aSource)
{
    mSize       = aSource.mSize;
    mCapacity   = aSource.mCapacity;
    mPtr        = new T [mCapacity];
    for(int index = 0; index < mSize; index++)
    {
        mPtr[index] = aSource.mPtr[index];
    }
}

//Overload assignment operator
template <typename T> 
CustomArray<T>& CustomArray<T> :: operator=(const CustomArray &aSource)
{
    delete [] mPtr;
    mSize       = aSource.mSize;
    mCapacity   = aSource.mCapacity;
    mPtr        = new T [mCapacity];
    for(int index = 0; index < mSize; index++)
    {
        mPtr[index] = aSource.mPtr[index];
    }
    return *this;
}

//Return size of array
template <typename T> 
uint32_t CustomArray<T> :: size(void)
{
    return mSize;
}

//Return capacity of array
template <typename T> 
uint32_t CustomArray<T> :: capacity(void)
{
    return mCapacity;
}

//Resize array
template <typename T> 
void CustomArray<T> :: resize(uint32_t aNewSize)
{
    if(aNewSize > mCapacity)
    {
        T* aPtr = new T [mCapacity*2];
        for(int index = 0; index < mSize; index++)
        {
            aPtr[index] = mPtr[index];
        }
        delete[] mPtr;
        mPtr = aPtr; 
    }
    mSize = aNewSize;
}

//Check empty array
template <typename T> 
bool CustomArray<T>::empty()
{
    return (mSize == 0);
}

//------------------correct resize and reserve
//Reserve the memory allocation for array
// aNewCapacity > mCapacity
template <typename T> 
void CustomArray<T>::reserve(uint32_t aNewCapacity)
{
    if(aNewCapacity<mSize)
    {
        resize(aNewCapacity);
    }
    else
    {
        T* aPtr = new T [aNewCapacity];
        for(int index = 0; index < mSize; index++)
        {
            aPtr[index] = mPtr[index];
        }
        delete[] mPtr;
        mPtr = aPtr; 
    }
}

//Change the capacity equal size
template <typename T> 
void CustomArray<T> :: shrink_to_fit(void)
{
    reserve(mSize);
}

//using exception 
template <typename T> 
T& CustomArray<T>::operator[](uint32_t aIndex)
{
    if(aIndex >= mSize || aIndex < 0)
    {
        std::__throw_out_of_range_fmt("Out of index");
    } 
    return *(mPtr + aIndex);
}

//exception
template <typename T> 
T& CustomArray<T> :: at(uint32_t aIndex)
{
    if(aIndex >= mSize || aIndex < 0)
    {
        std::__throw_out_of_range("Out of index");
    } 
    return *(mPtr + aIndex);
}

template <typename T> 
T& CustomArray<T>::front()
{
    return *mPtr;
}

template <typename T> 
T& CustomArray<T> :: back()

{
    return *mPtr + (mSize - 1);
}

template <typename T> 
T* CustomArray<T>::data(void)
{
    return mPtr;
}

template <typename T> 
void CustomArray<T>::push_back(const T& aElement)
{
    mSize++;
    if(mSize > mCapacity);
    {
        reserve(mSize);
    *mPtr + (mSize - 1) = aElement;
    }
}

template <typename T> 
void CustomArray<T>::pop_back(void)
{
    mSize--;
}

//using exception aIndex > mSize
template <typename T> 
void CustomArray<T>::insert(uint32_t aIndex, const T& aElement)
{
    if(aIndex>mCapacity)
    {
        resize(aIndex + 1);
        reserve(aIndex + 1);
    }
    else
    {
        mSize+=1;
    }
    for(int tIndex = aIndex ; tIndex < mSize ; tIndex ++)
    {
        T temp = mPtr[tIndex];
        mPtr[tIndex+1] = temp;
    }
    mPtr[aIndex] = aElement;
}

template <typename T> 
void CustomArray<T>::insert(uint32_t aIndex, const CustomArray<T> &aAddArray)
{
    if( ( aIndex + aAddArray.mSize ) > mCapacity)
    {
        resize( aIndex + aAddArray.mSize + 1 );
        reserve( aIndex + aAddArray.mSize + 1 );
    }
    else
    {
        mSize+=aAddArray.mSize;
    }
    for(int tIndex = aIndex ; tIndex < mSize ; tIndex ++)
    {
        T temp = mPtr[ tIndex ];
        mPtr[ tIndex + 1 ] = temp;
    }
    for (int nIndex = aIndex; nIndex < mSize; nIndex++)
    {
        mPtr[ nIndex + 1 ] = aAddArray.mPtr[ nIndex - aIndex ];
    }
}

// check erase
template <typename T> 
void CustomArray<T>::erase(uint32_t aBeginIndex, uint32_t aEndIndex)
{
    if( aEndIndex > mSize)
    {
        std::__throw_invalid_argument("Invalid Index");
    }
    else
    {
        for(int tIndex = aEndIndex ; tIndex < mSize ; tIndex ++)
        {
            T temp = mPtr[ tIndex ];
            mPtr[ tIndex + 1 ] = temp;//beginIndex
        }
        resize(mSize - (aEndIndex - aBeginIndex) );
    }  
}

template <typename T> 
void CustomArray<T>::swap(CustomArray &aAnotherVector)
{
    // T* a = aAnotherVector.data();
    T* tArr = mPtr;
    mPtr = aAnotherVector.mPtr;
    aAnotherVector.mPtr = mPtr;
}

template <typename T> 
void CustomArray<T>::clear()
{
    resize(0);
}

int main(int argv, char** argc)
{
    CustomArray<uint32_t> arrTwo(4,7);
    CustomArray<uint32_t> arrOne(5,6);
    // arrOne = arrTwo;
    // arrTwo.resize(10);
    // arrOne.insert(9,arrTwo);
    arrOne.swap(arrTwo);
    // arrOne.clear();
    // arrOne.erase(1,4);
    // for(int index = 0; index<20;index++)
    // {
    //     std::cout<<arrOne[index]<<std::endl;
    // }
    // std::cout<<arrOne.at(6)<<std::endl;
    // arrOne.reserve(16);
    return 0;
}