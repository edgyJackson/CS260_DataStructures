//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "Stack.h"

using namespace std;


int main()
{
   ifstream inFile("Document.html");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }



Stack<string> s1;
string line;



//test print

//while ( getline ( inFile, line ))

//{
//  stringstream ss ( line );

//      while ( getline (ss ,line, ' '))
//      {
//          s1.push(line);
//      }
//}
//s1.reversePrint();
//}


bool endTag = 0;

while ( getline ( inFile, line ))

{
  stringstream ss ( line );

      while ( getline (ss ,line, ' '))
      {
         if(endTag == 1)

          {
              if(line.find("/")==1){
                  s1.pop();


                  endTag = 1;


                    cout << "";
              }
              else if(line.find("<")==0){


                    s1.pop();
                    endTag = 0;
                    s1.push(line);
                    cout << "";

              }

            else
                 {
                    s1.pop();
                    endTag = 0;
                    s1.reversePrint();
                    cout << line << "\n";
                    }

           }
          else if (line.find("/") == 1)
         {
             endTag = 1;

         }
          else if(line.find("<") ==0)
         {
             s1.push(line);
         }
          else
         {
             s1.reversePrint();
             cout << line << "\n";
         }
      }
}

}


