#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of memory blocks: ";
    cin >> n;
    vector<int> block(n);
    cout << "Enter sizes of blocks: ";
    for (int i = 0; i < n; i++) cin >> block[i];

    cout << "Enter number of processes: ";
    cin >> m;
    vector<int> process(m);
    cout << "Enter sizes of processes: ";
    for (int i = 0; i < m; i++) cin >> process[i];

    vector<bool> allocated(n, false); // Track if a block is already used

    cout << "\nWORST FIT Allocation:\n";
    for (int i = 0; i < m; i++) {
        int worstIdx = -1;

        for (int j = 0; j < n; j++) {
            if (!allocated[j] && block[j] >= process[i]) {
                if (worstIdx == -1 || block[j] > block[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            cout << "Process " << i + 1 << " allocated to Block " << worstIdx + 1 << endl;
            allocated[worstIdx] = true; // Mark as used
        } else {
            cout << "Process " << i + 1 << " not allocated\n";
        }
    }

    return 0;
}
