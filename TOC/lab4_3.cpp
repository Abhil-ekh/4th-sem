#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Utility function to replace rightmost 'S' in the string with replacement
void replaceRightmostS(string &expr, const string &replacement) {
    int pos = expr.rfind('S');
    if (pos != string::npos) {
        expr.replace(pos, 1, replacement);
    }
}

// Function to print derivation steps for -(ID*ID)+ID
void rightmostDerivation() {
    vector<string> steps;
    string expr = "S";
    steps.push_back(expr);

    // Step 1: S -> S + S
    replaceRightmostS(expr, "S+S");
    steps.push_back(expr);

    // Step 2: Replace rightmost S with ID
    replaceRightmostS(expr, "ID");
    steps.push_back(expr);



    replaceRightmostS(expr, "-S");
    steps.push_back(expr);

    // expr is now "-S+ID"

    // Step 4: Replace rightmost S with (S)
    replaceRightmostS(expr, "(S)");
    steps.push_back(expr);

    // expr: "-(S)+ID"

    // Step 5: Replace rightmost S with S * S
    replaceRightmostS(expr, "S*S");
    steps.push_back(expr);

    // expr: "-(S*S)+ID"

    // Step 6: Replace rightmost S with ID
    replaceRightmostS(expr, "ID");
    steps.push_back(expr);

    // expr: "-(S*ID)+ID"

    // Step 7: Replace rightmost S with ID
    replaceRightmostS(expr, "ID");
    steps.push_back(expr);

    // expr: "-(ID*ID)+ID"

    // Print all derivation steps
    cout << "Rightmost derivation steps for the string '-(ID*ID)+ID':\n";
    for (int i = 0; i < steps.size(); i++) {
        cout << i + 1 << ": " << steps[i] << "\n";
    }
}

int main() {
    rightmostDerivation();
    return 0;
}
