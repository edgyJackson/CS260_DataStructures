//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

bool operator<(const Person& p1, const Person& p2){

    if(p1.last == p2.last)
        return (p1.first<p2.first);
    else
        return (p1.last < p2.last);



}



bool operator==(const Person& p1, const Person& p2){
    if(p1.kNum == p2.kNum)
        return true;
    else
        return false;
}

void partialZipSort(Person* array, int start, int end) {
    int size = end;
    int i, j;
    Person temp;
    for(i = start; i <size; i++){
          for(j = start; j < size -1; j++) {
            if(array[j].zipCode > array[i].zipCode){
                      temp = array[i]; //swap them
                      array[i] = array[j];
                      array[j] = temp;
                    }
           }
    }
    }


void nameSort(Person* array, int size) {

    //Sorts an array of Persons of given size

    //    allocates n extra storage and calls helper

    Person* temp = new Person[size];
    mergeSortInternal(array, 0, size-1, temp);


    delete [] temp;


}



int countLastName(const std::string& lastName, const Person* array, int size) {
    int count=0;
    for(int i = 0; i < size-1;i++){
        if(array[i].last == lastName){
            count += 1;
        }
    }

    return count;
}

int binaryFindFirstByLastName(const std::string& value, const Person* array, int size) {


    int low = 0;
    int mid;
    int high = size - 1;
    while(low <= high){
        mid = (low + high)/2;

        if(array[mid].last == value){
            if(  mid-1 < low)
            return mid;
            else if(array[mid-1].last != value){
                return mid;
            }
            else if(array[mid-1].last==value)
            {high = mid-1;}
        }

        else if(array[mid].last <value)
            low = mid + 1;
        else
            high = mid - 1;


    }
    return -1;


}




int binaryFindLastByLastName(const std::string& value, const Person* array, int size) {


    int low = 0;
    int mid;

    int high = size - 1;

    while(low <= high){

        mid = (low + high)/2;

        if(array[mid].last == value){
            if(  mid+1 > high)
            return mid;
            else if(array[mid+1].last != value){
                return mid;
            }
            else if(array[mid+1].last==value)
            {low = mid+1;}
        }

        else if(array[mid].last <value)
            low = mid + 1;
        else
            high = mid - 1;


    }
    return -1;
  }

int countLastNameInSorted(std::string lastName, const Person* array, int size) {
    int count=0;
    for(int i = 0; i < size-1;i++){
        if(array[i].last == lastName){
            count += 1;
        }
    }

    return count;
}
Person parsePerson(string personString) {
    Person newPerson;

    //get kNum
    unsigned int commaLoc = personString.find(",");
    newPerson.kNum =personString.substr(0, commaLoc);

    //get last name
    personString.erase(0, commaLoc+1);  //clear everything up to first comma
    unsigned int commaLoc2 = personString.find(",");
    string lastN =  personString.substr(0, commaLoc2);
    newPerson.last = lastN;

    //get first name
    personString.erase(0, commaLoc2+1);  //clear everything up to first comma
    unsigned int commaLoc3 = personString.find(",");
    string firstN =  personString.substr(0, commaLoc3);
    newPerson.first = firstN;

    //get zipCode
    string lString =  personString.substr(commaLoc3 + 1);
    newPerson.zipCode = stoi(lString);

    return newPerson;
}

void print(const Person& pers){
    cout << pers.last << ", " << pers.first << ", " << pers.zipCode << "\n";

}


//Precondition: arr contains two sorted sequences:
//   one begins at low and ends at mid
//   other begins at mid+1 and ends at high
//Postcondition: sequences are merged into one
//   sorted sequence spanning from low to high
void mergeFunc(Person* array, int low, int mid, int high, Person* temp) {
    //TODO - Fixme
    int lSide, rSide, output;

    lSide = low;
    rSide = mid+1;
    output = low;

    while(lSide <= mid && rSide <= high){

         if(array[lSide] < array[rSide]){
            temp[output] = array[lSide];
            lSide++;
            }

         else{
            temp[output] = array[rSide];

            rSide++;

            }
        output++;
    }
     while(lSide <=mid){
            temp[output] = array[lSide];

            output++;
            lSide++;
}
     while(rSide <=high){
             temp[output] = array[rSide];

            output++;
            rSide++;
     }


     for(lSide = low;lSide<output;lSide++){
        array[lSide] = temp[(lSide)];
    }
}
    //While either first sequence has an item left or second sequence has an item left
    //   Move smaller remaining item from front of first or second sequence
    //   to next available location in temp

    //Copy indexes from low-high from temp back to arr



void mergeSortInternal (Person* array, int low, int high, Person* temp) {
    if (low < high){


    int mid = (low + high) / 2;
    mergeSortInternal(array, low, mid, temp); /* sort first half */
    mergeSortInternal(array, mid+1, high, temp); /* sort second half */
    mergeFunc(array, low, mid, high, temp); /* merge two halves using temp */

    }

}








