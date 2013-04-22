// Project2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
using namespace std;

//declare consts
const double baseRate = 602.50;
const double discBaseRate = 400.00; //age discount base rate
const double each100Miles = 0.152;	
const int ageDiscountCeil = 71;
const int ageDiscountFloor = 42;
const int violationNumDiscount = 2; //must be LESS than this value
const double goodStudentRate = .05; //will be subtracted
const double noViolationsRate = .1235; //each 100 miles is set to this if #ofviolations less than violationsNumDiscount

double calcRate(int age, char goodStudent, int violations, double milesDriven){
	double rate = 0;
	double studentDisc = 0;
	//Age discount
	if (age < 71 && age > 42 && violations < violationNumDiscount){
		rate = discBaseRate;
		return rate;
	}

	//Student discount
	if (goodStudent == 'y' && age < 35){
		studentDisc = .05 * (baseRate + each100Miles * milesDriven);
	}

	//Violation Discount
	if (violations < violationNumDiscount){
		rate = (baseRate + noViolationsRate * milesDriven) - studentDisc;
		return rate;
	}

	rate = (baseRate + each100Miles * milesDriven) - studentDisc;
	return rate;
}

int _tmain(int argc, _TCHAR* argv[])
{


	//declare vars
	int age;
	char goodStudent;
	int violations;
	double milesDriven;
	double rate = 0.00;

	//get user input
	cout<<"Age of driver: ";
	cin>>age;
	cout<<"Good student? (y/n):";
	cin>>goodStudent;
	cout<<"Number of tickets:";
	cin>>violations;
	cout<<"Miles per week driven:";
	cin>>milesDriven;

	//
	rate = calcRate(age, goodStudent, violations, milesDriven);
	cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
	cout << "The rate is $"<<rate;
	cin >> age;

	return 0;
}

