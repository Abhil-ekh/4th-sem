#include <iostream>
#include <string>

using namespace std;

bool turingMachine(string tape) {
    int n = tape.size();
    int head = 0;

    while (true) {
        // Step 1: Find the first unmarked 'a'
        while (head < n && tape[head] != 'a') head++;
        if (head == n) break; // no more 'a's, move to final check

        // Mark 'a' as 'X'
        tape[head] = 'X';

        // Step 2: Find the first unmarked 'b' after this 'a'
        head++;
        while (head < n && tape[head] != 'b') head++;
        if (head == n) return false; // no matching 'b', reject

        // Mark 'b' as 'Y'
        tape[head] = 'Y';

        // Step 3: Move head back to the beginning
        head = 0;
    }

    // Step 4: Check if any unmarked 'b' remains
    for (char c : tape) {
        if (c == 'a' || c == 'b') return false; // unmatched symbol, reject
    }

    return true; // accept
}

int main() {
    string input;
    cout << "Enter a string over {a,b}: ";
    cin >> input;

    if (turingMachine(input)) {
        cout << "Accepted by TM!\n";
    } else {
        cout << "Rejected by TM!\n";
    }

    return 0;
}
