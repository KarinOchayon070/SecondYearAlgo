#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;


/* Practice 2 - 25.10.21 - Given a text text[0..n-1] and a pattern pat[0..m-1], write a func search(char pat[], char text[])
that prints all occurrences of pat[] in text[].*/


void PrintArr(int arr[], int n) {   //print the array

	int i = 0;
	for (i = 0; i < n; i++) {
		cout << " " << arr[i];
	}
	cout << "\n";
}

int* RishaFunction(char* ptrn) {

	int n = strlen(ptrn);
	int i = 1, j = 0;        // i is Sifa, j is  Risha.
	int* ips = new int[n];  //init the new array.
	ips[0] = 0;            //finger rule - first element is always zero.


	while (i < n) {

		if (ptrn[i] == ptrn[j]) {
			ips[i] = j + 1;
			i++;
			j++;
		}

		if (ptrn[i] != ptrn[j]) {
			if (j == 0) {
				ips[i] = 0;
				i++;
			}
			else {
				j = ips[j - 1];
			}
		}
	}
	return ips;
}


void KMPFunc(char* ptrn, char* text) {

	int M = strlen(ptrn);  //"aba".
	int N = strlen(text); //"aabaabaaa".

	int* ips = new int[M];      //init pai array.
	ips = RishaFunction(ptrn); //using RishaFunction.


	int i = 0, j = 0, counter = 0;

	while (i < N) {

		if (ptrn[j] == text[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout << "Hi! Found pattern at index " << i - j << ".\n";
			counter++;
			j = ips[j - 1];
		}

		else if (i < N && ptrn[j] != text[i]) {
			if (j != 0) {
				j = ips[j - 1];
			}
			else {
				i = i + 1;
			}
		}
	}
	cout << "Total occurrences: " << counter << ".\n";
}


int main() {

	char text[] = "aabaabaaa";
	char ptrn[] = "aba";
	int* arr = RishaFunction(ptrn); //check RishaFunction.
	cout << "Check Risha Function: ";
	PrintArr(arr, strlen(ptrn));   //print RishaFunction.
	KMPFunc(ptrn, text);          //print KMPFunc.
}
