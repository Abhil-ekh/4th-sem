//DFA THAT ACCEPTS STRING 1001

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string over {0,1}: ";
    cin >> input;

    int state = 0;  

    for (char c : input) {
        if (state == 0) {
            if (c == '1') state = 1;
            else state = -1;  
        }
        else if (state == 1) {
            if (c == '0') state = 2;
            else if (c == '1') state = 1;
            else {
                state = -1; 
                break;
            }
        }
        else if (state == 2) {
            if (c == '0') state = 3;
            else {
                state = -1;
                break;
            }
        }
        else if (state == 3) {
            if (c == '1') state = 4;
            else {
                state = -1;
                break;
            }
        }
        else if (state == 4) {
            state = -1;
            break;
        }
    }

    if (state == 4) {
        cout << "Accepted: The string is '1001'\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}
