#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

#include "Searches.h"


//low and high represent the
//returns location of value or -1 if not present
int recursiveBinarySearchHelper(int value, int arr[], int low, int high) {
    return -1; //TODO - fixme
}

//returns location of value or -1 if not present
int recursiveBinarySearch(int value, int arr[], int arrSize) {
    //pass off work to recursive helper function
    return recursiveBinarySearchHelper(value, arr, 0, arrSize - 1);
}

//returns location of value or -1 if not present
int binarySearch(int value, int arr[], int arrSize) {

    int low = 0;
    int mid;
    int high = arrSize - 1;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] > value)
            high = mid - 1;
        else if(arr[mid] < value)
            low = mid + 1;
        else
            return mid;


    }


    return -1; //TODO - fixme
}




//pick number 1-1,000,000
int randomValue() {
    int thousands = rand() % 1000;
    int ones = rand() % 1000;
    return thousands * 100 + ones;
}

//fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++)
        arr[i] = randomValue();

    //Sort using std:: algorithm
    sort(arr,arr+arrSize);
}


