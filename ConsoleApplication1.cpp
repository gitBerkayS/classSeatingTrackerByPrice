#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// a function to call the title.
void title() {
	cout << "-----------------------------" << endl;
	cout << setw(20) << right << "Course Seats" << endl;
	cout << "-----------------------------";
}

// a function if you need to call the options for the menu.
void menu(int& choice) {


	cout << "\nEnter 1 to reserve seat\n";
	cout << "2 to release seat\n";
	cout << "3 to exit.... ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "You must enter a valid menu number";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}
}

int main(){
	//initializing variables
	int total = 0, choice = 0, row = 0, columnreal;
	char column = ' ';

	// Creating a string array to store all the seat numbers.
	string course_seats[5][5] = {
	{"", "A","B", "C", "D"},
	{"1", "20","20", "20", "20"},
	{"2", "10","10", "10", "10"},
	{"3", "10","10", "10", "10"},
	{"4", "10","10", "10", "10"}
	};

	//printing the array
	title();
	for (int x = 0; x < 5; x++) {
		cout << endl;
		for (int y = 0; y < 5; y++) {
			cout << setw(5) << course_seats[x][y];
		}
	}
	

	cout << "\n\nYour total for now is: " << total << endl;
	cout << endl;

	//do while loop to repeat the menu items, and allow the program to function
	do {
		menu(choice);

		//if the user selects option number one on the menu
		if (choice == 1) {
			
			cout << "\nEnter a column letter ";
			//column converts recieved letter to a number, if it recieved anything that its not supposed to, it repeats the option untill user makes a valid selection.
			while ((column != 'A' && column != 'a' ) && ( column != 'B' && column != 'b' ) && ( column != 'C' && column != 'c' ) && ( column != 'D' && column != 'd')) {
				cin.clear();
				cin.ignore();
				cin >> column;


				if (column == 'A' || column == 'a') {
					columnreal = 1;
					break;
				}
				else if (column == 'B' || column == 'b') {
					columnreal = 2;
					break;
				}
				else if (column == 'C' || column == 'c') {
					columnreal = 3;
					break;
				}
				else if (column == 'D' || column == 'd') {
					columnreal = 4;
					break;
				}
				else {
					cout << "You must enter a valid column letter ";
					continue;
				}
			}

			
			cout << "Enter the row number ";
			cin >> row;
			//recieves a row number to access the array with.
			while (row != 1 && row != 2 && row != 3 && row != 4) {
				cout << "You must enter a valid row number ";
				cin.clear();
				cin.ignore();
				cin >> row;
			}

			//stores the price of the seats in a variable called total. if the seats are already reserved, the value of 0 will be added which wont affect the total.
			total += stoi(course_seats[row][columnreal]);

			// checking if the seats are already reserved. if its reserved the do while loop will reset.
			if (course_seats[row][columnreal] == "0") {
				cout << "Seat is already reserved .. Release it first.\n";

				title();
				for (int x = 0; x < 5; x++) {
					cout << endl;
					for (int y = 0; y < 5; y++) {
						cout << setw(5) << course_seats[x][y];
					}
				}
				cout << "\n\nYour total for now is: " << total << endl;
				continue;
			}
			//if the seats are not reserved, this is where we mark them as reserved.
			course_seats[row][columnreal] = "0";

			title();
			for (int x = 0; x < 5; x++) {
				cout << endl;
				for (int y = 0; y < 5; y++) {
					cout << setw(5) << course_seats[x][y];
				}
			}

			cout << "\n\nYour total for now is: " << total << endl;

		}
		//if the menu choice is 2...
		else if (choice == 2) {

			//same thing as menu option one...column converts recieved letter to a number, if it recieved anything that its not supposed to, it repeats the option untill user makes a valid selection.
			cout << "\nEnter a column letter ";
			while ((column != 'A' && column != 'a') || (column != 'B' && column != 'b') || (column != 'C' && column != 'c') || (column != 'D' && column != 'd')) {
				cin.clear();
				cin.ignore();
				cin >> column;


				if (column == 'A' || column == 'a') {
					columnreal = 1;
					break;
				}
				else if (column == 'B' || column == 'b') {
					columnreal = 2;
					break;
				}
				else if (column == 'C' || column == 'c') {
					columnreal = 3;
					break;
				}
				else if (column == 'D' || column == 'd') {
					columnreal = 4;
					break;
				}
				else {
					cout << "You must enter a valid column letter ";
					continue;
				}
			}

			//same thing as menu 1... recieves a row number to access the array with.
			cout << "Enter the row number ";
			cin >> row;
			while (row != 1 && row != 2 && row != 3 && row != 4) {
				cout << "You must enter a valid row number ";
				cin.clear();
				cin.ignore();
				cin >> row;
			}

			//if selected row and column is not 0 then that means the seat is not sold out so we cannot release it. the do while loop restarts.
			if(course_seats[row][columnreal] != "0") {
				cout << "\nSeat is not sold yet...\n";

				title();
				for (int x = 0; x < 5; x++) {
					cout << endl;
					for (int y = 0; y < 5; y++) {
						cout << setw(5) << course_seats[x][y];
					}
				}
				cout << "\n\nYour total for now is: " << total << endl;
				continue;
			}

			//if the spot is already sold...
			else {
				//check if row is 1 or greater than one. row = 1 means price was $20
				if (row == 1) {
					course_seats[row][columnreal] = "20";
					total -= 20;
				}
				//row is > 1 means price is $10
				else if (row > 1) {
					course_seats[row][columnreal] = "10";
					total -= 10;
				}

				else {
					//checking for bugs/glitches
					cout << "Error... Ending program. Hint: Row is less than 1";
				}

				title();
				for (int x = 0; x < 5; x++) {
					cout << endl;
					for (int y = 0; y < 5; y++) {
						cout << setw(5) << course_seats[x][y];
					}
				}
				cout << "\n\nYour total for now is: " << total << endl;
			}

		}
		//if menu option is 3.. then we end the program.
	} while (choice != 3);
	
	
	cout << "Thank you for using this service.. Ending program now. Have a good day.\n\n\n\n";
}