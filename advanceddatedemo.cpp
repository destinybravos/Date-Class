#include <iostream>
#include "advanceddatedemo.h"

using namespace std;

int main(){
		
//	Using the Extended Date Class with Advanced Features.
//	First Instabtiate Different Objects of the class as myAdDate.
	aDate myDate1;
	aDate myDate2;
	aDate myDate3, myDate4, myDate5, myDate6, myDate7, myDate8;
	int DayDiff;
	
//	Set the First Date
	myDate1.setDate(12,31,2020);
	
//	Manipulate the rest days from the initialized first day
	myDate2 = myDate1 + 10;
	myDate3 = ++myDate2;
	myDate4 = myDate3++;
	myDate5 = myDate4 - 7;
	myDate6 = --myDate5;
	myDate7 = myDate5--;
	DayDiff = myDate7 - myDate1;
	
	
//	Output all the dates in fullDate format
	cout << myDate1.fullDate() << endl;
	cout << myDate2.fullDate() << endl;
	cout << myDate3.fullDate() << endl;
	cout << myDate4.fullDate() << endl;
	cout << myDate5.fullDate() << endl;
	cout << myDate6.fullDate() << endl;
	cout << myDate7.fullDate() << endl;
	cout << DayDiff << endl;
	
//	Testing the Input and Output Overload
	cout<< "\n\n Enter a date in the the following format: day month year \n(Numbers/Integer values only)!\n\n";
	cin >> myDate8;
	cout << "The date is " << myDate8.LongDate() << endl;
	
//  Adding No of Days to the date to check Month Spans
	int days;
	
	cout << "\n\n How many Days should I add to the previously displayed date?  \n(Numbers/Integer values only)!\n\n";
	cin >> days;
	myDate2 = myDate8 + days;
	cout << myDate8 << " plus " << days << " days is " << myDate2; 
	
	cout << "\n\nThank you for using the Date Class!\n";
	
}

