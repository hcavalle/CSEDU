#include <iostream>
#include <cstdlib>
using namespace std;

//function prototypes
int cycleHigh(int, int);
int cycleCount(long long);
long long oddOrEven(long long);

int main(){
	//declare vars
	int startNum = 0;
	int endNum = 0;
	
	while (true) {
	cout << "Start: ";
	cin >> startNum;  
	
	if (startNum < 0){
		break;
	}
	cout << "End: ";
	cin >> endNum;
	cout << "Max: "<< cycleHigh(startNum, endNum)<<endl<<endl;
	}
	return 0;
} //end main

//takes start and end, calls cycleCount for each number in base sequence, determines highest. 
int cycleHigh(int start, int end){
	int highCount = 0;
	int count = 0;
	for (int i = start; i <= end; i++){
		//cout<<"Cycle for:"<<i<<endl;
		count = cycleCount(i);
		if (count > highCount){
			highCount = count;
			cout<<"Current number is: " << i << endl;
			//cout<<"High is:"<<highCount<<endl;	
		}
	}//end cycle
	return highCount;
}

//takes current internal number, calls oddOrEven until current internal number is 1
int cycleCount(long long internalNumber){
	int internalCount = 1; //starts at 1 to include seeding number
	while(internalNumber != 1){
		internalNumber = oddOrEven(internalNumber);
		//cout<<internalNumber<<endl;
		internalCount ++;
	}
	return internalCount; //return cycle count for current base number
}
//takes current cycleNumber determines odd or even, does corresponding calc, returns next number in sequence 
long long oddOrEven(long long number){
	if (number %2 == 0){
		number /= 2;
	}
	else {
		 number = number * 3 +1;
	}
	return number; //returns next number in the internal sequence cycle
}