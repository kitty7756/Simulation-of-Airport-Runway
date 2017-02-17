/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;

   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();

   Queue q3;
   q3 = q1;
   cout << "Contents of queue q3 after q3 = q1 (via  print):\n";
   print(q3); 
   cout << endl;

   cout << "Move 300 to front if there's any: " << endl;
   q3.move_to_front(300);     
   q3.display(cout);
   cout<< endl;

   Queue q4;
   q4 = q1;
   cout << "Contents of queue q4 after q4 = q1 (via  print):\n";
   print(q4); 
   cout << endl;

   Queue q5;
   q5.enqueue(250);
   q5.enqueue(420);

   q4.merge_two_queues(q5);
   cout << "Contents after calling merge two queues on q4(q5), q5 has elements 250 and 420: " << endl;
   print(q4);
   cout<<endl;

   cout << "Contents to check if the merged queue is empty: " << endl;
   print(q5);
   cout << "There should be nothing for the lane above this one since the queue is empty" <<endl;
   cout<<endl;

   



   //system("PAUSE");
   return 0;
}
