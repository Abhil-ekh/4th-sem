#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PDA for L = { w c w^r | w belongs_to (0*1)* }
bool accepts_wcwr(const string &s) {
    // must contain exactly one 'c'
    size_t cpos = s.find('c');
    if (cpos == string::npos || s.find('c', cpos + 1) != string::npos)
        return false;

    string w = s.substr(0, cpos);
    string wr = s.substr(cpos + 1);

    // Check: wr must be reverse of w
    string wrev = string(w.rbegin(), w.rend());
    if (wr != wrev) return false;

    // Now check if w ∈ (0*1)* : i.e. sequence of blocks like 0001, 01, 1, 001, etc.
    size_t i = 0;
    while (i < w.size()) {
        // zero or more 0s
        while (i < w.size() && w[i] == '0') i++;
        // must have a 1
        if (i >= w.size() || w[i] != '1') return false;
        i++; // consume the 1
    }
    return true;
}

int main() {
    string s = "11011";  // hardcoded string

    cout << "Checking string: " << s << "\n";

    if (accepts_wcwr(s)) {
        cout << "ACCEPTED: \"" << s << "\" belongs to {w c w^R | w belongs to (0*1)*}\n";
    } else {
        cout << "REJECTED: \"" << s << "\" does not belong to {w c w^R | w belongs to (0*1)*}\n";
    }

    return 0;
}
