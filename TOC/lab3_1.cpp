#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int state = 0; 

    for (int i = 0; i < input.length(); ++i) {
        char c = input[i];

        if (state == 0)
            state = (c == 'a') ? 1 : 0;
        else if (state == 1)
            state = (c == 'b') ? 2 : ((c == 'a') ? 1 : 0);
        else if (state == 2)
            state = (c == 'a') ? 3 : ((c == 'a') ? 1 : 0);
        else if (state == 3)
            state = (c == 'b') ? 4 : ((c == 'a') ? 1 : 0);
        else if (state == 4)
            state = (c == 'a') ? 5 : ((c == 'a') ? 1 : 0);
        else if (state == 5)
            state = 5; 
    }

    if (state == 5 && input.length() == 5)
        cout << "Accepted";
    else
        cout << "Rejected";

    return 0;
}
