/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Function  search through a queue for a particular key value, and if found, move the node to
//the front of the same queue. 
void Queue::move_to_front(int keyValue){
	if (!empty() && myFront != myBack){
		for (Queue::NodePointer ptr = myFront; ptr != 0; ptr=ptr->next) {
			if (ptr == myBack) {
				break;
			}
			if ((ptr->next)->data == keyValue){
				Queue::NodePointer position = ptr->next;
				Queue::NodePointer after = (ptr->next)->next;
				ptr->next = after;
				Queue::NodePointer currentFront = myFront;
				myFront = position;
				myFront->next = currentFront;
				break;
			}
		}
	}
}

void Queue::merge_two_queues(Queue & anotherQueue) {
	if (empty() && !anotherQueue.empty()) {
		myFront = anotherQueue.myFront;
		myBack = anotherQueue.myBack;
		anotherQueue.myFront = anotherQueue.myBack = 0;
		return;
	}

	if (!empty() && !anotherQueue.empty()) {

		Queue::NodePointer newF = 0;
		Queue::NodePointer newB = 0;

		if (myFront->data <= anotherQueue.myFront->data){
			newF = newB = myFront;
			myFront = myFront -> next;
		} else {
			newF = newB = anotherQueue.myFront;
			anotherQueue.myFront = anotherQueue.myFront->next;
		}

		while (myFront != 0 || anotherQueue.myFront != 0) {
			if (myFront == 0) {
				newB->next = anotherQueue.myFront;
				newB = newB->next;
				anotherQueue.myFront = anotherQueue.myFront->next;
			}
			else if (anotherQueue.myFront == 0) {
				newB->next = myFront;
				newB = newB->next;
				myFront = myFront->next;
			} else {
				if (myFront->data <= anotherQueue.myFront->data) {
					newB->next = myFront;
					newB = newB->next;
					myFront = myFront->next;
				} else {
					newB->next = anotherQueue.myFront;
					newB = newB->next;
					anotherQueue.myFront = anotherQueue.myFront->next;
				}
			}

		}

		myFront = newF;
		myBack = newB;
		anotherQueue.myBack = 0;

	}
}

