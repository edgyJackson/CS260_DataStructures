//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include "AddressLinkedList.h"

AddressListNode::AddressListNode() {
    next = nullptr;
    //data will be default initialized
}

AddressListNode::AddressListNode(const Address& value)
    : data(value)
{
    next = nullptr;
}

AddressLinkedList::AddressLinkedList(){

    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

AddressLinkedList::AddressLinkedList(const AddressLinkedList& other){

    head = nullptr;
    tail = nullptr;
    length = 0;

    //start at beginning of other list and walk all the way to the end
    // build new list by adding each value to end of existing list
    AddressListNode* positionInOther = other.head; //use to walk through other list
    while(positionInOther != nullptr){
    insertEnd(positionInOther->data); //make a new node in this list with current value in other list
    positionInOther = positionInOther->next;
    }

}

//AddressLinkedList& AddressLinkedList::operator=(const AddressLinkedList& other){}

AddressLinkedList::~AddressLinkedList(){

    AddressListNode* current = head;
    while( current != nullptr ) {
        AddressListNode* next = current->next;
        delete current;
        current = next;
        length--;
    }


}

int AddressLinkedList::listSize() const{

    return length;
}

void AddressLinkedList::print() const{
    //current will point to each element in turn
    AddressListNode* current = head;

    while(current != nullptr) {
        std::cout << current->data;   //print current item
        current = current->next;        //advance to next
    }
    std::cout << "done!" << "\n";
}

void AddressLinkedList::printRange(int startIndex, int endIndex) const{

    AddressListNode* current = head;

    for(int i=0;i<startIndex;i++) {
               current=current->next; //advance to next

    }

    for(int i=0; i<endIndex-startIndex+1;i++){
        std::cout << current->data;
        current=current->next; //advance to next
    }

}

void AddressLinkedList:: insertStart(const Address& value){

    AddressListNode* temp = new AddressListNode(value);

    temp->next = head;  //The new node has to point to, what used to be the first node1
    head = temp;        //new node is now head

    //if there is no second node, new node is both head and tail
    if(head->next == nullptr)
        tail = head;
    if(tail==nullptr){
        tail=temp;
    }
    length++;
}

void AddressLinkedList::insertEnd(const Address& value){

//check if list is empty if so set head to point to the temp
        if(head==nullptr){
            insertStart(value);
            return;
        }


AddressListNode* temp = new AddressListNode(value);


//use tail to insert node at end of list
tail->next = temp;
tail = temp;
length++;

}

Address AddressLinkedList::removeFirst(){


    Address oldHead = head->data;
    AddressListNode* temp = head->next;
    delete head;
    head = temp;
length--;
    return oldHead;
}

//Address AddressLinkedList::retrieveAt(int index) const{

//    //Advance to location we want to retieve
//    AddressListNode* temp = head;
//    for(int i = 0; i < index; i++) {
//    temp = temp->next;
//    }

//    return temp->data;
//}

void AddressLinkedList::combine(AddressLinkedList& other){


int size = other.length;


std::cout << "got the size";
    for(int i =0;i<size;i++){
    insertEnd(other.removeFirst()); //make a new node in this list with current value from other list
    }



}

Address AddressLinkedList::removeAt(int index){



    Address temp;
    if(index == 0)
    this->removeFirst(); //special case
    else{

        AddressListNode* current = head;
    for(int i=0;i<index-1;i++){
            current = current->next;
    }

    AddressListNode* nodeToRemove = current->next;
    current->next = nodeToRemove->next;
     temp=nodeToRemove->data;
    delete nodeToRemove;
    this->length--;
    }

    return temp;
    }

AddressLinkedList AddressLinkedList::extractAllMatches(const Address& itemToMatch){

    AddressListNode* current = head;
    AddressLinkedList aListE;



      for(int i=0;i<length;i++){
           if(current->data.state == itemToMatch.state){
               aListE.insertEnd(this->removeAt(i-1));
               i--;
            }


         current = current->next;

       }





       //FIXME - returns empty list
       return aListE;
}


void AddressLinkedList::insertAt(int index, const Address& value){


if(index == 0) {
this->insertStart(value);
return;
}
//Advance to index BEFORE the one at which we want to insert
AddressListNode* current = head;
for(int i = 0; i < index-1; i++) {
current = current->next;
if(current == nullptr)
std::cout << "error, index out of bounds";
}

//Make new node and insert it
AddressListNode* newNode = new AddressListNode(value);
newNode->next = current->next;
current->next = newNode;
length++;
}



void AddressLinkedList::interleave(AddressLinkedList& other){
    AddressListNode* currentOther = other.head;
    for(int i = 1; i <= other.length*2; i+=2) {
    this->insertAt(i,currentOther->data); //make a new node in this list with current value from other list
  currentOther = currentOther->next;
    }



}
