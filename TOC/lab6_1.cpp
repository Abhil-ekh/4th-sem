#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PDA for L = { a^(2n) b^n | n >= 1 }
bool accepts_a2n_bn(const string &s) {
    stack<char> st;
    int i = 0;
    int countA = 0, countB = 0;

    // Count a's and push marker for each a
    while (i < s.size() && s[i] == 'a') {
        st.push('A');
        ++countA;
        ++i;
    }

    // Must have at least 2 a's (n>=1) and even number of a's
    if (countA < 2 || countA % 2 != 0) return false;

    // Match b's: each b pops **two a's**
    while (i < s.size() && s[i] == 'b') {
        if (st.size() < 2) return false; // not enough a's to pop
        st.pop();
        st.pop();
        ++countB;
        ++i;
    }

    // Must consume all input and stack empty
    if (i == s.size() && st.empty() && countB >= 1)
        return true;

    return false;
}

int main() {
    cout << "Enter a string to check for L = {a^(2n) b^n | n >= 1}: ";
    string s;
    cin >> s;

    if (accepts_a2n_bn(s)) {
        cout << "ACCEPTED: \"" << s << "\" belongs to L\n";
    } else {
        cout << "REJECTED: \"" << s << "\" does not belong to L\n";
    }

    return 0;
}
