# 42-c1-get_next_line
## **Function Prototype**
	char  *get_next_line(int file_descriptor);
 
## **Important Notes**
- GNL returns dynamically allocated memory that needs to be freed.
- Read input is buffered in the heap before returned to the calling function. Therefore, the GNL function should be called until it returns **`NULL`** to prevent memory leaks.
- The low-level `read` system call is used in this function. Therefore, SIGINT can cause issues while GNL is waiting for further inputs.

## **Description**
The GNL function uses the low-level `read` system call and attempts to read the **buffer_size** amount of char from the passed fd (file descriptor). Albeit the buffer_size is predetermined in the associated header file, this value can be overwritten during compilation.

In cases where nothing can be read, such as not being permitted to read from the given fd or there is nothing to read, GNL returns `NULL`. if the `read` system call can executed without an error, GNL will return the string until a newline character `\n` (including \n) or the 
entire string if EOF (end of file) is encountered with no `\n` in the buffer.

As the `read` system calls reads an entire `buffer_size` amount of data at once, the buffer may contain 0, 1, or +1 `\n` characters. If there are no `\n` characters but `EOF` is not reached, it will keep reading and create a linked list. In all other cases, 
it will clean up the buffer where anything after the `\n` is saved in a static variable for the next function call and return the requested line.

#### **Notes**
	Written by Muktim in 42London
 	Submitted on 19/05/2024
  	Final Score: 125/100
