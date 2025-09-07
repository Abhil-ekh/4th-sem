#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resource types: ";
    cin >> m;
    vector<vector<int>> maxNeed(n, vector<int>(m));
    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);
    cout << "\nEnter MAX matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxNeed[i][j];
    cout << "\nEnter ALLOCATION matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];
    cout << "\nEnter AVAILABLE resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxNeed[i][j] - alloc[i][j];
    vector<int> work = avail;
    vector<bool> finish(n, false);
    vector<int> safeSequence;
    cout << "\nCalculating Safe Sequence...\n";
    for (int count = 0; count < n; count++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }
    bool safe = true;
    for (bool f : finish)
        if (!f)
            safe = false;
    if (safe) {
        cout << "\nSystem is in a SAFE state.\nSafe Sequence: ";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << safeSequence[i];
            if (i != n - 1)
                cout << " -> ";
        }
        cout << endl;
    }
    else
        cout << "\nSystem is NOT in a safe state.\n";
    return 0;
}