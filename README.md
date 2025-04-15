# 42-Get-next-line

This project is part of the 42 School curriculum and focuses on implementing a function that reads a file line by line. The goal is to understand file I/O operations, dynamic memory allocation, and buffer management in C.

## 📚 Project Overview

The `get_next_line` function reads a line from a file descriptor, returning it each time it's called. It handles files of any size and supports multiple file descriptors simultaneously.

## 🛠️ Features

- Reads from any file descriptor, including files and standard input.
- Manages memory efficiently to prevent leaks.
- Handles lines of arbitrary length.
- Supports multiple file descriptors without interference.

## 📁 Project Structure

42-Get-next-line/ <br>
├── get_next_line.c         # Core function implementation <br>
├── get_next_line.h         # Header file with function prototypes <br>
├── get_next_line_utils.c   # Helper functions <br>
├── Makefile                # Build script <br>
└── README.md               # Project documentation <br>

## 🚀 Getting Started

### 📋 Prerequisites

- GCC compiler
- Make utility

---

## 🛠️ Installation

1. **Clone the repository:** <br>
   git clone https://github.com/asparts/42-Get-next-line.git <br>
   cd 42-Get-next-line <br>

2. **Compile the project:​** <br>
make  <br>
This will generate the necessary object files. <br>

## Usage
Include the get_next_line.h header in your C program and compile it with the get_next_line.c and get_next_line_utils.c files.

Example: <br>
```
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
Compile with: <br>
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl <br>
## 🔍 Notes
The BUFFER_SIZE macro defines how many bytes are read at a time. It can be set during compilation: <br>
gcc -D BUFFER_SIZE=42 ... <br>
Ensure to free the memory allocated by get_next_line to prevent memory leaks. <br>

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
