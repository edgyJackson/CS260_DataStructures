#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Searches.h"

int main()
{
    //Seed the rng for random generation
    srand(time(0));

    //----------------------Correctness Test------------------------
//	int smallNumsSize = 8;
//	int smallNums[] = {1, 3, 6, 8, 12, 13, 15, 17};

//	cout << "Testing with smallNums:" << endl;
//	for(int i = 0; i < 20; i++) {
//        int loc = binarySearch(i, smallNums, smallNumsSize);
//		cout << i << " is at: " << loc << endl;
//	}

    //----------------Test timing with Large Numbers----------------
    const int BIGNUM_SIZE = 1000000;
    int* bigNums = new int[BIGNUM_SIZE];

    //Fill with random numbers and sort
    genNums(bigNums, BIGNUM_SIZE);

    cout << "still alive\n";


	//TODO Do some searching here
    int myNum = randomValue(), numberLocation;

    clock_t startTime = clock();

    for(int i = 0; i <= 1000; i++) {
    numberLocation = binarySearch(myNum, bigNums, BIGNUM_SIZE);
    cout << myNum << " is located at index " << numberLocation << "\n";
    }

    clock_t endTime = clock();
    double seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    cout << seconds << "\n";

delete [] bigNums;
    return 0;
}
