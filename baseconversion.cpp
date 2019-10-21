// CPP code to find nth number 
// with digits 0, 1, 2, 3, 4, 5 
#include <bits/stdc++.h> 
using namespace std; 

#define max 100000 

// function to convert num to base 6 
int baseconversion(int arr[], int num, int base) 

{ 
	int i = 0, rem, j; 

	if (num == 0) { 
		return 0; 
	} 

	while (num > 0) { 
		rem = num % base; 

		arr[i++] = rem; 

		num /= base; 
	} 

	return i; 
} 

// Driver code 
int main() 
{ 

	// initialize an array to 0 
	int arr[max] = { 0 }; 

	int n = 10; 

	// function calling to convert 
	// number n to base 6 
	int size = baseconversion(arr, n - 1, 6); 

	// if size is zero then return zero 
	if (size == 0) 

		cout << size; 

	for (int i = size - 1; i >= 0; i--) { 

		cout << arr[i]; 
	} 

	return 0; 
} 

// Code is contributed by Anivesh Tiwari. 
