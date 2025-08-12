#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Transition {
    int from, to;
    string symbol;
};

int main() {
    // DFA with states q0 to q4 (0 to 4)
    int states = 5;
    int startState = 0;
    int finalState = 4;

    vector<Transition> transitions = {
        {0, 1, "1"},
        {1, 2, "0"},
        {2, 3, "0"},
        {3, 4, "1"}
    };

    cout << "DFA Transitions:\n";
    for (const auto& t : transitions) {
        cout << "q" << t.from << " --" << t.symbol << "--> q" << t.to << endl;
    }

    cout << "\nSince the DFA accepts only one specific string, the regular expression is simply:\n";
    cout << "\nRegular Expression: 1001" << endl;

    return 0;
}
