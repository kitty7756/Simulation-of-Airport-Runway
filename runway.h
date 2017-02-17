
/*-- LQueue.h -------------------------------------------------------------

  This header file defines a runway at an Airport.
  Basic operations:
    constructor:  Constructs a runway with two empty takeoff and landing queues
    addTakeoff:   Add a takeoff flight to takeoff queue
    addLanding:   Add a landing flight to landing queue
    dequeueTakeoff: dequeue the first flight in the takeoff queue
    dequeueLanding: dequeue the first flight in the landing queue 
    Note: Execution terminates if memory isn't available for a queue element.
---------------------------------------------------------------------------*/

#ifndef RUNWAY
#define RUNWAY
#include "LQueue.h"

class Runway
{
 public:
  /***** Function Members *****/

  /***** Constructors *****/
  Runway();
  /*-----------------------------------------------------------------------
    Construct a Runway object.

    Precondition:  None.
    Postcondition: runway with empty takeoff and landing queues
  -----------------------------------------------------------------------*/
    
  /***** Destructor *****/
  ~Runway();

  void addTakeoff(int);
  /*-----------------------------------------------------------------------
    add a flight with the int as its flight number to the takeoff queue

    Precondition:  None.
    Postcondition: flight added to the queue
  -----------------------------------------------------------------------*/

  void addLanding(int);
  /*-----------------------------------------------------------------------
    add a flight with the int as its flight number to the landing queue

    Precondition:  None.
    Postcondition: flight added to the queue
  -----------------------------------------------------------------------*/

  void dequeueTakeoff();
  /*-----------------------------------------------------------------------
    dequeue the first flight in the takeoff queue

    Precondition:  queue is not empty
    Postcondition: first flight removed from queue
  -----------------------------------------------------------------------*/

  void dequeueLanding();
  /*-----------------------------------------------------------------------
    dequeue the first flight in the landing queue

    Precondition:  queue is not empty
    Postcondition: first flight removed from queue
  -----------------------------------------------------------------------*/

  bool checkInUse();
   /*-----------------------------------------------------------------------
    checks to see if the runway is in use

    Precondition:  None.
    Postcondition: return the status of inUse
  -----------------------------------------------------------------------*/

  void setInUseTrue();
  /*-----------------------------------------------------------------------
    sets runway to use

    Precondition:  None.
    Postcondition: sets inUse to true
  -----------------------------------------------------------------------*/

  void setInUseFalse();
  /*-----------------------------------------------------------------------
    sets runway to be not used

    Precondition:  None.
    Postcondition: sets inUse to false
  -----------------------------------------------------------------------*/

  bool checkEmptyTakeoffQueue();
  /*-----------------------------------------------------------------------
    checks if takeoff is empty

    Precondition:  None.
    Postcondition: return the empty status of takeoff
  -----------------------------------------------------------------------*/

  bool checkEmptyLandingQueue();
  /*-----------------------------------------------------------------------
    checks if landing is empty

    Precondition:  None.
    Postcondition: return the empty status of landing
  -----------------------------------------------------------------------*/

  int firstTakeoffNumber();
  /*-----------------------------------------------------------------------
    returns the data of the head of takeoff queue

    Precondition:  queue is non-empty.
    Postcondition: return the data of the head 
  -----------------------------------------------------------------------*/

  int firstLandingNumber();
  /*-----------------------------------------------------------------------
    returns the data of the head of landing queue

    Precondition:  queue is non-empty.
    Postcondition: return the data of the head
  -----------------------------------------------------------------------*/
  void merge_two_runways(Runway & anotherRunway);
  /*-----------------------------------------------------------------------
    merge the takeoff and landing queues of two runways

    Precondition:  None.
    Postcondition: merged takeoff and landing queues, anotherRunway has 
    				empty takeoff/landing queues after merging
  -----------------------------------------------------------------------*/


  private:
    Queue takeoff;
    Queue landing;
    bool inUse = false;


}; // end of class declaration

#endif
