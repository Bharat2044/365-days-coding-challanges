// Question Link: https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/save-patients/

/*
Save Patients
  
Problem:
A new deadly virus has infected large population of a planet. A brilliant scientist has discovered a new strain of virus which can cure this disease. Vaccine produced from this virus has various strength depending on midichlorians count. A person is cured only if midichlorians count in vaccine batch is more than midichlorians count of person. A doctor receives a new set of report which contains midichlorians count of each infected patient, Practo stores all vaccine doctor has and their midichlorians count. You need to determine if doctor can save all patients with the vaccines he has. The number of vaccines and patients are equal.

Input Format:
First line contains the number of vaccines - N. Second line contains N integers, which are strength of vaccines. Third line contains N integers, which are midichlorians count of patients.

Output Format:
Print a single line containing 'Yes' or 'No'.

Input Constraint:
1 < N < 10

Strength of vaccines and midichlorians count of patients fit in integer.
Problem Setter: Practo Tech Team

Sample Input:
5
123 146 454 542 456
100 328 248 689 200
Sample Output:
No

Time Limit: 1
Memory Limit: 256
Source Limit:
*/



#include <iostream>
#include <algorithm>
using namespace std;

bool savePatients(int arr[], int brr[], int n) {
	for(int i=0; i<n; i++) {
		if(arr[i] < brr[i])
			return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;   
	
	int arr[n], brr[n];

	for(int i=0; i<n; i++) 
		cin >> arr[i];

	for(int i=0; i<n; i++) 
		cin >> brr[i];

	(savePatients(arr, brr, n)) ? cout << "Yes" : cout << "No"; 

	return 0;
}







