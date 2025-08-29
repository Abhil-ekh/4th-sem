#include <iostream>
#include <string>

using namespace std;

bool evenPalindromeTM(string tape) {
    int n = tape.size();
    if (n % 2 != 0) return false; // odd length, reject

    int head = 0;

    while (true) {
        // Step 1: Find first unmarked symbol from left
        while (head < n && tape[head] == 'X') head++;
        if (head == n) break; // all symbols marked, accept

        char leftChar = tape[head];
        tape[head] = 'X'; // mark it
        int right = n - 1;

        // Step 2: Find last unmarked symbol from right
        while (right >= 0 && tape[right] == 'X') right--;

        // If mismatch, reject
        if (tape[right] != leftChar) return false;

        // Mark the right symbol
        tape[right] = 'X';

        // Reset head to start for next iteration
        head = 0;
    }

    return true; // all matched
}

int main() {
    string input;
    cout << "Enter a string over {a,b}: ";
    cin >> input;

    if (evenPalindromeTM(input)) {
        cout << "Accepted by TM!\n";
    } else {
        cout << "Rejected by TM!\n";
    }

    return 0;
}
