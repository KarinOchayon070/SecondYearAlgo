#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define COL 5
#define ROW 5

/* Practice 1 - Find The Celebrity Problem, Party of N People Explained - 18.10.21:
At a party of n people, we define celebrity/star being the person that everyone Know him but he does not know anyone.
Input: A group of people and interpersonal relationships.
Output: Is there a celebrity in the group? If so, who is it?.*/


int IsCelebrity(int Grap[COL][ROW], int n) {

	int start = 0;    //rows
	int end = n - 1; //cols

	while (start < end) {
		if (Grap[start][end] == 1) { //If Grap[start][end] = 1, we sure that 0th person knows 5th person, so 0th person cannot be the celebrity.
			start++; //move on to the next option to see if the other elements know the 5th person.
		}
		else {
			end--; //if not - can't be a celebrity - moving on to th next option
		}
	}

	for (int i = 0; i < n; i++) {
		if ((i != start) && (Grap[start][i] == 1 || Grap[i][start] == 0)) {//exemple - row 2, col 2 - both 0
			return -1;
		}
	}
	return start;
}

void main() {

	int Graph[ROW][COL] = { {0,0,1,1,0},
							{1,0,1,1,0},
							{0,0,0,0,0},
							{0,1,1,0,1},
							{0,0,1,1,0}
	};

	int res = IsCelebrity(Graph, 5);
	cout << (char)(res + 'A');
}