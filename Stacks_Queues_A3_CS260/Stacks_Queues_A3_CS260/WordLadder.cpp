//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <vector>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

using namespace std;


bool oneDiff(const string &dictWord, const string &stackWord)
  {
      int count = 0;

      for (unsigned int i = 0; i < stackWord.size(); ++i)
      {
          if (dictWord.at(i) != stackWord.at(i))
          {
              ++count;
          }
      }

      if (count <= 1)
      {
          return true;
      }

      return false;
  }

int main(){

    string startWord = "clone", endWord = "stone";
//   cout << "Enter the start word for your ladder:";
//   cin >> startWord;
//   cout << "Enter the end word for your ladder:";
//   cin >> endWord;

   vector<string>fiveLetterWords;
   string word;
   ifstream inFile("FiveLetterWords.txt");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }
     while(getline(inFile, word)){

         fiveLetterWords.push_back(word);
     }
       inFile.close();

       cout << fiveLetterWords[0];
Stack<string> words;

Stack<string> words1;
words1.push("fuck");
words.push(startWord);

cout << words.peek();
Queue<Stack<string>>wordLad;

cout << wordLad.getDataSize();
wordLad.enqueue(words);
wordLad.enqueue(words1);
Stack<string> fuck = wordLad.front();

cout << words.peek();

cout << wordLad.front().peek();



//while (!wordLad.isEmpty())
//   {
//       for (unsigned int i=0; i < fiveLetterWords.size();i++)
//       {
//           if (oneDiff(fiveLetterWords[i], wordLad.front().peek()))
//           {
//               if (fiveLetterWords[i] == endWord)
//               {
//                   Stack<string> output;


//                   while (!wordLad.front().isEmpty())
//                   {
//                       output.push(wordLad.front().pop());

//                   }

//                   while (!output.isEmpty())
//                   {
//                       cout << output.peek() << " ";

//                   }

//                   cout << fiveLetterWords[i] << endl;

//                   return 0;
//               }
//               else
//               {
//                   Stack<string> temp; temp.push(wordLad.front().pop());
//                   temp.push(fiveLetterWords[i]);
//                   wordLad.enqueue(temp);
//                   fiveLetterWords.erase(fiveLetterWords.begin());
//               }
//       }

//       wordLad.front().peek();
//   }

//   cout << "No word ladder exists for this word." << endl;

//}

}

