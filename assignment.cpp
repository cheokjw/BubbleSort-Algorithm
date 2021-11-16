#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


// initializing functions
void pass_by_value(int val[], int N);




int main()
{

	// initializing valriables
	int choice, num, arr[99], i, sorted_arr;


	// Ask user to choose Pass-by-value or Pass-by Reference
	cout << "Welcome to our Bubble Sort Program :)";
	cout << "\nPlease choose\n1. Pass-By-Value\n2. Pass-by-Address\nChoice : ";
	cin >> choice;


	// input
	cout << "enter total number of elements: ";
	cin >> num;
	cout << "\n enter " << num << " elements \n";


	// letting the user to input all of the values into an array
	for (i = 0; i < num; i++) {
		cout << "number " << i + 1 << " : ";
		cin >> arr[i];
	}


	// Before Sorting
	for (i = 0; i < num; i++) {
		cout << arr[i] << " ";

	}

	cout << "\n\n========================\n";


	// Conditional statement for user's choose
	if (choice == 1) {
		pass_by_value(arr, num);
	}
	//else if (choice == 2) {
	//	pass_by_address(&arr, &num);

	//}


	// Output value after sort
	for (i = 0; i < num; i++) {
		cout << arr[i] << " ";

	}


	return 0;
}







// bubble sort (pass-by-value function)
void pass_by_value(int arr[], int size)
{


	int i, j;

	cout << "\nsorting array using bubble sort....\n";


	// looping through the list
	for (i = 0; i < size; i++) {

		// (size-i-1) because we don't have to loop through the last part of the array after each loop since the largest number is already at last
		for (j = 0; j < (size - i - 1); j++) {

			if (arr[j] > arr[j + 1]) {

				// swapping value if the current value is larger than adjacent value
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;



			}
		}
	}
}



// bubble sort (pass-by-address)
void pass_by_address(int* arr[], int* size) {


	int i, j;

	cout << "\nsorting array using bubble sort....\n";


	// looping through the list
	for (i = 0; i < *size; i++) {

		// (size-i-1) because we don't have to loop through the last part of the array after each loop since the largest number is already at last
		for (j = 0; j < (*size - i - 1); j++) {

			if (*arr[j] > *arr[j + 1]) {

				// swapping value if the current value is larger than adjacent value
				int temp = *arr[j];
				*arr[j] = *arr[j + 1];
				*arr[j + 1] = temp;



			}
		}
	}

}





