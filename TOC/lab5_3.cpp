#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PDA for L = { w w^R | w ∈ (a+b)* }
bool accepts_wwr(const string &s) {
    int n = s.size();
    if (n % 2 != 0) return false; // length must be even
    int mid = n / 2;

    stack<char> st;
    // Push first half onto stack
    for (int i = 0; i < mid; ++i) {
        st.push(s[i]);
    }

    // Compare second half with stack (reverse of first half)
    for (int i = mid; i < n; ++i) {
        if (st.empty() || s[i] != st.top())
            return false;
        st.pop();
    }

    return st.empty();
}

int main() {
    string s = "abba"; // hardcoded string

    cout << "Checking string: " << s << "\n";

    if (accepts_wwr(s)) {
        cout << "ACCEPTED: \"" << s << "\" belongs to {w w^R | w belongs to (a+b)*}\n";
    } else {
        cout << "REJECTED: \"" << s << "\" does not belong to {w w^R | w belongs to (a+b)*}\n";
    }

    return 0;
}
