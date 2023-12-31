// CS1010 AY2015/6 Semester 2 PE2 Ex2
//
// nato.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#define MAXLEN 101

int decrypt(char []);

int main(void) {
	char name[MAXLEN];

    printf("Enter name in NATO alphabet: ");

	printf("Decrypted name: \n"); // Incomplete
	
	printf("The given name cannot be decrypted.\n");

	return 0;
}

int decrypt(char name[]){
	// Do not change this 2D array
	// alphabet[0] -> code word for 'A'
	// alphabet[1] -> code word for 'B'
	// ...
	char alphabet[26][MAXLEN] = {
		"ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO",
		"FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT",
		"KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR",
		"PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO",
		"UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE",
		"ZULU"};
			
	return 0;
}

// Hint 1: For an encryted name starting with a particular 
// character (e.g., 'C'), which row of alphabet shows the 
// expected code word?

// Hint 2: It is advisable to create a new array for storing
// the (partially) decrypted name and only copy the decryted 
// name back to name[] in the end.

// Hint 3: String functions may be useful but they are not 
// critical for solving this problem. If you know arrays well,
// you will be able to come up with a good solution.

// Hint 4: Think carefully before starting to code. If you have 
// a good solution, you may only need to add ~20 lines of code to 
// decrypt().