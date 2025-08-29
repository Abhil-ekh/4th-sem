#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to remove immediate left recursion for a given production
void removeLeftRecursion(const string &nonTerminal, const vector<string> &productions) {
    vector<string> alpha;  // Left recursive parts (A -> Aα)
    vector<string> beta;   // Non-left recursive parts (A -> β)

    // Separate α and β
    for (auto &prod : productions) {
        if (prod[0] == nonTerminal[0]) {
            // Left recursive production: A -> Aα
            alpha.push_back(prod.substr(1)); 
        } else {
            // Non-left recursive production: A -> β
            beta.push_back(prod);
        }
    }

    // If no left recursion
    if (alpha.empty()) {
        cout << nonTerminal << " -> ";
        for (int i = 0; i < productions.size(); i++) {
            cout << productions[i];
            if (i != productions.size() - 1) cout << " | ";
        }
        cout << endl;
        return;
    }

    // Create new non-terminal A'
    string newNonTerminal = nonTerminal + "'";

    // Print A -> βA'
    cout << nonTerminal << " -> ";
    for (int i = 0; i < beta.size(); i++) {
        cout << beta[i] << newNonTerminal;
        if (i != beta.size() - 1) cout << " | ";
    }
    cout << endl;

    // Print A' -> αA' | ε
    cout << newNonTerminal << " -> ";
    for (int i = 0; i < alpha.size(); i++) {
        cout << alpha[i] << newNonTerminal << " | ";
    }
    cout << "E" << endl;
}

int main() {
    // Example grammar T -> T*F | F
    string nonTerminal = "T";
    vector<string> productions = {"T*F", "F"};

    cout << "Removing left recursion for: " << nonTerminal << endl;
    removeLeftRecursion(nonTerminal, productions);

    return 0;
}
