#include<iostream>
using namespace std;

/* Lesson 1 - 17/10/2021:
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊n/2⌋ times. */


//1 - Using two for loops - Time Complexity : O(n2).
int majorityProblemTwoLoops(int arr[], int n) {

    //Using two for-loops, count the number of appearance for each element.Once the counter exceeds the ⌊n / 2⌋, then we return the element.
    int i = 0, maxCount = 0, index = -1;
    for (i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        // update maxCount if count of current element is greater
        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }
    // if maxCount is greater than ⌊n / 2⌋ return the corresponding element
    if (maxCount > n / 2) {
        cout << arr[index] << endl;
    }
    else {
        cout << "No Majority Element" << endl;
        return 0;
    }
    return 1;
}

//2 - Using Moore’s Voting Algorithm - Time Complexity : O(n).
int majorityProblemMooresVotingAlgo(int arr[], int n) {

    int i = 0, cand = -1, count = 0, sum = 0;
    for (i = 0; i < n; i++) {

        if (count == 0) {
            cand = arr[i];
            count++;
        }
        else {
            if (arr[i] == cand) {
                count++;
            }
            else {
                count--;
            }
        }
    }

    count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == cand) {
            count++;
        }
    }

    if (count > n / 2) {
        cout << cand;
        return cand;
    }
    else {
        cout << "No";
        return 0;
    }
}


int main()
{
    int arr[7] = { 2,2,1,1,3,2,2 };
    int n = 7;
    //int ansForLoops = majorityProblemTwoLoops(arr, 7);
    int ansMores = majorityProblemMooresVotingAlgo(arr, 7);
}