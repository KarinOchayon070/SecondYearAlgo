#include <iostream>
using namespace std;

/* Practice 1 - 18.10.21:
Finding the minimum and maximum -  (⌊3n/2⌋ - 2) Comparisons.*/


void FindMaxAndMin(int arr[], int n) {

	int Min, Max, MinLocal, MaxLocal, i = 0;

	if (arr[0] < arr[1]) {
		Min = arr[0];
		Max = arr[1];
	}
	else {
		Min = arr[1];
		Max = arr[0];
	}

	for (i = 2; i < n - 2; i++) {
		if (arr[i] < arr[i + 1]) {
			MinLocal = arr[i];
			MaxLocal = arr[i + 1];
		}
		else {
			MinLocal = arr[i + 1];
			MaxLocal = arr[i];
		}
		if (MinLocal < Min) {
			Min = MinLocal;
		}
		if (MaxLocal > Max) {
			Max = MaxLocal;
		}
	}
	cout << "Min: " << Min << ", ";
	cout << "Max: " << Max << ".";
}


int main() {
	int arr[10] = { 77,-1,9,1,0,7,5,3,2,6 };
	FindMaxAndMin(arr, 10);
}