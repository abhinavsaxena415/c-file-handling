/** @file	- read_file.c
 *  @brief 	- Example for Reading a file and storing into a string,
 *  		  caller is responsible for freeing allocated memory
 *  		  otherwise this leads to a Memory Leak issue
 *  @author - Abhinav Saxena
 *  @bug 	- No known bugs.
 */

/**
 * @param 	- File name (if file is in same folder) or
 * 			  File path (relative or absolute path to file including file name)
 * @param	- Result (input char pointer where file contents are stored)
 * @return 	- -1 (if Fail to open file or allocate memory)
 * 			   0 (if file read is Success and stored in given input char pointer)
 */
#include <stdio.h>
#include <stdlib.h>

int readFile(const char* filename, char** result)
{
	// local variables
	FILE *file_pointer;
	long file_size;

	// checking input parameter is NULL or not
	if ((filename == NULL) || (result == NULL))
	{
		printf("Input parameter is NULL\n");
		return (-1);
	}

	// open file in read mode, return NULL if fail
	file_pointer = fopen(filename,"r");
	if(!file_pointer)
	{
		printf("File : %s not found\n", filename);
		return(-1);
	}

	// calculating file size to allocate memory
	fseek(file_pointer ,0, SEEK_END);
	file_size = ftell(file_pointer);
	rewind(file_pointer);
	*result = (char *)calloc(1, file_size + 1);

	// return NULL if memory allocation failed
	if (*result == NULL)
	{
        printf("Memory allocation failed\n");
        fclose(file_pointer);
		return (-1);
	}
	
	// reading file content and store string into result
	fread(*result, sizeof(char), file_size, file_pointer);

	// appending NULL at the end of string
	result[file_size] = 0;

	// clearing file pointer after use
	fclose(file_pointer);

	// returning output string
	return (0);
}

/* --- END --- */
