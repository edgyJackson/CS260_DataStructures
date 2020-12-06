//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;


int main()
{
    int size = 0;
    cout << "Enter problem size:" << endl;
    cin >> size;

    ArrayList<Address> aListA;
    ArrayList<Address> aListB;

    AddressFactory aFactory("25000AddressesA.txt");
    AddressFactory aFactory2("25000AddressesB.txt");

    for(int i = 0; i < size / 2; i++) {
        Address a = aFactory.getNext();
        aListA.insertEnd(a);
        Address a2 = aFactory2.getNext();
        aListB.insertEnd(a2);
    }


cout << "-----------------------Part 1-----------------------------\n\n";


//Combine aListB into aListA

aListA.combine(aListB);

//Print out the number of items in aListA and aListB

cout << " # of items in aListA: " << aListA.listSize() << endl;
cout << " # of items in aListB: " << aListB.listSize()<< "\n\n";

//printing 4 middle indexes of combined list aListA";

printListRange(aListA, size/2 - 2,size/2 + 1 );

cout << "\n\n";


cout << "-----------------------Part 2-----------------------------\n\n";


//create an address struct and initialize the state variable as "OR"
Address OregonAddress;
OregonAddress.state = "OR";

ArrayList<Address> aListC = aListA.extractAllMatches(OregonAddress);

cout << "aListA length: " << aListA.listSize() << "\n\n";
cout << "aListC length: " << aListC.listSize()<<"\n\n";


cout << "-----------------------Part 3-----------------------------\n\n";


AddressLinkedList linkListA;
AddressLinkedList linkListB;

AddressFactory aLLFactory("25000AddressesA.txt");
AddressFactory aLLFactory2("25000AddressesB.txt");

for(int i = 0; i < size / 2; i++) {
    Address a0 = aLLFactory.getNext();
    linkListA.insertEnd(a0);
    Address a1 = aLLFactory2.getNext();
    linkListB.insertEnd(a1);
}

cout << "\nlinkListA 2-4 :\n";
linkListA.printRange(2,4);

cout << "\n\n\nlinkListB 2-4 :\n";
linkListB.printRange(2,4);


cout << "\n\n-----------------------Part 4-----------------------------\n\n";


AddressLinkedList linkListC(linkListA);
AddressLinkedList linkListD(linkListB);

cout << "Still Here \n\n";

linkListC.combine(linkListD);

cout << "Still Here after the combine\n\n";
cout << "\n\nlinkListC length: " << linkListC.listSize() << endl;
cout << "\n\nlinkListD length: " << linkListD.listSize() << "\n\n";


linkListC.printRange(size/2-2, size/2+1);


cout << "\n\n-----------------------Part 5-----------------------------\n\n";


AddressLinkedList linkListE = linkListC.extractAllMatches(OregonAddress);


cout << "linkListC Length: " << linkListC.listSize() << "\n\n";

cout << "linkListE Length: " << linkListE.listSize() << "\n\n";





cout << "\n\n-----------------------Part 6-----------------------------\n\n";


linkListA.interleave(linkListB);

//linkListA.printRange(0,4);




return 0;
}








