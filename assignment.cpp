#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>

using namespace std;

/// Github Upload Test
// initializing functions
void menu();
bool isNumber(string);
void input(int*, int);
int pass_by_value(int, int);
void sort_order();
void pass_by_address(int*, int);



int main()
{
	// Initializing variables
	const int size = 10;
	const bool cond = true;
	int i, j, original, arr[size], des_arr[size];
	string choice, order_choice, cont;
	
	// Allow user to keep using the program until they close it manually
	while (cond) {
		// Menu function
		menu();
		// buffer
		getline(cin >> ws, choice);


		// Check if input is number and contains white space
		while (isNumber(choice) == false) {

			cout << "You have entered a non-integer! Please try again\nEnter your choice : ";
			getline(cin >> ws, choice);
		}

		// Input validation
		while (choice != "1" && choice != "2" && choice != "3") {

			cout << "Please Enter 1, 2 or 3 :3";
			cout << "\nEnter your choice : ";
			getline(cin >> ws, choice);

			while (isNumber(choice) == false) {
				cout << "You have entered a non-integer! Please try again\nEnter your choice : ";
				getline(cin >> ws, choice);
			}
		}


		// Pass-by-value
		if (choice == "1") {

			// Input values and store in array
			input(arr, size);

			for (i = 0; i < size - 1; i++) {
				for (j = 0;j < size - i - 1;j++) { // 3 1
					if (arr[j] > arr[j + 1]) {
						original = arr[j];
						arr[j] = pass_by_value(arr[j], arr[j + 1]); // smaller
						arr[j + 1] = original; // bigger
					}
				}
			}

		}

		// Pass-by-address
		else if (choice == "2") {

			// Input values and store in array
			input(arr, size);

			// Function call
			pass_by_address(arr, size);

		}

		// Quits Program
		else
		{
			cout << "\nThanks for using our program <3\n\n";
			exit(0);
		}

		// Ascending/ Descending Input
		sort_order();
		getline(cin >> ws, order_choice);

		// Input Validation
		while (order_choice != "1" && order_choice != "2") {
			cout << "Not 1 or 2! Please try again\nEnter your choice : ";
			getline(cin >> ws, order_choice);
		}

		// Ascending Sort
		if (order_choice == "1") {
			cout << "\nsorting array using bubble sort....\n\n";

			for (i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
		}

		// Descending Sort
		else {
			cout << "\nsorting array using bubble sort....\n\n";

			for (i = 0; i < size; i++) {
				des_arr[i] = arr[size - 1 - i];
				cout << des_arr[i] << " ";
			}
		}

		// Prompts the user for continuing
		cout << "\n\nWish to continue (Y/N) ? ";
		getline(cin >> ws, cont);

		// Input validation
		while (cont != "Y" && cont != "N" && cont != "y" && cont != "n") {
			cout << "Please enter Y or N : ";
			getline(cin >> ws, cont);
		}

		if (cont == "Y" || cont == "y")
			system("cls");
		else {
			cout << "\nThanks for using our program <3\n\n";
			exit(0);
		}
	}

	return 0;
}


// Menu
void menu() {

	cout << setw(50) << setfill('*') << endl;
	cout << "\n*" << setfill(' ') << right << setw(48) << "*\n";
	cout << "*" << setfill(' ') << right << setw(39) << "Welcome to the Bubble Sort Program" << setw(9) << "*\n";
	cout << "*" << setfill(' ') << right << setw(48) << "*\n";
	cout << setw(49) << setfill('*') << "\n";

	cout << "\t1. Pass-by-value method" << endl;
	cout << "\t2. Pass-by-address method" << endl;
	cout << "\t3. Exit program" << endl;

	cout << "\nEnter your choice : ";

}

// Array input
void input(int* myarr, int arrSize) {

	string value;

	cout << "\nEnter " << arrSize << " elements \n";

	for (int i = 0; i < arrSize; i++) {
		cout << "Number " << i + 1 << " : ";
		getline(cin >> ws, value);

		// Check if input is string
		while (isNumber(value) == false) {

			// check if user input negative
			if (value[0] == '-') {
				cout << "Please enter positive number! :p\n";
			}
			else {
				cout << "Please enter a digit! :p\n";
			}

			cout << "Number " << i + 1 << " : ";
			getline(cin >> ws, value);
		}
		myarr[i] = stoi(value);
	}
}

// Validation function
bool isNumber(string s)
{
	// Returns false if string contains character and whitespace
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) == false || isspace(s[i]) == true) {
			return false;
		}
	}
	return true;
}

// bubble sort (pass_by_value)
int pass_by_value(int a, int b) {

	int temp;
	temp = a;
	a = b;
	b = temp;
	return a; // return the smaller value

}

// Sort_order menu
void sort_order() {

	cout << setw(31) << setfill('*') << endl;
	cout << "\n*" << setfill(' ') << right << setw(20) << "Bubble Sort Order" << setw(9) << "*\n";
	cout << setw(30) << setfill('*') << "\n";

	cout << "  1. Ascending order" << endl;
	cout << "  2. Descending order" << endl;
	cout << "\nEnter your choice: ";



}

// bubble sort (pass-by-address)
void pass_by_address(int* ptr, int n) {

	int i, j;

	// looping through the list
	for (i = 0; i < n - 1; i++) {

		// (size-i-1) because we don't have to loop through the last part of the array after each loop since the largest number is already at last
		for (j = 0; j < (n - i - 1); j++) {

			// *(ptr + value) is the same as arr[value], it refers to the index of the array
			if (*(ptr + j) > *(ptr + j + 1)) {

				// swapping value if the current value is larger than adjacent value
				int temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;

			}
		}
	}

}


