//----------------------------------------------------------
// CS260 Assignment 5 IndexBuilder
//----------------------------------------------------------

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

#include "IndexMap.h"

using namespace std;


//had to use to remove random characters in the beginning of text file.
void SkipBOM(std::ifstream &in)
{
    char test[3] = {0};
    in.read(test, 3);
    if ((unsigned char)test[0] == 0xEF &&
        (unsigned char)test[1] == 0xBB &&
        (unsigned char)test[2] == 0xBF)
    {
        return;
    }
    in.seekg(0);
}


int main()
{

//    int const LOOPS = 1;
    IndexMap bookIndex;


//read in strings from book, if string starts with "-" increase page num, word num = 1
cout << "***********************Part 3************************\n\n";
cout << "read in the file and build an index of the contents of the book:\n";

//open file and check if it's open
    ifstream inFile;
    inFile.open("GreatExpectations.txt");

    SkipBOM(inFile);

    if(!inFile.is_open()){
     cout << "Error opening file!!!";
        exit(0);
}

//read in every word and store it in an IndexMap

int pageNum=1;
int wordNum=1;
string temp;



//timing code
clock_t startTime = clock();

//read in words from text file
while(inFile >> temp) {
    if(temp.substr(0,1)=="-") {
        pageNum++;
        wordNum = 1;
    } else {
    IndexLocation tempLoc(pageNum, wordNum);
    bookIndex.add(temp, pageNum, wordNum);
    wordNum++;

    }
}

clock_t endTime = clock();

   //output algorithm timing results in seconds
   double seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
   cout << "Index build took " << seconds << " seconds\n";
   cout << "Number of distinct words in the book = " << bookIndex.numKeys() << "\n\n";
   cout << "--------------------------------" << endl;


       IndexRecord record = bookIndex.get("fathers");
       cout << "printing record for \"fathers\": \n"<< record << endl;

        IndexRecord record2 = bookIndex.get("great");
       cout << "\nprinting record for \"great\": \n"<< record2 << endl;


   cout << "\n\n***********************Part 4************************\n\n";
   cout << "print out all locations where the first word is directly followed by the second word:\n\n";

   bookIndex.findWordPairs("great", "expectations");

   bookIndex.findWordPairs("my", "milkshake");

   bookIndex.findWordPairs("my", "day");

   bookIndex.findWordPairs("my", "fathers");

      bookIndex.findWordPairs("family", "name");

   cout << "\n\n";



   cout << "\n\n***********************Part 5************************\n\n";
   cout << "given a location (word 1 on page x), find the associated key:\n\n";

   cout << "first word on page 100 = ";
   cout << bookIndex.firstWordOnPage(50) << "\n\n";

    int age = 28;

    cout << "My age is " << age ;

    age + 1;

    printf("\nmy age is %i\n", age);









   return 0;

}
