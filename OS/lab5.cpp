//lab5
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int pid;        // process ID
    int bt;         // burst time
    int at;         // arrival time
    int priority;   // priority
    int wt;         // waiting time
    int tat;        // turnaround time
};

// Function to calculate TAT and WT, and print Gantt chart
void calculateTimes(Process p[], int n) {
    int totalWT = 0, totalTAT = 0;
    cout << "\nPID\tBT\tAT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at 
             << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
    }
    cout << "Average Waiting Time = " << (float)totalWT / n << endl;
    cout << "Average Turnaround Time = " << (float)totalTAT / n << endl;
}

// Function to print the Gantt Chart
void printGanttChart(vector<int> gantt, vector<int> times) {
    cout << "\nGantt Chart: \n";

    // Print the process bars
    for (int i = 0; i < gantt.size(); i++) {
        cout << "| P" << gantt[i] << " ";
    }
    cout << "|\n";

    // Print the time markers
    for (int i = 0; i < times.size(); i++) {
        cout << times[i] << "    ";
    }
    cout << "\b" << times.back() << "\n"; // Remove one more space before the last completion time
}

// FCFS Scheduling
void fcfs(Process p[], int n) {
    cout << "\n--- FCFS Scheduling ---\n";
    int currentTime = 0;
    vector<int> gantt; // to store the process execution order
    vector<int> times; // to store the time markers for Gantt chart

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
        gantt.push_back(p[i].pid);
        times.push_back(currentTime); // store the end time for Gantt chart
    }

    printGanttChart(gantt, times);
    calculateTimes(p, n);
}

// SJF Scheduling (non-preemptive)
void sjf(Process p[], int n) {
    cout << "\n--- SJF Scheduling ---\n";
    // Sort by burst time (if equal, by arrival time)
    sort(p, p + n, [](Process a, Process b) {
        if (a.bt == b.bt) return a.at < b.at;
        return a.bt < b.bt;
    });

    int currentTime = 0;
    vector<int> gantt; // to store the process execution order
    vector<int> times; // to store the time markers for Gantt chart

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
        gantt.push_back(p[i].pid);
        times.push_back(currentTime); // store the end time for Gantt chart
    }

    printGanttChart(gantt, times);
    calculateTimes(p, n);
}

// Priority Scheduling (non-preemptive)
void priorityScheduling(Process p[], int n) {
    cout << "\n--- Priority Scheduling ---\n";
    // Sort by priority (lower value = higher priority)
    sort(p, p + n, [](Process a, Process b) {
        if (a.priority == b.priority) return a.at < b.at;
        return a.priority < b.priority;
    });

    int currentTime = 0;
    vector<int> gantt; // to store the process execution order
    vector<int> times; // to store the time markers for Gantt chart

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
        gantt.push_back(p[i].pid);
        times.push_back(currentTime); // store the end time for Gantt chart
    }

    printGanttChart(gantt, times);
    calculateTimes(p, n);
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[20];

    cout << "\nEnter the details for each process (PID, Burst Time, Arrival Time, Priority):\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Process " << i + 1 << " (PID, Burst Time, Arrival Time, Priority): ";
        cin >> p[i].pid >> p[i].bt >> p[i].at >> p[i].priority;
    }

    // Run the different scheduling algorithms
    fcfs(p, n);
    sjf(p, n);
    priorityScheduling(p, n);

    return 0;
}
