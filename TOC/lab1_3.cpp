// dfa that accepts 10, 01, 001, 110

#include<iostream>
#include<string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string over {0,1}: ";
    cin >> input;
    int state=0;
    for(char c:input) {
        if (state == 0) {
            if (c == '0') 
				state = 2;
            else 
				state = 1;  
        }
        else if (state == 1) {
            if (c == '0') 
				state = 3;
            else 
				state = 4;
        }
        else if (state == 2) {
            if (c == '0') 
				state = 5;
            else 
				state = 3;
        }
        else if (state == 3) {
            if (c == '0' || c == '1') 
				state = -1;
        }
        else if (state == 4) {
            if (c == '0') 
				state = 3;
            else 
				state = 6;
        }
        else if (state == 5) {
            if (c == '0') 
				state = 6;
            else 
				state = 3;
        }
        else if (state == 6) {
            state = -1;
            break;
        }
    }
    if (state == 3) 
        cout << "Accepted";
    else 
        cout << "Rejected";

    return 0;
}