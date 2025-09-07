#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ------------------ Sequential File Allocation ------------------
    cout << "\n--- Sequential File Allocation ---\n";
    int n;
    cout << "Enter total blocks: ";
    cin >> n;
    vector<int> blocks(n, 0);

    int start, len;
    cout << "Enter starting block and length: ";
    cin >> start >> len;

    if (start + len > n) {
        cout << "Allocation not possible\n";
    } else {
        for (int i = start; i < start + len; i++)
            blocks[i] = 1;
        cout << "Blocks allocated from " << start << " to " << start + len - 1 << endl;
    }

    // ------------------ Indexed File Allocation ------------------
    cout << "\n--- Indexed File Allocation ---\n";
    cout << "Enter total blocks: ";
    cin >> n;
    blocks.assign(n, 0);

    int indexBlock, count;
    cout << "Enter index block: ";
    cin >> indexBlock;
    cout << "Enter number of blocks to allocate: ";
    cin >> count;

    vector<int> allocated(count);
    cout << "Enter block numbers: ";
    for (int i = 0; i < count; i++) {
        cin >> allocated[i];
        if (allocated[i] < n)
            blocks[allocated[i]] = 1;
    }

    cout << "Index Block: " << indexBlock << "\nBlocks: ";
    for (int b : allocated) cout << b << " ";
    cout << endl;

    // ------------------ Linked File Allocation ------------------
    cout << "\n--- Linked File Allocation ---\n";
    cout << "Enter number of blocks: ";
    cin >> n;
    vector<int> next(n, -1);

    cout << "Enter start block and length: ";
    cin >> start >> len;

    int prev = start;
    cout << "Enter " << len - 1 << " block numbers: ";
    for (int i = 1; i < len; i++) {
        int blk;
        cin >> blk;
        next[prev] = blk;
        prev = blk;
    }

    cout << "File blocks linked starting from " << start << endl;

    return 0;
}
