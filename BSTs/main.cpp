//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>

#include "MySet.h"

using namespace std;

//assumes x is in range [0-999]
string intTo3DigitString(int x) {
	stringstream s;
	s << setw(3) << setfill('0') << x;
	return s.str();
}

//Returns a vector containing all valid IP addresses starting with 192.168
vector<string> getLocalIPs() {
	string prefix = "192.168";
	
	vector<string> localIPs;
	
	for(int i = 0; i < 256; i++) {
		string thirdSegment = "." + intTo3DigitString(i);
		for(int j = 0; j < 256; j++) {
			string fourthSegment = "." + intTo3DigitString(j);
			localIPs.push_back(prefix + thirdSegment + fourthSegment);
		}
	}
		
	return localIPs;
}



int main()
{
    int const LOOPS = 1;
    int size= 100000;
    MySet<string> setA;
    MySet<string> setB;




    //read in number of records to pull
    cout << "***********************Part 1************************\n\n";
    cout << "enter number of IP's to handle: ";
    cin >> size;

    //open file and check if it's open
    ifstream inFile;
    ifstream inFile2;
    inFile.open("IPListA.txt");
    inFile2.open("IPListB.txt");
    if(!inFile.is_open() && !inFile2.is_open()){
        cout << "Error opening file!!!";
        exit(0);
    }
    //read in every line one at at time and store as string
    for(int i = 0; i < size; i++) {
        string temp;
        string temp2;
        getline(inFile, temp);
        getline(inFile2, temp2);//read one line from file and store as string
        setA.add(temp);//add string to setA
        setB.add(temp2);//add string to setB
        }

    cout << "\nNumber of items in setA: " << setA.size();
    cout << "\n";
    cout << "\nDepth of setA: " << setA.depth();
    cout << "\n\n";

    cout << "***********************Part 2************************\n\n";

     //timing code
    clock_t startTime = clock();

    //
    for(int i=0;i<LOOPS;i++){
    setA.getSmallest();

    }
    clock_t endTime = clock();

    cout << "smallest item in setA: " << setA.getSmallest();
    cout << "\n";

    //output algorithm timing results in seconds
    double seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "getSmallest took " << seconds << " seconds\n\n";

    cout << "***********************Part 3************************\n\n";

    MySet<string> setA2(setA);
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";
    cout << setA2.removeLargest() <<"\n";

    cout << "\nnumber of items left in setA2 after removing largest 10 times: " << setA2.size() << "\n";

    cout << "***********************Part 4************************\n\n";




    MySet<string> setA3(setA);
    vector<string> localIPs = getLocalIPs();
        vector<string> foundLocals(setA3.getRange(localIPs.front(), localIPs.back()));

        for(unsigned int i=0;i<foundLocals.size();i++){
             setA3.remove(foundLocals[i]);

        }

    cout << "\nsetA3 size after removing local IPs: " << setA3.size() << "\n\n";
    cout << "***********************Part 5************************\n\n";



    MySet<string> setAUB = setA.unionWith(setB);



    cout << "setAUB size: " << setAUB.size() <<"\n";
    cout << "setAUB smallest item: " << setAUB.getSmallest();

    cout << "\n\n***********************Part 6************************\n\n";


    MySet<string> setAIB;

    setAIB = setA.intersectionWith(setB);


    cout << "setAIB size: " << setAIB.size() <<"\n";
    cout << "setAIB smallest value: " << setAIB.getSmallest() << "\n";

    cout << "\n\n***********************Part 7************************\n\n";

    vector<string> setASpecifiedRange;

    //timing code
    startTime = clock();

    for(int i=0;i<LOOPS;i++){
    setASpecifiedRange = setA.getRange("100.000.000.000" , "110.000.000.000");
    }

    endTime = clock();
    //output algorithm timing results in seconds
    seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "getRange function took " << seconds << " seconds\n";



    cout << "\nnumber of items in the vector: " << setASpecifiedRange.size() << "\n\n";


    for(unsigned int i = 0; i<5; i++ ) {
        cout << setASpecifiedRange[i] << "\n";
    }
cout << "\n";

return 0;

}
