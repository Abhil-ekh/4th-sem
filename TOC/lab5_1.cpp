#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PDA for L = { a^n b^n | n >= 1 }
bool accepts_an_bn(const string &s) {
    if (s.empty()) return false;
    stack<char> st;
    bool seenB = false;
    int countA = 0, countB = 0;

    for (char c : s) {
        if (c == 'a') {
            if (seenB) return false; // 'a' after 'b' not allowed
            st.push('A');
            ++countA;
        } else if (c == 'b') {
            seenB = true;
            if (st.empty()) return false; // more b's than a's
            st.pop();
            ++countB;
        } else {
            return false; // invalid char
        }
    }

    return (countA >= 1 && countB >= 1 && st.empty());
}

int main() {
    string s = "aaaabbbb";   // hardcoded string to check

    cout << "Checking string: " << s << "\n";

    if (accepts_an_bn(s)) {
        cout << "ACCEPTED: \"" << s << "\" belongs to {a^n b^n | n>=1}\n";
    } else {
        cout << "REJECTED: \"" << s << "\" does not belong to {a^n b^n | n>=1}\n";
    }

    return 0;
}
