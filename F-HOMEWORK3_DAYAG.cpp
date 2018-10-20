// PROGRAM CREATED BY:
// EDRIEL ANTHONY C. DAYAG
// BSITAGD X01

#include <iostream>
#include <unistd.h>
using namespace std;

int error(){
	cout << "You have entered an invalid date. Please follow the format." << endl;
	cout << "Please try again. Restarting the program in 3 seconds...";
	sleep(3);
	system("CLS");
}

int main(){
	int day, month, year;
	
	cout << "This program reads your input date and compute its immediate successor." << endl << endl;
	cout << "Format: YYYY-MM-DD (i.e. 1999-02-18 = February 18, 1999). Add 0 in the beginning for single digit inputs." << endl;
	cout << "Enter the year [YYYY]: ";
	cin >> year;
	cout << "Enter the month [MM]: ";
	cin >> month;
	cout << "Enter the day [DD]: ";
	cin >> day;
	
	if(year == 0 || month == 0 || day == 0){ // ERROR FILTER
		error();
		main();
	} else if(month == 02 && year % 4 == 0){ // LEAP YEAR MODIFIER
		if(year % 100 == 0){ // IF IT'S DIVISIBLE BY 100, IT SHOULD BE DIVISBLE BY 400 TOO
			if(year % 400 == 0){
				cout << endl << "It's a leap year!" << endl;
				switch(day){
					case 1 ... 28:
						day++;
						break;
					case 29:
						month++;
						day = 01;
						break;
					default:
						error();
						main();
						break;
				}
			} else { // NON-LEAP YEAR
				switch(day){
					case 1 ... 27:
						day++;
						break;
					case 28:
						month++;
						day = 01;
						break;
					default:
						error();
						main();
						break;
				}
			}
		} else { // LEAP YEAR IF IT'S NOT DIVISIBLE BY 100
			cout << endl << "It's a leap year!" << endl;
			switch(day){
				case 1 ... 28:
					day++;
					break;
				case 29:
					month++;
					day = 01;
					break;
				default:
					error();
					main();
					break;
			}
		}
	} else if(month == 02){ // NON-LEAP YEAR
		switch(day){
			case 1 ... 27:
				day++;
				break;
			case 28:
				month++;
				day = 01;
				break;
		}
	} else if(month == 12){ // DECEMBER LAST DAY
		switch(day){
			case 1 ... 30:
				day++;
				break;
			case 31:
				year++;
				month = 01;
				day = 01;
				break;
			default:
				error();
				main();
				break;
		}
	} else if(day >= 1 && day <= 30){ // DAY+1 FOR MONTHS WITH 31 DAYS, MONTH+1 FOR MONTHS WITH 30 DAYS
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10:
				day++;
				break;
			case 4: case 6: case 9: case 11:
				month++;
				day = 01;
				break;
			default:
				error();
				main();
				break;
		}
	} else if(day == 31){ // 31ST DAY FOR EACH MONTH
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10:
				month++;
				day = 01;
				break;
			case 4: case 6: case 9: case 11:
				error();
				main();
				break;
			default:
				error();
				main();
				break;
		}
	} else { // FALLBACK ERROR
		error();
		main();
	}
	
	cout << "The next day would be " << year << "-" << month << "-" << day << " [YYYY-MM-DD].";
}
