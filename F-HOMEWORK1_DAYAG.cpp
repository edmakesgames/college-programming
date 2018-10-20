// PROGRAM CREATED BY:
// EDRIEL ANTHONY C. DAYAG
// BSITAGD X01

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	float side1, side2, area;
	float a, b, c;
	float missingside;
	float finalside1, finalside2, finalhyp;
	string unit, side1hyp, side2hyp;
	
	cout << "\t\t\tRight Triangle Side Finder and Area Calculator" << endl << endl;
	
	cout << "This program finds the missing side of a RIGHT Triangle using the Pythagorean Theorem." << endl;
	cout << "You just need to input the first 2 sides of the triangle." << endl;
	cout << "After finding the missing side, the program will then proceed to calculate its area." << endl << endl;
	cout << "IMPORTANT: This only works for RIGHT Triangles." << endl << endl;
	
	// Knowing the first side given by the user and finding if it's the hypotenuse
	cout << "Please enter the first side of the right triangle: ";
	cin >> side1;
	cout << "Is this the hypotenuse? (yes or no)" << endl;
	cin >> side1hyp;
	cout << endl;
	
	while(side1hyp != "yes" && side1hyp != "no"){
		cout << "You have entered an invalid input. Please only answer yes or no." << endl;
		cout << "Is this the hypotenuse? (yes or no)" << endl;
		cin >> side1hyp;
		cout << endl;
	}
	
	if(side1hyp == "yes"){
		c = side1;
		a = 0;
	} else {
		a = side1;
	}
	
	// Knowing the second side given by the user and finding if it's the hypotenuse
	cout << "Please enter the second side of the right triangle: ";
	cin >> side2;
	
	// Conditional statement to avoid asking for 2 hypotenuses
	if(side1hyp == "yes"){
		b = side2;
		side2hyp = "no";
		cout << endl;
	} else {
		cout << "Is this the hypotenuse? (yes or no)" << endl;
		cin >> side2hyp;
		cout << endl;
		// Loop for invalid answers
		while(side2hyp != "yes" && side2hyp != "no"){
			cout << "You have entered an invalid input. Please only answer yes or no." << endl;
			cout << "Is this the hypotenuse? (yes or no)" << endl;
			cin >> side2hyp;
			cout << endl;
		}
		
		if(side2hyp == "yes"){
			c = side2;
			b = 0;
		} else {
			b = side2;
		}
	}
	
	// Acquiring the measurement for later use
	cout << "What is the unit of measurement used? (Choose between mm, cm, or m only)" << endl;
	cin >> unit;
	cout << endl;
	while(unit != "cm" && unit != "mm"){
		cout << "You have entered an invalid type of measurement. Please choose between mm, cm, or m only." << endl;
		cout << "What is the unit of measurement used?" << endl;
		cin >> unit;
		cout << endl;
	}
	
	// Finding the missing side using the Pythagorean Theorem
	if(c == 0){
		cout << "The missing side is the hypotenuse." << endl;
		missingside = hypot (a, b); // cmath function: hypot
		cout << "It is equal to " << missingside << unit << "." << endl;
		cout << endl;
		// Value assignment for finding the area
		finalside1 = a;	
		finalside2 = b;
	} else {
		if(a == 0){
			cout << "The missing side is one of the base sides." << endl;
			b = pow (b, 2.0); // cmath function: pow
			c = pow (c, 2.0); // cmath function: pow
			a = c - b;
			missingside = sqrt (a); // cmath function: sqrt
			cout << "It is equal to " << missingside << unit << "." << endl;
			cout << endl;
			// Value assignment for finding the area
			finalside1 = missingside;
			finalside2 = sqrt (b); // cmath function: sqrt
		} else {
			if(b == 0){
				cout << "The misside side is one of the base sides." << endl;
				a = pow (a, 2.0); // cmath function: pow
				c = pow (c, 2.0); // cmath function: pow
				b = c - a;
				missingside = sqrt (b); // cmath function: sqrt
				cout << "It is equal to " << missingside << unit << "." << endl;
				cout << endl;
				// Value assignment for finding the area
				finalside1 = sqrt (a); // cmath function: sqrt
				finalside2 = missingside;
			} else {
				cout << "The program cannot find the missing side because you have entered an invalid input. Please try again.";
				return 0;
			}
		}
	}
	
	area = finalside1 * finalside2 / 2;
	cout << "The area of the right triangle is " << area << " square " << unit << "." << endl;
}
