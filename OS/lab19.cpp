#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    // ---------------- FCFS ----------------
    cout << "\n--- FCFS Disk Scheduling ---\n";
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;
    vector<int> req(n);
    cout << "Enter requests: ";
    for (int i = 0; i < n; i++) cin >> req[i];
    cout << "Enter head position: ";
    cin >> head;

    int total = 0;
    int prev = head;
    for (int i = 0; i < n; i++) {
        total += abs(prev - req[i]);
        prev = req[i];
    }
    cout << "Total head movement (FCFS): " << total << endl;

    // ---------------- SCAN ----------------
    cout << "\n--- SCAN Disk Scheduling ---\n";
    int size;
    cout << "Enter disk size: ";
    cin >> size;
    cout << "Enter number of requests: ";
    cin >> n;
    req.resize(n);
    cout << "Enter requests: ";
    for (int i = 0; i < n; i++) cin >> req[i];
    cout << "Enter head position: ";
    cin >> head;

    req.push_back(0);
    req.push_back(size - 1);
    sort(req.begin(), req.end());

    int idx = 0;
    for (int i = 0; i < req.size(); i++)
        if (req[i] >= head) { idx = i; break; }

    total = 0;
    prev = head;
    for (int i = idx; i < req.size(); i++) {
        total += abs(req[i] - prev);
        prev = req[i];
    }
    for (int i = idx - 1; i >= 0; i--) {
        total += abs(req[i] - prev);
        prev = req[i];
    }
    cout << "Total head movement (SCAN): " << total << endl;

    // ---------------- LOOK ----------------
    cout << "\n--- LOOK Disk Scheduling ---\n";
    cout << "Enter number of requests: ";
    cin >> n;
    req.resize(n);
    cout << "Enter requests: ";
    for (int i = 0; i < n; i++) cin >> req[i];
    cout << "Enter head position: ";
    cin >> head;

    sort(req.begin(), req.end());
    idx = 0;
    for (int i = 0; i < n; i++)
        if (req[i] >= head) { idx = i; break; }

    total = 0;
    prev = head;
    for (int i = idx; i < n; i++) {
        total += abs(req[i] - prev);
        prev = req[i];
    }
    for (int i = idx - 1; i >= 0; i--) {
        total += abs(req[i] - prev);
        prev = req[i];
    }
    cout << "Total head movement (LOOK): " << total << endl;

    return 0;
}
