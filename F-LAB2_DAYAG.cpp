// PROGRAM CREATED BY:
// EDRIEL ANTHONY C. DAYAG
// BSITAGD X01

#include <iostream>
using namespace std;

int main(){
	
	int amount, money;
	string answer;
	
	cout << "This program displays the name of the individual found in a specific banknote (Philippine Currency)." << endl;
	cout << "This includes bills (1000, 500, 200, 100, 50, 20) and coins (10, 5, 1)" << endl;
	cout << "Format: Enter only the amount (i.e. 1000, 500, 10, 5)." << endl;
	cout << "\nPlease enter the denomation of the banknote: ";
	cin >> amount;
	cout << endl;
	
	while(amount != 1 && amount % 5 != 0){
		cout << "Invalid amount. Please enter a valid denomination of a banknote." << endl;
		cout << "Please enter the denomation of the banknote: ";
		cin >> amount;
		cout << endl;
	}
	
	cout << "Is it a bill/coin, or centavo?" << endl;
	cin >> answer;
	cout << endl;

	if (answer == "bill" || answer == "coin" || answer == "bill/coin"){
		money = amount;
	} else {
		if(answer == "centavo"){
			cout << "You cannot find a person in a centavo. Only three stars and a sun.";
		} else {
			cout << "You have entered an invalid input. Please follow the format.";
		}
	}

	switch(money){
		case 1:
			cout << "The person that appears in a " << money << "-peso coin is Jose Rizal." << endl;
			break;
		case 5:
			cout << "The person that appears in " << money << "-peso coin Andres Bonifacio." << endl;
			break;
		case 10:
			cout << "The person that appears in " << money << "-peso coin Apolinario Mabini." << endl;
			break;
		case 20:
			cout << "The person that appears in " << money << " PHP is Manuel L. Quezon" << endl;
			break;
		case 50:
			cout << "The person that appears in " << money << " PHP is Sergio Osmeña." << endl;
			break;
		case 100:
			cout << "The person that appears in " << money << " PHP is Manuel A. Roxas." << endl;
			break;
		case 200:
			cout << "The person that appears in " << money << " PHP is Diosdado P. Macapagal" << endl;
			break;
		case 500:
			cout << "The people that can be found in " << money << " PHP are Corazon C. Aquino and Benigno S. Aquino Jr." << endl;
			break;
		case 1000:
			cout << "The people that can be found in " << money << " PHP are Jose Abad Santos, Vicente Lim, and Josefa Llanes Escoda." << endl;
			break;
		default:
			cout << "Invalid input.";
	}

}
