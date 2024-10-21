#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Process {
public:
    string name;
    int arrival;
    int burst;
    int priority;
    int waiting;
    int turnaround;
    int remaining;
    bool completed;

    Process(string name, int arrival, int burst, int priority)
    {
        this->name = name;
        this->arrival = arrival;
        this->burst = burst;
        this->priority = priority;
        this->waiting = 0;
        this->turnaround = 0;
        this->remaining = burst;
        this->completed = false;
        
    }

    
};

void displayGanttChart(vector<string> &gantt) {
    cout << "\n|------------------------------------------------|";
    cout << "\n|                    Gantt Chart                 |";
    cout << "\n|------------------------------------------------|\n";
    for (const string &p : gantt) {
        cout << "|  " << p << "  ";
    }
    cout << "|";
    // cout << "\n|------------------------------------------------|";
}

void displayTimes(vector<Process> &processes) {
    cout << "\n|------------------------------------------------|";
    cout << "\n| Process\t\tWaiting Time\tTurnaround Time  |";
    cout << "\n|------------------------------------------------|\n";
    for (const Process &p : processes) {
        cout << "|  " << p.name << "\t\t\t" << p.waiting << "\t\t\t\t" << p.turnaround << "               |\n";
    }
    cout << "|------------------------------------------------|\n";
}

void multilevelFeedbackQueue(vector<Process> &processes, int quant1, int quant2, int quant3) {
    queue<Process*> queue1, queue2, queue3;
    vector<string> gantt;
    int time = 0, completed = 0;
    int n = processes.size();
    vector<bool> addedToQueue(n, false);

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    while (completed < n) {
        bool processExecuted = false;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && processes[i].remaining > 0 && !addedToQueue[i]) {
                if (processes[i].priority == 1) {
                    queue1.push(&processes[i]);
                } else if (processes[i].priority == 2) {
                    queue2.push(&processes[i]);
                } else {
                    queue3.push(&processes[i]);
                }
                addedToQueue[i] = true;
            }
        }

        if (!queue1.empty()) {
            Process *current = queue1.front();
            queue1.pop();
            if (current->remaining <= quant1) {
                time += current->remaining;
                gantt.push_back(current->name);
                current->remaining = 0;
                current->completed = true;
                current->turnaround = time - current->arrival;
                current->waiting = current->turnaround - current->burst;
                completed++;
            } else {
                time += quant1;
                gantt.push_back(current->name);
                current->remaining -= quant1;
                queue2.push(current);
            }
            processExecuted = true;
        } else if (!queue2.empty()) {
            Process *current = queue2.front();
            queue2.pop();
            if (current->remaining <= quant2) {
                time += current->remaining;
                gantt.push_back(current->name);
                current->remaining = 0;
                current->completed = true;
                current->turnaround = time - current->arrival;
                current->waiting = current->turnaround - current->burst;
                completed++;
            } else {
                time += quant2;
                gantt.push_back(current->name);
                current->remaining -= quant2;
                queue3.push(current);
            }
            processExecuted = true;
        } else if (!queue3.empty()) {
            Process *current = queue3.front();
            queue3.pop();
            if (current->remaining <= quant3) {
                time += current->remaining;
                gantt.push_back(current->name);
                current->remaining = 0;
                current->completed = true;
                current->turnaround = time - current->arrival;
                current->waiting = current->turnaround - current->burst;
                completed++;
            } else {
                time += quant3;
                gantt.push_back(current->name);
                current->remaining -= quant3;
                queue3.push(current);
            }
            processExecuted = true;
        }

        if (!processExecuted) {
            time++;  // Increment time if no process is being executed
        }
    }

    displayGanttChart(gantt);
    displayTimes(processes);
}

int main() {
    vector<Process> processes = {
        Process("P1", 0, 10, 1),
        Process("P2", 1, 5, 2),
        Process("P3", 2, 8, 1),
        Process("P4", 3, 6, 3),
        Process("P5", 4, 2, 2)
    };

    int quant1 = 4, quant2 = 6, quant3 = 8;

    multilevelFeedbackQueue(processes, quant1, quant2, quant3);

    return 0;
}
