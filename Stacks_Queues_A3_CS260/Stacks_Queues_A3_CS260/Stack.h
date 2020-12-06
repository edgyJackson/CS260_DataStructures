//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef STACK_H
#define STACK_H

#include <iostream>


//Turn loops off for the duration of this file. 

//You are to use recursion for any repetition.
//Make sure to do any other includes before these defines.
#define for DONOTUSETHIS
#define while DONOTUSETHIS
#define goto DONOTUSETHIS

/**
 * @brief List node for AddressLinkedList
 */
template <class T>
struct StackNode
{
    T data;
    StackNode* next;

    StackNode();
    StackNode(const T& value);


    /**
     * @brief operator = set this stacknode equal to other
     * @param other
     * @return
     */
    StackNode<T>& operator=(const StackNode<T>& other);
};


/**
 * @brief Stack based on a linked list
 */
template <class T>
class Stack
{
private:
    StackNode<T>* top;

public:
    /**
     * @brief Construct empty stack
     */
    Stack();

    /**
     * @brief Copy constructor
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Stack(const Stack<T>& other);

    /**
     * @brief Assignment Operator
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Stack<T>& operator=(const Stack<T>& other);

    /**
     * @brief Destructor
     */
    ~Stack();

    /**
     * @brief Check if stack is empty
     * @return true if nothing in stack, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Add item to stack
     * @param value Item to push a copy of onto the stack
     */
    void push(const T& item);

    /**
     * @brief Remove and return top item from stack
     * @return Item that was at the top of the stack
     * Can throw exception/blow up with assertion if currently empty
     */
    T pop();

    /**
     * @brief Return a copy of the top item on the stack (without removing it)
     * @return Item that is at the top of the stack
     */
    T peek() const;


    /**
     * @brief Output the stack in order to cout
     */
    void print() const;
	 
    /**
     * @brief Output the stack in reverse order to cout
     */
    void reversePrint() const;

 void deleteList(StackNode<T>* current);
};


//--------------------------------------------------------------------
// StackNode implementations
//--------------------------------------------------------------------

template <class T>
StackNode<T>::StackNode() {
    next = nullptr;
    data = T(); //data will be default initialized
}

template <class T>
StackNode<T>::StackNode(const T& value)
    : data(value)
{
    next = nullptr;
}

template <class T>
StackNode<T>& StackNode<T>::operator=(const StackNode<T>& other)
{
    data=other.data;
    next = other.next;
}

//--------------------------------------------------------------------
// Stack Implementations
//--------------------------------------------------------------------


template <class T>
Stack<T>::Stack() {
    top = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other) {
    top = other.top;
}


template <class T>
Stack<T>::~Stack() {
    deleteList(top);

}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {


    if(&other != this) {
            /* this is a real assignment */




            top = other.top;

        }

        return *this;



}



template <class T>
bool Stack<T>::isEmpty() const {

    return top == nullptr;
}


template <class T>
T Stack<T>::peek() const {
    return top->data;
}


template <class T>
void Stack<T>::push(const T& item) {
    StackNode<T>* newNode = new StackNode<T>(item);
    if(top == NULL){

        top = newNode;
    }
    else{

    newNode->next = top;
    top = newNode;
    }
}


template<class T>
T Stack<T>::pop() {

    if (isEmpty())
       {
            std::cout << "The stack currently is empty.\n\n";
            return 0;
       }

       T ret = top->data;
       StackNode<T>* remove_node = top;
       top = top->next;
       delete remove_node; // DON'T FORGET TO DELETE THE STACK NODE!
       return ret;
}



template<class T>
void Stack<T>::print() const {

    recursivePrint(top);
}

template<class T>
 void Stack<T>::reversePrint() const {
    reverseRecursivePrint(top);
 }

template<class T>
void recursivePrint(StackNode<T>* current) {
     if(current == nullptr)
         std::cout << "\n" << std::endl;
     else{
         std::cout << current->data << "";
         recursivePrint(current->next);
     }
 }

template<class T>
 void reverseRecursivePrint(StackNode<T>* current) {
      if(current == nullptr)
             std::cout << "";
        else{

             reverseRecursivePrint(current->next);
              std::cout << current->data << "";

     }
 }


 template<class T>
  void Stack<T>::deleteList(StackNode<T> *current) {
      if (current == nullptr)
              return;

          deleteList(current->next);
          delete current;
  }
//--------------------------------------------------------------------
// All your code before here
//--------------------------------------------------------------------
//Turn loops back on.
//Otherwise whatever file includes this will not be able to use them.
#undef for
#undef while
#undef goto

#endif // STACK_H
