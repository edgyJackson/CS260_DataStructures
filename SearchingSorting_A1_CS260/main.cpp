#include <iostream>
#include <fstream>
#include "Person.h"
#include <string>
#include <ctime>
using namespace std;

int main()
{
//***************PART 1***************
int size= 100000;

   //read in number of records to pull
cout << "***********************Part 1************************\n\n";
    cout << "enter number of records to examine ";
    cin >> size;


    //create dynamic person array using input as size
    Person *personArray = new Person[size];

    //open file and check if it's open
    ifstream inFile;
   inFile.open("people.txt");
   if(!inFile.is_open()){
          cout << "Error opening file!!!";
          exit(0);
      }



    //read in every line one at at time and perform parsePerson function
   //and split the string into 4 variables
        for(int i = 0; i < size; i++) {
            string temp;
            getline(inFile, temp);  //read one line from file and store as string
            personArray[i] = parsePerson(temp); //parse string into Person variables
        }


cout << "\n\n***********************Part 2************************\n\n";

string lastName = "Mertz";
int const LOOPS = 1;
int numberOfMertz = 0;

//timing code
clock_t startTime = clock();

        //count number of Mertz in array, can loop algorithm if needed
   for(int i=0;i<LOOPS;i++){
        numberOfMertz = countLastName(lastName, personArray, size);
    }
clock_t endTime = clock();

    //ouput number of names found in array.
    cout << "number of " << lastName << " in your array: " << numberOfMertz << "\n";
   //output algorithm timing results in seconds
   double seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
   cout << "search took " << seconds << " seconds\n";


cout << "\n\n***********************Part 3************************\n\n";

partialZipSort(personArray,2,7);

for(int i=0;i<10;i++){

    print(personArray[i]);
}

cout << "\n\n***********************Part 4************************\n\n";


////timing code
startTime = clock();

for(int i=0;i<LOOPS;i++){

        nameSort(personArray, size);
   }

endTime = clock();


for(int i=0;i<100;i++){

    print(personArray[i]);
}

//output algorithm timing results in seconds
seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
cout << "\nsearch took " << seconds << " seconds\n";


cout << (personArray[1] < personArray[0]);

cout << (5 < 6);



cout << "\n\n***********************Part 5************************\n\n";




cout << "Last Abbott at index: "<< binaryFindLastByLastName("Abbott", personArray, size)<< endl;
cout << "Last Zulauf at index: " << binaryFindLastByLastName("Zulauf", personArray, size)<< endl;



cout << "First Abbott at index: "<< binaryFindFirstByLastName("Abbott", personArray, size)<< endl;
cout << "First Zulauf at index: "<< binaryFindFirstByLastName("Zulauf", personArray, size)<< endl;



cout << "\n\n***********************Part 6************************\n\n";


startTime = clock();

cout << "Mertz found: " << countLastNameInSorted("Mertz", personArray, size) << "\n";

endTime = clock();

//output algorithm timing results in seconds

seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
cout << "\nsearch took " << seconds << " seconds\n";

return 0;


    }

