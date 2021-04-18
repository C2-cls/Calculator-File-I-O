/* This is a program to calculate a simple number
and write the result to a text file*/

#include <stdio.h>

int main(void)
{
	char operator;					//Initialize all variable to be used
	int num1, num2, result = 0;		//Initialize result with a starting value of zero

	FILE* outFile;					// Initialize the pointer for the file to be written

	/* The calculator will first perform a simple calculation
	and the file I/O will receive the Result variable*/

	printf("Enter number 1: ");
	scanf_s("%i", &num1);

	printf("\nEnter an operator (+ or -) : ");
	scanf_s(" %c", &operator,3);	//scanf depreciated, used scanf_s; included buffer amount '3'

	printf("\nEnter number 2: ");
	scanf_s("%i", &num2);

	switch (operator)				// Use switch function to evaluate operator characters
	{
	case '+':
		result = num1 + num2;
		break;						// Add break; statements to all switch cases
	case '-':
		result = num1 - num2;
		break;
	default:						// default case will prevent division operation. Add division by zero protection in next generation.
		printf("Invalid input");
		break;
	}
	// A function to write the Result variable to a text file
	fopen_s(&outFile, "results_output.txt", "w");
	if (outFile == NULL)			// Check if there is a filename specified
	{
		printf("***data was not exported, file not opened***");
		return(1);
	}

	fprintf(outFile, "\nResult: %i\n", result);		// Result Variable is written to the text file w/ pointer outFile

	fclose(outFile);								// File cleanup and closed
	return 0;
}