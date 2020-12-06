//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef MYSET_H
#define MYSET_H


#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

//Node node for Set
template <class T>
struct SetNode
{
    T data;
    SetNode<T>* left;
    SetNode<T>* right;

    SetNode(const T& value);
};


//Set based on a BST
template <class T>
class MySet
{
private:
    SetNode<T>* root;

public:
    //Construct empty set
    MySet();

    //Copy constructor 
    MySet(const MySet<T>& other);

    //Assignment operator - implement if needed
    MySet<T>& operator=(const MySet<T>& other);

    //Destructor
    ~MySet();

    //get number of items contained
    int size() const;

    //get depth of underlying tree
    int depth() const;

    //Add item to set
    //  Do not add duplicates of existing items - ignore any duplicate add
    void add(const T& item);

    //Check if item is in the set
    bool contains(const T& item) const;

    //Remove given item from the set if it exists
    void remove(const T& item);

    //returns the smallest item from the set (does not remove it)
    T getSmallest() const;
	
    //removes the largest item from the set and returns it
    T removeLargest();

    //Generates a new set containing all the items that are in either
    //  this set or another set
    //  intersections of {A, B, C, D} and {B, D, F} would be {A, B, C, D, F}
	//  Both original sets are left unmodified
    MySet<T> unionWith(const MySet<T>& other) const;
	
    //Generates a new set containing all the items that are in both
    //  this set and another set
    //  intersections of {A, B, C, D} and {B, D, F} would be {B, D}
	//  Both original sets are left unmodified
    MySet<T> intersectionWith(const MySet<T>& other) const;

    //Returns a vector of items in the set that are >= start and < end
    std::vector<T> getRange(const T& startValue, const T& endValue) const;

    //inorder print of Set
    void print();



};


//--------------------------------------------------------------------
// SetNode implementations
//--------------------------------------------------------------------

template <class T>
SetNode<T>::SetNode(const T& value)
    : data(value) {

    left = nullptr;
    right = nullptr;
}

//--------------------------------------------------------------------
// Set Implementations
//--------------------------------------------------------------------


template <class T >
MySet<T>::MySet(){

    root = nullptr;
}

template <class T>
SetNode<T>* copySubTree(SetNode<T> *current){

    if (current == nullptr)
            return nullptr;

        SetNode<T>* newNode = new SetNode<T>(current->data);
        newNode->left = copySubTree(current->left);
        newNode->right = copySubTree(current->right);

        return newNode;
}

template <class T>
MySet<T>::MySet(const MySet<T>& other) {

    root = copySubTree(other.root);

}

template<class T>
MySet<T>& MySet<T>::operator=(const MySet<T>& other) {

    if(this !=&other) {
        //remove any existing nodes before
        //copying nodes of other tree
        deleteSubTree(root);
        root = copySubTree(other.root);
    }
    return *this;
}

template<class T>
void deleteSubTree(SetNode<T> *current) {
     if (current == nullptr)
             return;

         deleteSubTree(current->left);
         deleteSubTree(current->right);
         delete current;
 }

template<class T>
MySet<T>::~MySet() {

    deleteSubTree(root);

}

template<class T>
int sizeHelper(SetNode<T> *rootNode ) {

    if(!rootNode) return 0;
    else return 1 + sizeHelper(rootNode->left) + sizeHelper(rootNode->right);
}

template<class T>
int MySet<T>::size() const {

    return sizeHelper(root);

}

template<class T>
int depthHelper(SetNode<T> *current) {
     if(!current) return 0;
     else return 1 + std::max(depthHelper(current->left), depthHelper(current->right));
}

template<class T>
int MySet<T>::depth() const {

    return depthHelper(this->root);
}

template<class T>
SetNode<T>* addHelper(SetNode<T> *curNode, T value) {
    if(curNode == nullptr) {
        return new SetNode<T>(value);
    }

    if(value < curNode->data) {
        curNode->left = addHelper(curNode->left, value);
    } else {
        curNode->right = addHelper(curNode->right, value);
    }

    return curNode;
}

template<class T>
void MySet<T>::add(const T& item) {
    if( this->contains(item)){
        //do nothing;
} else {
    root = addHelper(root, item);
    }
}

template<class T>
bool containsHelper(SetNode<T>* curNode, T valToFind) {
    if(curNode == nullptr)
        return false;
    if(curNode->data == valToFind)
        return true;

    if(curNode->data > valToFind)
        return containsHelper(curNode->left, valToFind);
    else
        return containsHelper(curNode->right, valToFind);
}

template<class T>
bool MySet<T>::contains(const T& item) const {
    return containsHelper(root, item);
}

template<class T>
SetNode<T>* removeHelper(SetNode<T>* curNode, T valToRemove) {
    if(curNode == nullptr) {
        return nullptr;     //Value not in tree
    }
    else if(valToRemove < curNode->data) {
        //Node to remove must be off to the left
        curNode->left = removeHelper(curNode->left, valToRemove);
        return curNode;
    }
    else if(curNode->data < valToRemove) {
        //Node to remove must be off to the right
        curNode->right = removeHelper(curNode->right, valToRemove);
        return curNode;
    }
    else {
        //Found the value to remove

        //Case 0: No children - delete & return nullptr. Subcase of #1.
        //Case 1: No right child. Delete and return left child.
        if(curNode->right == nullptr) {
            SetNode<T>* leftChild = curNode->left;
            delete curNode;
            return leftChild;   //replaces the current node
        }

        //Case 2: No left child.
        if(curNode->left == nullptr) {
            SetNode<T>* rightChild = curNode->right;
            delete curNode;
            return rightChild;   //replaces the current node
        }

        //Case 3: Two children. Swap in value of smallest value to right,
        curNode->data = smallestValueFrom(curNode->right);
        //Now delete that value from right subtree
        curNode->right = removeHelper(curNode->right, curNode->data);
        //Return currentNode back to caller
        return curNode;

    }
}

template<class T>
void MySet<T>::remove(const T& item) {

    root = removeHelper<T>(root, item);
}

template<class T>
T smallestValueFrom(SetNode<T>* curNode)
{
    if(curNode->left == nullptr) {
        return curNode->data;
    } else {
        return smallestValueFrom(curNode->left);
    }
}

template<class T>
T MySet<T>::getSmallest() const {
    if( root ==nullptr)
        throw std::out_of_range("Can't get smallest in empty tree");

    return smallestValueFrom(root);
}

template<class T>
SetNode<T>* removeLargestHelper(SetNode<T>* curNode)
{
    if(curNode->right == nullptr) {
        SetNode<T>* temp = curNode->left;
        delete curNode;
        return temp;
    } else {
        curNode->right = removeLargestHelper(curNode->right);

        return curNode;
    }

}

template<class T>
T largestValueFrom(SetNode<T>* curNode)
{
    if(curNode->right == nullptr) {
        return curNode->data;
    } else {
        return largestValueFrom(curNode->right);
    }
}

template<class T>
T MySet<T>::removeLargest() {
    if( root ==nullptr)
        throw std::out_of_range("Can't remove from empty tree");

    T temp = largestValueFrom(root);
    root = removeLargestHelper(root);

    return temp;

}


template <class T>
void unionWithHelper(MySet<T>& temp, SetNode<T>* otherNode) {

    if(otherNode == nullptr)
        return;

    temp.add(otherNode->data);
    unionWithHelper(temp, otherNode->left);
    unionWithHelper(temp, otherNode->right);


}

template<class T>
MySet<T> MySet<T>::unionWith(const MySet<T>& other) const {

    MySet<T> temp(*this);

    if(other.root == nullptr) { return temp;}

    unionWithHelper(temp, other.root);


    return temp;




}





template <class T>
void intersectionWithHelper(MySet<T>& temp, MySet<T>& temp2, SetNode<T>* otherNode) {

    if(otherNode == nullptr)
        return;
    if(temp.contains(otherNode->data)) {
    temp2.add(otherNode->data);
    }

    intersectionWithHelper(temp, temp2, otherNode->left);
    intersectionWithHelper(temp, temp2, otherNode->right);


}




template<class T>
MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const {

    MySet<T> mySetTemp(*this);
    MySet<T> returnTemp;

    if(other.root == nullptr) { return returnTemp;}

    intersectionWithHelper(mySetTemp, returnTemp, other.root);


    return returnTemp;
}








template<class T>
void inOrderDFS(std::vector<T> &ret, SetNode<T>* curNode, T startValue, T endValue) {
    if(curNode==nullptr) {
        return;
    }

    if((curNode->left != nullptr) && (curNode->data > startValue)) {
    inOrderDFS(ret, curNode->left, startValue, endValue);
    }

    if((curNode->data >= startValue) && (curNode->data < endValue)) {
        ret.push_back(curNode->data);
    }

    if((curNode->right != nullptr) && (curNode->data < endValue)) {
    inOrderDFS(ret, curNode->right, startValue, endValue);
    }
}



template<class T>
std::vector<T> getRangeHelper(SetNode<T>* curNode, const T& startValue, const T& endValue) {
    std::vector<T> rangeVec;

    inOrderDFS<T>(rangeVec, curNode, startValue, endValue);

    return rangeVec;

}

template<class T>
std::vector<T> MySet<T>::getRange(const T& startValue, const T& endValue) const {


    return getRangeHelper(root, startValue, endValue);

}

template<class T>
void printHelper(SetNode<T>* curNode) {
    if(curNode == nullptr)
        return;

    printHelper(curNode->left);
    std::cout << curNode->data << "\n";
    printHelper(curNode->right);
}

template<class T>
void MySet<T>::print() {
    printHelper(root);
}




#endif // MYSET_H
