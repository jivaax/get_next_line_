*This project has been created as part of the 42 curriculum by <jwira>.*

# get_next_line

## Description

**get_next_line** is a C project developed as part of the 42 curriculum.  
The goal of this project is to implement a function that reads a file descriptor line by line, returning one line at a time with each call.

The function must handle buffered input efficiently, manage memory correctly, and work with different file descriptors. It should also correctly handle end-of-file situations and files with or without newline characters.

This project is a fundamental exercise in understanding low-level file I/O, static variables, memory management, and string manipulation in C.

---

## Instructions

### Compilation

Compile the project together with your main file and required utility functions:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
