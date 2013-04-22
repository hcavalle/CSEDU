#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//function prototypes
void assignInitialValues(string grid[][10], int size); /* where each square in the grid is randomly assigned the value "C" for cooperator or "D" for defector.*/

void iterate(string grid[][10], int size); /* where each square in the grid is modified according the rules provided above.*/

void calculateTime(string grid[][10], int size); //calculates the time done in an iteration and whether the prisoner switches from C to D, called within calculatetime()

string switchPrisoner(string); //switches a prisoner from c to d or d to c

double percentageOfCooperation(string grid[][10], int size);

void printPercentage(double percentage) {cout << "The percentage of cooperators is " << percentage << "%\n";}

void printGrid(string grid[][10], int size);

int main() {
	//Declare vars
	const int gridSize = 10;
	const int totalIterations = 10000;
	string prisonerGrid [gridSize][gridSize];
	double cooperatorPercentage;
	
	//seed rand vals
	srand(time(0));

	
	//initialize prisoner grid, call assignInitialValues(string grid[][10], int size);
	assignInitialValues(prisonerGrid, gridSize);
	printGrid(prisonerGrid, gridSize);
	
	//iterate through simulation, calculating time and switching prisoners
	for (int i = 0; i < 10000; i++){
		iterate(prisonerGrid, gridSize);
		cooperatorPercentage = percentageOfCooperation(prisonerGrid, gridSize);
		printPercentage(cooperatorPercentage);
		printGrid(prisonerGrid, gridSize);
	}

	//determine percentage of cooperators and print
	cooperatorPercentage = percentageOfCooperation(prisonerGrid, gridSize);
	printPercentage(cooperatorPercentage);

	//debug cin
	cin >> cooperatorPercentage;
}

//function definitions

void assignInitialValues(string grid[][10], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j <size; j++){
			if (rand() % 2 == 1){
				grid[i][j] = "C";
			}
			else{
				grid[i][j] = "D";
			}
		}
	}
}

void iterate(string grid[][10], int size){
	//calculate time for prisoners over x iterations
	for (int i = 0; i < 2; i++){
		calculateTime(grid, size); //calculates time done based on other prisoners surrounding choices, if more than 20, call switch prisoner.
	}

}
void calculateTime(string grid[][10], int size){
	int time = 0;
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j <size; j++){
			//cout<<"Current prisoner is: "<<grid[i][j]<<endl;
			//check if current prisoner is c and do c calc
			if(grid[i][j] == "C"){
				if(j < 9 && grid[i][j+1]== "C"){
					time += 5;
					//cout<<time<<endl;
				}
				else{
					time += 2;
					//cout<<time<<endl;
				}
				if(j > 0 && grid[i][j-1] == "C"){
					time += 5;
					//cout<<time<<endl;
				}
				else{
					time += 2; //end checking vertical matches
					//cout<<time<<endl;
				}
				if(i < 9 && grid[i+1][j] == "C"){
					time += 5;
					//cout<<time<<endl;
				}
				else{
					time += 2;
				}
				if(i > 0 && grid[i-1][j] == "C"){
					time += 5;
					//cout<<time<<endl;
				}
				else{
					time += 2;
					//cout<<time<<endl;
				}
			}//end if current prisoner is C

			//check if current prisoner is D and do d calc
			if(grid[i][j] == "D"){
				if(j < 9 && grid[i][j+1] == "C"){
					time += 10;
					//cout<<time<<endl;
				}
				else{
					time += 3;
					//cout<<time<<endl;
				}
				if(j > 0 && grid[i][j-1] == "C"){
					time += 10;
					//cout<<time<<endl;
				}
				else{
					time += 3;
					//cout<<time<<endl;
				}

				if(i < 9 && grid[i+1][j] == "C"){
					time += 10;
					//cout<<time<<endl;
				}
				else{
					time += 3;
					//cout<<time<<endl;
				}
				if(i > 0 && grid[i-1][j] == "C"){
					time += 10;
					//cout<<time<<endl;
				}
				else{
					time += 3;
					//cout<<time<<endl;
				}
			}//end if current prisoner is D
			if(time >= 20){
				grid[i][j] = switchPrisoner(grid[i][j]);
				//cout<<"Changed prisoner to: "<<grid[i][j]<<endl;
			}
			else{
				//cout<<"Prisoner didn't change"<<endl;
			}
			time = 0;
		}//end inner calculation for loop, done with one row of prisoners.
	}//end outer calculation loop, done with grid of prisoners.
}

string switchPrisoner(string prisoner){
	if(prisoner == "D"){
		return "C";
	}
	else{
		return "D";
	}
	return prisoner;
}

double percentageOfCooperation(string grid[][10], int size){
	double percent = 0.0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(grid[i][j] == "C"){
				percent++;
			}
		}
	}
	//cout<<"Percent is "<<percent<<endl;
	return (percent/size) * 10.00;
}

//debug funcs
void printGrid(string grid[][10], int size){	
	for(int i = 0; i < size; i++){
		cout<<"Row "<<i<<": ";
		for(int j = 0; j < size; j++){
			//string a = ;
			cout << " " <<	grid[i][j];
			}
		cout<<endl;
	}
}