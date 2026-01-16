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
```

---

## Resources

### Articles and Tutorials

- [File I/O in C Programming](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) - Overview of system-level file operations
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Understanding static variable lifetime and scope

---

## Algorithm Explanation and Justification

The `get_next_line` implementation uses a **static buffer approach** with dynamic memory management to efficiently read and return lines from a file descriptor.

### Core Algorithm

The algorithm operates on the following principle:
1. **Static Buffer Persistence**: A static variable stores leftover data between function calls, maintaining state across multiple invocations for the same file descriptor.
2. **Buffered Reading**: Data is read from the file descriptor in chunks of `BUFFER_SIZE` bytes to minimize system calls.
3. **Line Extraction**: The buffer is searched for newline characters (`\n`), and complete lines are extracted and returned.
4. **Remainder Management**: Any data after a newline is preserved in the static buffer for the next call.

### Justification

This approach was selected for several key reasons:

**Efficiency**: Reading in fixed-size chunks (controlled by `BUFFER_SIZE`) reduces the number of expensive `read()` system calls compared to reading byte-by-byte. This is crucial for performance, especially with large files.

**Memory Management**: The implementation dynamically manages the static buffer, freeing it when EOF is reached while preserving remainder data between calls. This balances efficiency (no repeated allocations for the same data) with proper cleanup (no memory leaks when done reading).

**Simplicity**: The algorithm maintains a clear separation of concerns: reading data, finding line boundaries, and managing leftovers. This makes the code easier to understand, debug, and maintain.

**Flexibility**: The `BUFFER_SIZE` can be adjusted at compile time to optimize for different use cases (small vs. large files, memory constraints, etc.).

**Correctness**: The approach naturally handles edge cases such as:
- Files without trailing newlines
- Empty lines
- Multiple consecutive newlines
- End-of-file conditions
- Invalid file descriptors (proper cleanup with freed stash)
