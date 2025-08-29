#include <iostream>
#include <string>
using namespace std;

string twosComplementTM(string tape) {
    int n = tape.size();
    int head = n - 1;

    // Step 1: Find the first '1' from right (least significant bit)
    while (head >= 0 && tape[head] != '1') {
        head--;
    }

    // If no '1' found, all zeros => 2's complement is same
    if (head < 0) return tape;

    // Step 2: Invert all bits to the left of this position
    for (int i = 0; i < head; i++) {
        tape[i] = (tape[i] == '0') ? '1' : '0';
    }

    return tape;
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;


    string result = twosComplementTM(input);
    cout << "2's complement = " << result << "\n";

    return 0;
}
