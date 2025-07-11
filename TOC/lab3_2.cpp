#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int state = 0;    
    int output = 0;   

    for (int i = 0; i < input.length(); ++i) {
        char c = input[i];

        output = 0; 

        if (state == 0)
            state = (c == 'a') ? 1 : 0;
        else if (state == 1)
            state = (c == 'b') ? 2 : 0;
        else if (state == 2)
            state = (c == 'b') ? 3 : 0;
        else if (state == 3)
            state = (c == 'a') ? 4 : 0;
        else if (state == 4) {
            state = (c == 'a') ? 5 : 0;
            output = (c == 'a') ? 1 : 0;  
        }
        else if (state == 5) 
            output = 1;
    }

    cout << ((output == 1 && input.length() == 5) ?
             "String ACCEPTED by Mealy machine (matched 'abbaa').\n" :
             "String REJECTED by Mealy machine.\n");

    return 0;
}
