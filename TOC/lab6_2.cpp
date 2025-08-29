#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PDA for L = { a^n b^{2n} c^n | n >= 1 }
bool accepts_an_b2n_cn(const string &s) {
    stack<char> st;
    int i = 0;
    int countA = 0, countB = 0, countC = 0;

    // Step 1: read a's
    while (i < s.size() && s[i] == 'a') {
        st.push('A');  // push for each 'a'
        ++countA;
        ++i;
    }

    if (countA < 1) return false; // n >= 1

    // Step 2: read b's, pop one marker for every 2 b's
    while (i < s.size() && s[i] == 'b') {
        ++countB;
        ++i;
    }

    if (countB != 2 * countA) return false; // must have exactly 2n b's

    // Step 3: read c's, pop one marker for each
    while (i < s.size() && s[i] == 'c') {
        if (st.empty()) return false;
        st.pop();
        ++countC;
        ++i;
    }

    if (countC != countA) return false; // must have n c's

    // Accept if all input consumed and stack empty
    return (i == s.size() && st.empty());
}

int main() {
    cout << "Enter a string to check for L = {a^n b^{2n} c^n | n >= 1}: ";
    string s;
    cin >> s;

    if (accepts_an_b2n_cn(s)) {
        cout << "ACCEPTED: \"" << s << "\" belongs to L\n";
    } else {
        cout << "REJECTED: \"" << s << "\" does not belong to L\n";
    }

    return 0;
}
