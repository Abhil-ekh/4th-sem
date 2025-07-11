#include<iostream>
#include<string>
using namespace std;

int main(){
	string input;
	cout<<"Enter a string over {0,1}: ";
	cin>>input;
	int state = 0;
	for(char c:input){
		if (state==0) {
			if (c=='1')
				state=1;
		}
		else if (state==1) {
			if (c=='1')
				state=0;		
		}
	
	}	
	if(state==1)
		cout<<"Accepted";
	else
		cout<<"Rejected";

	return 0;
}