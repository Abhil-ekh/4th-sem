//DFA THAT ACCEPTS STRING THAT STARTS WITH "a" AND ENDS WITH "b"

#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	cout << "Enter a string over {a,b}: ";
    cin >> input;
    int state=0;
    for(char c:input) {
    	if (state == 0) {
            if (c == 'a') 
				state = 1;
            else 
				state = -1;  
        }
        else if (state == 1) {
            if (c == 'a') 
				state = 1;
            else if (c == 'b') 
				state = 2;
            else {
                state = -1; 
                break;
            }
        }
        else if (state == 2) {
            if (c == 'a') 
				state = 1;
			else if (c == 'b') 
				state = 2;
            else {
                state = -1;
                break;
            }
        }
        // else if (state == 3) {
        //     state = -1;
        //     break;
        // }
	}
	if (state == 2) {
        cout << "Accepted";
    } else {
        cout << "Rejected";
    }

    return 0;
}