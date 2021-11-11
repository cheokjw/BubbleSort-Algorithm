// assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


void Pass_by_value(int arr[], int size) {


	int i, j;

	cout << "\nSorting Array Using Bubble Sort....\n";


	// Looping through the list
	for (i = 0; i < size; i++) {

		// (size-i-1) because we don't have to loop through the last part of the array after each loop since the largest number is already at last
		for (j = 0; j < (size - i - 1); j++) {

			if (arr[j] > arr[j + 1]) {

				// Swapping value if the current value is larger than adjacent value
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;


			}
		}
	}
}



int main()
{

	int num, arr[10], i, sorted_arr;

	cout << "Enter Total Number of Elements: ";
	cin >> num;
	cout << "\n Enter " << num << " Elements : \n";

	// Letting the user to input all of the values into an array
	for (i = 0; i < num; i++) {
		cout << "number " << i + 1 << " : ";
		cin >> arr[i];
	}

	Pass_by_value(arr, num);

	
	for (i = 0; i < num; i++) {
		cout << arr[i] << " ";

	}


	return 0;
}

