/**
 * @author - Abhinav Saxena
**/

// Include Header files
#include <stdio.h>
#include <stdlib.h>

// Global Variables
const char* fileName = "test.txt";

// Declaration of functions
int readFile(const char* filename, char** result);

int main (void)
{
	// local variable a char pointer used to store file contents as string
	char* output_str;

	// function call to read file and store content in output_str
	readFile(fileName, &output_str);

	printf("File contents -:\n%s\n",output_str);

	// Free allocated memory after use and assign pointer to NULL
	if (output_str != NULL)
	{
		free(output_str);
		output_str = NULL;
	}

	return (0);
}
