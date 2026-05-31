# CS50x 2026 - Week 1: C

## Overview
This directory contains my solutions and coursework for Week 1 of Harvard's CS50x. The focus of this week is transitioning from graphical programming (Scratch) into text-based programming using the **C programming language**. 

Key concepts explored in this module include:
*   Memory and data types (int, float, char, string)
*   Boolean expressions and conditional statements
*   Loops (`for`, `while`, `do-while`)
*   Command-line compilation and execution
*   Under-the-hood compilation steps (preprocessing, compiling, assembling, linking)

## Problem Sets
This repository includes the source code for the following assignments:

*   **[Hello]**: A foundational program that utilizes standard I/O to prompt a user for their name and print a personalized greeting.
*   **[Mario]**: A structural logic problem that rebuilds the block pyramids from Super Mario Brothers using nested loops and precise console formatting. *(Includes both the 'Less Comfortable' and 'More Comfortable' variations).*
*   **[Cash / Credit]**: 
    *   *Cash*: Implements a greedy algorithm to calculate the minimum number of coins required to make change.
    *   *Credit*: A mathematical logic challenge implementing Luhn's Algorithm to determine the validity and vendor (Visa, Mastercard, Amex) of a credit card number entirely through integer arithmetic.

## Compilation & Execution
These programs are written in standard C and utilize the `<cs50.h>` header file for string and I/O management.

To compile a program in a native Linux environment:
```bash
# Using the CS50 make utility
make hello

# Or using the GNU C Compiler directly (linking the CS50 library)
gcc hello.c -o hello -lcs50