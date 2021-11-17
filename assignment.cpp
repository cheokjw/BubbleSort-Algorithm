#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>


/*
TODO: 1) For pass-by-value, we need to pass in the values in array one by one instead of passing the whole array
	  2) Add input validation (check if the input isdigit())
	  3) Change the menu (make it looks nicer)
	  4) Pass-by-address correct buy find a way to assign pointer
*/


using namespace std;


// initializing functions
void pass_by_value();
void pass_by_address(int* ptr, int n);
void test(int* ptr);


int main()
{
	// Initializing variables
	int choice, i, arr[10], size;



	// Allow user to keep using the program until they close it manually
	while (true) {


		cout << setw(50) << setfill('*') << endl;
		cout << "\n*" << setfill(' ') << right << setw(48) << "*\n";
		cout << "*" << setfill(' ') << right << setw(39) << "Welcome to the Bubble Sort Program" << setw(9) << "*\n";
		cout << "*" << setfill(' ') << right << setw(48) << "*\n";
		cout << setw(49) << setfill('*') << "\n";

		cout << "\t1. Pass-by-value method" << endl;
		cout << "\t2. Pass-by-address method" << endl;
		cout << "\t3. Exit program" << endl;

		cout << "\nEnter your choice : ";

		cin >> choice;


		// Input validation
		while (choice != 1 && choice != 2 && choice != 3) {
			cout << endl;
			cout << "\nInvalid Input! Please try again";
			cout << "\n\t1. Pass-by-value method" << endl;
			cout << "\t2. Pass-by-address method" << endl;
			cout << "\t3. Exit program" << endl;

			cout << "\nEnter your choice : ";

			cin >> choice;

		}

		// Pass-by-value
		if (choice == 1) {

			pass_by_value();


		}

		// Pass-by-address
		else if (choice == 2) {

			// Input values and store in array
			cout << "enter total number of elements: ";
			cin >> size;
			cout << "\n enter " << size << " elements \n";

			for (i = 0; i <= size - 1; i++) {
				cout << "number " << i + 1 << " : ";
				cin >> arr[i];
			}

			// For testing addresses purpose
			test(arr);

			// Function call
			pass_by_address(arr, size);

			for (i = 0; i < size; i++) {
				cout << arr[i] << " ";

			}


		}
		// Quits Program
		else if (choice == 3) {
			cout << "\nThanks for using our program <3\n\n";
			exit(0);
		}
	}


	return 0;
}


// bubble sort (pass_by_value)
void pass_by_value() {

	int num, size;



}




// bubble sort (pass-by-address)
void pass_by_address(int *ptr, int n) {


	int i, j;

	cout << "\nsorting array using bubble sort....\n";


	// looping through the list
	for (i = 0; i < n; i++) {

		// (size-i-1) because we don't have to loop through the last part of the array after each loop since the largest number is already at last
		for (j = 0; j < (n - i - 1); j++) {

			// *(ptr + value) is the same as arr[value], it refers to the index of the array
			if (*(ptr +j) > *(ptr + j + 1)) {

				// swapping value if the current value is larger than adjacent value
				int temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;

			}
		}
	}

}




// Testing purposes
void test(int *ptr) {
	cout << *(ptr + 3);
}