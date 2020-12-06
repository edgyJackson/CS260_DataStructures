//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "IndexMap.h"

#include <cassert>
#include <algorithm>
#include <stdexcept>

using namespace std;


void IndexMap::grow() {

    //temp copies of old array and size
    IndexRecord* oldData = buckets;
    int oldTableSize = numBuckets;

    //setup new storage
    keyCount = 0;         //0 values in the new storage
                         // insert calls below will rebuild the setSize
    numBuckets = (numBuckets * 2 + 1);
    buckets = new IndexRecord[numBuckets];
    for(int i = 0; i < numBuckets; i++)
        buckets[i].word = EMPTY_CELL;

    //take value from old storage and rehash into new array
    for(int i = 0; i < oldTableSize; i++) {

        if(oldData[i].word != EMPTY_CELL && oldData[i].word != PREVIOUS_USED_CELL){

            int bucketNumber = getLocationFor(oldData[i].word);


            while(buckets[bucketNumber].word != EMPTY_CELL && buckets[bucketNumber].word != PREVIOUS_USED_CELL) {

                bucketNumber = (bucketNumber + 1) % numBuckets;

            }


            buckets[bucketNumber] = oldData[i];

            keyCount++;

            }



    }

    //delete old storage
    delete [] oldData;
}

int IndexMap::getLocationFor(const std::string& key) const {

    string word = key;
    //get hashed value of string
    hash<string> hasher;
    unsigned int hashValue = hasher(key);  //technicall type is size_t
    //return that mapped onto table
    return hashValue % numBuckets;
}



IndexMap::IndexMap(int startingBuckets) {

    keyCount = 0;
    numBuckets = startingBuckets;
    buckets = new IndexRecord[numBuckets];


    for(int i = 0; i < numBuckets; i++)
            buckets[i].word = EMPTY_CELL;



}

IndexMap::~IndexMap() {

    delete [] buckets;
}


bool IndexMap::contains(const std::string& key) const {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

    //check if key is capitalized version of existing word, if so convert to lowercase
        string word = key;
        if(isupper(key[0]) && islower(key[1]) ) {
            word[0] = tolower(key[0]);
        }

    int bucketNumber = getLocationFor(word);

    //look for the value starting in that bucket - need to keep searching until
    // we find an empty bucket
    while(buckets[bucketNumber].word != EMPTY_CELL) {
        if( buckets[bucketNumber].word == word )
            return true;

        //move to next bucket, wrap if necessary
        bucketNumber = (bucketNumber + 1) % numBuckets;
    }

    return false;
}


void IndexMap::add(const std::string& key, int pageNumber, int wordNumber) {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

//check if key is capitalized version of existing word, if so convert to lowercase
    string word = key;
    if(isupper(key[0]) && islower(key[1]) ) {
        word[0] = tolower(key[0]);
    }

//if key exists in buckets then find and add a Index location to that key's Index Record's vector
    if(contains(word)) {
        int keyLoc = getLocationFor(word);

        while(buckets[keyLoc].word != word) {

            keyLoc = (keyLoc + 1) % numBuckets;
    }

    IndexLocation curLoc(pageNumber, wordNumber);
        buckets[keyLoc].addLocation(curLoc);
        return;

    }

    //grow if needed
    if(keyCount > MAX_LOAD * numBuckets)
        grow();



    int bucketNumber = getLocationFor(word);

//find location to store Index record
    while(buckets[bucketNumber].word != EMPTY_CELL && buckets[bucketNumber].word != PREVIOUS_USED_CELL) {

        bucketNumber = (bucketNumber + 1) % numBuckets;

    }

    //add at found location and increment size

    buckets[bucketNumber].word = word;
    IndexLocation curLoc(pageNumber, wordNumber);
    buckets[bucketNumber].addLocation(curLoc);

    keyCount++;
    return;

}


int IndexMap::numKeys() const {

    return keyCount;
}






void IndexMap::print() const {
cout << "Buckets\n[ \n";
for(int i = 0; i < this->numBuckets; i++)
{
    if(this->buckets[i].word == EMPTY_CELL)
        cout << "_ \n";
    else if(this->buckets[i].word == PREVIOUS_USED_CELL)
        cout << "# \n";
    else
        cout << this->buckets[i] << " \n";
}
    cout << "\n]\n";

}


IndexRecord IndexMap::get(const std::string& word) const {


    //check if key is capitalized version of existing word, if so convert to lowercase
        string key = word;
        if(isupper(key[0]) && islower(key[1]) ) {
            key[0] = tolower(key[0]);
        }

    IndexRecord tempRecord("");
    int wordLoc = getLocationFor(key);

    while(buckets[wordLoc].word != key) {

        wordLoc = (wordLoc + 1) % numBuckets;
        if(wordLoc == getLocationFor(key)) {

            cout << word << " was not found in map\n\n";
            return tempRecord;
        }
    }

        tempRecord = buckets[wordLoc];
        return tempRecord;


}



void IndexMap::findWordPairs(const std::string& key1, const std::string& key2) const {
    if(key1 == EMPTY_CELL || key1 == PREVIOUS_USED_CELL || key2 == EMPTY_CELL || key2 == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

//check if key is capitalized version of existing word, if so convert to lowercase
    string word1 = key1;
    string word2 = key2;
    if(isupper(key1[0]) && islower(key1[1]) ) {
        word1[0] = tolower(key1[0]);
    }
    if(isupper(key2[0]) && islower(key2[1]) ) {
        word2[0] = tolower(key2[0]);
    }

//if key exists in buckets then find it's location in buckets

    cout << "\n" << key1 << ": " << key2 << "\n";

    if(!contains(word1) || !contains(word2))
    {
        cout << "one or more words were not found\n";
        return;
    }


        bool pairFound = false;
        int word1Loc = getLocationFor(word1);
        int word2Loc = getLocationFor(word2);


        while(buckets[word1Loc].word != word1) {

            word1Loc = (word1Loc + 1) % numBuckets;
        }

        while(buckets[word2Loc].word != word2) {

            word2Loc = (word2Loc + 1) % numBuckets;
        }


        for(unsigned int i =0;i<buckets[word1Loc].locations.size();i++) {



            IndexLocation nextIndex(buckets[word1Loc].locations[i].pageNum, buckets[word1Loc].locations[i].wordNum + 1);

            if(buckets[word2Loc].hasLocation(nextIndex)) {

                cout << "(" << buckets[word1Loc].locations[i] <<") ";
                pairFound = true;
            }





        }

        if(!pairFound) {

            cout << "no pairs found";
        }

        cout << "\n";


}

std::string IndexMap::firstWordOnPage(int pageNumber) const {

    IndexLocation temp(pageNumber, 1);

    for(int i=0;i<numBuckets;i++) {

        if(buckets[i].hasLocation(temp)) {

            return buckets[i].word;
        }


    }
    return  "page not found";
}
