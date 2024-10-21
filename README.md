Multilevel Feedback Queue Scheduling Simulation
This project simulates Multilevel Feedback Queue (MLFQ) scheduling, a CPU scheduling algorithm that allows processes to be dynamically prioritized across multiple queues. The program is implemented in C++ and manages process scheduling based on three queues with different time quanta. The goal of this algorithm is to optimize CPU utilization by giving higher priority to shorter or more interactive processes.

Table of Contents
Overview
Features
Input Process Details
How It Works
Gantt Chart and Times Display
Usage
How to Run the Program
Example Output
License
Overview
The Multilevel Feedback Queue Scheduling algorithm works by assigning each process to one of several queues. The processes in higher-priority queues receive shorter CPU time slices (time quanta). If a process does not finish within its allotted time slice, it is demoted to a lower-priority queue. This approach helps to handle both short and long-running processes efficiently, without allowing long processes to starve.

Features
Multiple Queues: Three priority queues with different time quanta.
Process Preemption: Processes are preempted and demoted to lower-priority queues if they use up their allotted time slice.
Turnaround and Waiting Time Calculation: The program calculates both turnaround and waiting times for each process.
Gantt Chart: The program visually displays the order of process execution in a Gantt chart.
Input Process Details
The input consists of a list of processes, each with the following attributes:

Name: A string identifier (e.g., P1, P2).
Arrival Time: The time when the process arrives in the ready queue.
Burst Time: The total time required by the process to complete execution.
Priority: The priority level of the process. A lower number indicates a higher priority.
In this simulation, five processes are hardcoded as input for simplicity, but you can modify the program to take dynamic input.

How It Works
Queue Structure
Queue 1: Highest priority with the shortest time quantum (quant1).
Queue 2: Medium priority with a larger time quantum (quant2).
Queue 3: Lowest priority with the longest time quantum (quant3).
Scheduling Algorithm
Process Arrival: As the time progresses, processes are added to the appropriate queue based on their priority and arrival time.
Execution: The CPU selects a process from the highest priority queue that has available processes.
Preemption: If a process uses up its allotted time slice without completing, it is demoted to the next lower-priority queue.
Completion: Once a process completes, it is removed from the queue, and its turnaround and waiting times are calculated.
Process States
Waiting Time: Time spent in the queue before starting execution.
Turnaround Time: Total time from process arrival to completion.
Gantt Chart and Times Display
After running the simulation, the program displays:

Gantt Chart: Shows the sequence of processes executed over time.
Waiting Time and Turnaround Time: For each process, the program outputs the waiting time and turnaround time.
Usage
Input
The following processes are preloaded into the program:

Process	Arrival Time	Burst Time	Priority
P1	0	10	1
P2	1	5	2
P3	2	8	1
P4	3	6	3
P5	4	2	2
Time Quanta
Queue 1: quant1 = 4
Queue 2: quant2 = 6
Queue 3: quant3 = 8
How to Run the Program
Clone or Download this repository.

Compile the program using a C++ compiler.

Example compilation command (for g++):

bash
Copy code
g++ -o mlfq mlfq.cpp
Run the program:

bash
Copy code
./mlfq
The Gantt chart and process waiting/turnaround times will be displayed in the console.

Example Output
sql
Copy code
|------------------------------------------------|
|                    Gantt Chart                 |
|------------------------------------------------|
|  P1  |  P3  |  P1  |  P2  |  P5  |  P3  |  P4  |
|------------------------------------------------|

|------------------------------------------------|
| Process        Waiting Time   Turnaround Time  |
|------------------------------------------------|
|  P1                4               14          |
|  P2               13               18          |
|  P3               15               23          |
|  P4               22               28          |
|  P5               15               17          |
|------------------------------------------------|
License
This project is licensed under the MIT License - see the LICENSE file for details.
