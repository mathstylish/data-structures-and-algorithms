[![pt-br](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/mathstylish/data-structures-and-algorithms/blob/main/README.pt-br.md)
# Data Structures and Algorithms

The goal of this repository is to serve as a study reference, providing implementations of the data structures and algorithms that you typically learn in this discipline. The programming language I will use is C, for at least two reasons which **I** think didactically interesting:

- **Simplicity and Clarity**: The syntax of the C language is relatively simple, making it easier to understand. Just by reading the code, you can get an idea of what's being done, allowing you to focus more on the concepts of the discipline rather than the details of the language itself.

- **Memory Management**: The C language requires programmers to explicitly manage memory using functions like `malloc()` and `free()`. This allows you to understand how memory is **allocated** and **released** for different data structures.

**Note**: While the C language has its advantages for learning data structures and algorithms, it's important to note that you can learn these concepts in any programming language. What will change is only the language and how the operations are carried out in it.

## Repository Structure
 - Source code, e.g., `LinkedList/`
 - In the source code directories, there's a `.h` file and a `.c` file, e.g., `LinkedList/Singly/singly.h` and `LinkedList/Singly/singly.c`. `.h` is a header file containing macros, structures, and function declarations that we'll implement in the `.c` file.

## How to Run the Examples?
Firstly, you need the following dependencies: `gcc`, `make`. I explain how to install these tools in the [challenge](#challenge) that I proposed. There, you'll find examples of how to install them.

Then compile the source code with `gcc -o LinkedList/Singly/test LinkedList/Singly/singly.c LinkedList/Singly/main.c` and execute with `./LinkedList/Singly/test`. The -o flag indicates where the executable output of the compilation will be generated, `test` is the name of the executable file. Name it whatever you want.
