# File-handling in C
**Repo for file handling API/Example code in C language for differnet file operations.**

## read_file.c
## readFile(input1, input2) Function
This function gives you flexiblity of Reading a file(.txt, .json, .log .... etc) and store it into a memory allocated string. Here, first parameter is **input1** is the file name or file path including file name recomended data type is **const char***, second parameter is **input2** is the char pointer where result will be stored recomended data type is **char***.

**NOTE- Above API/Function is avalable in read_file.c and its implementation is shown in main.c. Caller of this function is responsible for freeing memory and assigning pointer to NULL of "input2", otherwise this may lead to Memory Leak and Dangling pointer issues**
