//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
const int QUEUE_INIT_SIZE = 20;

/**
 * @brief Queue defined using array as ring
 */
template <class T>
class Queue
{
private:
    T* data;
    int start;
    int end;
    int dataSize;

    /**
     * @brief used to allocate a larger backing array when storage fills
     */
    void grow();

public:
    /**
     * @brief Construct empty stack
     */
    Queue();

    /**
     * @brief Copy constructor
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue(const Queue<T>& other);

    /**
     * @brief Assignment Operator
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue<T>& operator=(const Queue<T>& other);

    /**
     * @brief Destructor
     */
    ~Queue();

    /**
     * @brief Check if queue is empty
     * @return true if nothing in the queue, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief add item to back of queue
     * @param value Item to add
     */
    void enqueue(const T& item);

    /**
     * @brief Remove and return front item from queue
     * @return Item that was at the front of the queue
     * Can throw exception/blow up with assertion if currently empty
     */
    T dequeue();

    /**
     * @brief Return a copy of the front item
     * @return Item that is at the front of the queue
     */
    T front() const;


    /**
     * @brief Return true if queue is full
     * @return Item that is at the front of the queue
     */
    bool full () const;

    void print( int n) const;

    int getStart() const;

    int getDataSize() const;


};

//--------------------------------------------------------------------
// Queue Implementations
//--------------------------------------------------------------------


template <class T>
Queue<T>::Queue() {
    dataSize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    data = new T[dataSize];
}

template <class T>
Queue<T>::~Queue() {
    delete [] data;
}


template <class T>
void Queue<T>::grow() {
end = dataSize-1;
    dataSize = dataSize * 2;
T* tempArray = new T[dataSize];

if(!isEmpty()){
    int curLoc = 0;
    while(curLoc!=end-1){

        if(start==end+1){start = 0;}
        tempArray[curLoc] = data[start];


        curLoc++;
        start++;

    }

}

delete [] data;

data = tempArray;

start = 0;

}


template <class T>
void Queue<T>::enqueue(const T& value) {
    if( full() ) {
        grow();
    }

         //insert at back
if(end==dataSize){ end = 0;}
       data[end] = value;
       end++;


}


template <class T>
T Queue<T>::dequeue() {

    if(isEmpty()){
        std::cout << "empty queue ";
        exit(-1);
    }
else{
    T temp = data[start];
    start++;
    return temp;
}

}



template <class T>
bool Queue<T>::full () const {

      return (end+1)%dataSize == start ? true : false;
}

template <class T>
bool Queue<T>::isEmpty() const {
    return start == end;
}


template <class T>
T Queue<T>::front() const {

    if(isEmpty()){


        std::cout << "empty queue";
                exit(-1);
    }
    else{
            T res = data[start];
    return  res;
    }

}

template<class T>
void Queue<T>::print(int n) const {



   if(n >= end) {
       return;
   }

       else{
   std::cout << data[n];
   n++;
   print(n);
   }



}

template<class T>
int Queue<T>::getStart() const {
    return start;
}

template<class T>
int Queue<T>::getDataSize() const {
    return dataSize;
}

#endif // STACK_H
