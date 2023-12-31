/*
 *  freezer.c
 *  Unit 4 Exercise 5: Estimate temperature in a freezer
 *  given the elapsed time since power failure.
 *  Formula: T = (4*t^2 / (t+2)) - 20
 */
#include <stdio.h>

int main(void)
{
	int hours, minutes;
	float temperature; // Temperature in freezer

	// Get the hours and minutes
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	printf("Hours: %d\n", hours);
	printf("Minutes: %d\n", minutes);
	return 0;
}
