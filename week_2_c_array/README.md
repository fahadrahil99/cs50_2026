# CS50x 2026 - Week 2: Arrays

## Overview
This directory contains my solutions for Week 2 of Harvard's CS50x. The primary focus of this week is understanding data structures under the hood—specifically, how memory is organized sequentially to form **Arrays** and **Strings** (which are simply arrays of characters).

Key concepts explored in this module include:
* Memory layout and indexing
* String manipulation and the `<string.h>` library
* Command-line arguments (`argc`, `argv`)
* Typecasting and ASCII math
* Cryptography fundamentals

## Problem Sets
This repository includes the source code for the following assignments:

* **[Scrabble]**: A program that determines the winner of a short Scrabble-like game. It maps characters to an array of point values using ASCII math to compute the score for two competing words.
* **[Readability]**: A program that computes the approximate grade level needed to comprehend a block of text. It uses the Coleman-Liau index formula by parsing the string to count the number of letters, words, and sentences.
* **[Substitution]**: A cryptographic program that implements a substitution cipher. It accepts a 26-character alphanumeric key as a command-line argument, validates the key for duplicates and correct formatting, and encrypts a user-provided plaintext message while preserving the original case.

## Compilation & Execution
These programs are written in standard C and utilize the `<cs50.h>` library.

To compile a program in a native Linux environment:
```bash
# Using the CS50 make utility
make scrabble
make readability
make substitution
./scrabble
./readability
./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ