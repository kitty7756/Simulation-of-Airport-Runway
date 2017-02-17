

List of Files:
LQueue.C
LQueue.h
LQueue_driver.C
Makefile
runway.C
runway.h
Runway_driver.C

Summary of Runway_driver:
Runway_driver creates two runways, each has its own takeoff and landing queues. They both run when the timer starts, and generate
random planes based on random numbers. Runway2, however, also generates another random number that determines if an emergency
situation happens. If an emergency situation happens, runway2 will be shut down and all of the planes in runway 2 will be merged
to runway1. 



Example output for LQueue_driver.C:

Queue created.  Empty? true
How many elements to add to the queue? 5
Contents of queue q1 (via  print):
100  200  300  400  500  

Contents of queue q2 after q2 = q1 (via  print):
100  200  300  400  500  

Queue q2 empty? false
Front value in q2: 100
Remove front -- Queue contents: 200  300  400  500  
Remove front -- Queue contents: 300  400  500  
Remove front -- Queue contents: 400  500  
Remove front -- Queue contents: 500  
Remove front -- Queue contents: 
Queue q2 empty? true
Front value in q2?
0
Trying to remove front of q2: 
*** Queue is empty -- can't remove a value ***
Contents of queue q3 after q3 = q1 (via  print):
100  200  300  400  500  

Move 300 to front if there's any: 
300  100  200  400  500  

Contents of queue q4 after q4 = q1 (via  print):
100  200  300  400  500  

Contents after calling merge two queues on q4(q5), q5 has elements 250 and 420: 
100  200  250  300  400  420  500  

Contents to check if the merged queue is empty: 

There should be nothing for the lane above this one since the queue is empty



Example output for Runway_driver.C:

Enter: 
Time for a plane to land (in minutes): 2
Time for a plane to takeOff (in minutes): 3
Landing rate (planes per hour): 15
Takeoff rate (planes per hour): 15
How long to run the simulation (in minutes): 20
Time = 1
Plane 1 wants to land on R2; added to landing queue; 1 in queue
R2:Landing: Plane 1
Time = 2
Plane 2 wants to takeoff from R2; added to takeoff queue; 1 in queue
Time = 3
Runway R2 is free for use
R2:Takeoff queue: 1 in queue
R2:Landing queue: 0 in queue
R2:Taking off: Plane 2
R2 has been shut down due to emergency
All flights move to R1
Time = 4
Time = 5
Time = 6
Plane 3 wants to land on R1; added to landing queue; 1 in queue 
R1:Landing: Plane 3
Time = 7
Plane 4 wants to land on R1; added to landing queue; 1 in queue 
Plane 5 wants to takeoff from R1; added to takeoff queue; 1 in queue 
Time = 8
Runway R1 is free for use
R1:Takeoff queue: 1 in queue
R1:Landing queue: 1 in queue
R1:Landing: Plane 4
Time = 9
Plane 6 wants to takeoff from R1; added to takeoff queue; 2 in queue 
Time = 10
Runway R1 is free for use
R1:Takeoff queue: 2 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 5
Time = 11
Time = 12
Time = 13
Plane 7 wants to land on R1; added to landing queue; 1 in queue 
Plane 8 wants to takeoff from R1; added to takeoff queue; 2 in queue 
Runway R1 is free for use
R1:Takeoff queue: 2 in queue
R1:Landing queue: 1 in queue
R1:Landing: Plane 7
Time = 14
Time = 15
Runway R1 is free for use
R1:Takeoff queue: 2 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 6
Time = 16
Plane 9 wants to takeoff from R1; added to takeoff queue; 2 in queue 
Time = 17
Plane 10 wants to takeoff from R1; added to takeoff queue; 3 in queue 
Time = 18
Plane 11 wants to land on R1; added to landing queue; 1 in queue 
Runway R1 is free for use
R1:Takeoff queue: 3 in queue
R1:Landing queue: 1 in queue
R1:Landing: Plane 11
Time = 19
Plane 12 wants to takeoff from R1; added to takeoff queue; 4 in queue 
Time = 20
Runway R1 is free for use
R1:Takeoff queue: 4 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 8
No new takeoffs or landings will be generated
Time = 21
Time = 22
Time = 23
Runway 1 is free for use
R1:Takeoff queue: 3 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 9
Runway 2 is free for use
R2:Takeoff queue: 0 in queue
R2:Landing queue: 0 in queue
Time = 24
Time = 25
Time = 26
Runway 1 is free for use
R1:Takeoff queue: 2 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 10
Time = 27
Time = 28
Time = 29
Runway 1 is free for use
R1:Takeoff queue: 1 in queue
R1:Landing queue: 0 in queue
R1:Taking off: Plane 12
Time = 30
Time = 31
Time = 32
Runway 1 is free for use
R1:Takeoff queue: 0 in queue
R1:Landing queue: 0 in queue
End of program

Statistics
Maximum number of plane in landing queue was: 1
Average minutes spent waiting to land: 0
Maximum number of plane in takeoff queue was: 4
Average minutes spent waiting to takeoff: 3





