#include <iostream>
#include "Stack.h"
#include "Queue.h"


using namespace std;

int main()
{

cout << "----------------------Part A: Stack----------------------\n";
cout << "-----------------1)----------------------\n";

    cout << "creating empty stack s1\n\n";
    Stack<char> s1;


    cout << "pushing B A R \n\n";
    s1.push('B');
    s1.push('A');
    s1.push('R');

    cout << "peeking at s!: " << s1.peek()<< "\n\n";


    cout << "printing in order\n";

    s1.print();


    cout << "\npopping s1 \n\n";
    s1.pop();


    cout << "pushing D \n\n";
    s1.push('D');


    cout << "printing in order\n\n";

    s1.print();

    cout << "\nprinting in reverse order\n";

    s1.reversePrint();

cout << "\n----------------------Part B: Queue----------------------\n";
cout << "-----------------3)----------------------\n";


cout << "creating empty queue q1 with default size of 20\n\n";
Queue<char> q1;


cout << "--------enqueueing letters F, L, A \n\n";
q1.enqueue('F');
q1.enqueue('L');
q1.enqueue('A');


cout << "--------dequeing a letter \n\n";


q1.dequeue();

cout << "--------enqueueing letter T\n\n";

q1.enqueue('T');



cout << "--------printing the current queue\n\n";

q1.print(q1.getStart());

cout << "\n--------enqueueing letter E\n";

q1.enqueue('E');

cout << "\n--------dequeing another letter \n";


q1.dequeue();


cout << "--------printing the current queue\n\n";



cout << "\n--------enqueueing '?' 1000 times \n";

for(int i=0;i<1000;i++)
{
    q1.enqueue('?');
}


cout << "\n--------dequeueing 1000 times \n";
for(int i=0;i<1000;i++)
{
    q1.dequeue();
}

cout << "--------printing the current queue\n\n";

q1.print(q1.getStart());



cout << "\n\n--------------------------------------------\n\n";

}
