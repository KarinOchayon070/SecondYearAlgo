#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Practice 1 - 18.10.21 -  Given an array of size n of a few ones and zeros,
so that t is first ones members and the others are zeros.
Write an algorithm that finds t.*/

//O(n)
int FindTOn(int arr[], int n) {

	int i, t = 0;

	for (i = 0; i < n; i++) {
		if (arr[i] == 1) {
			continue;
		}
		else {
			t = i;
			return t;
		}
	}
	return n;
}

//O(logn)
int binarySearchLogn(int arr[], int n) {

	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {

		int mid = (low + high) / 2;

		if (arr[mid] == 0 && arr[mid - 1] == 1) {// If the element is present at the middle itself.
			return mid;
		}

		if (arr[mid] == 1 && arr[mid + 1] == 0) {//if the element is 1 and after 0.
			return mid + 1;
		}

		else if (arr[mid] == 0) { //if 0 - go left (the ones at the begining)
			high = mid - 1;
		}

		else if (arr[mid == 1]) {//if 1 - go right (the zeros after the ones)
			low = mid + 1;
		}
	}
	return low;
}

//O(logt)
int binarySearchLogt(int arr[], int n) { //return number of ones in a[0]=a[1]=...a[t-1]=1,a[t]=a[t+1]=...=a[n-1]=0

	int low = 0, high, mid;

	if (arr[low] == 0) {
		return 0;
	}
	if (arr[++low] == 0) {
		return 1;
	}
	while ((2 * low < n) && arr[2 * low]) {
		low *= 2;
	}
	if (2 * low < n) {
		high = 2 * low - 1;
	}
	else {
		high = n - 1;
	}
	return binarySearchLogn(arr, n); //the function returns index of the right 1
}

int main() {

	//int arr[6] = {0,0,0,0,0,0};
	//int ans = FindTOn(arr, 6);
	//cout << ans;

	//int arr[6] = {0,0,0,0,0,0};
	//int ans = binarySearchLogn(arr, 6);
	//cout << ans;

	//int arr[6] = {0,0,0,0,0,0};
	//int ans = binarySearchLogt(arr, 6);
	//cout << ans;
}